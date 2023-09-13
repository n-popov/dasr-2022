#include <vector>
#include <map>
#include <iostream>
#include <numeric>

class ATM
{
public:
    // Конструктор, создаёт пустой банкомат
    ATM() = default;

    // Деструктор, если нужен

    // Вносит в устройство набор купюр
    // - в векторе notes перечислены достоинства вносимых купюр (разумеется, возможны повторы)
    // - в поле currency указан код валюты
    void deposit(const std::vector<unsigned int>& notes, unsigned short int currency) {
	auto& notes_for_currency = data[currency];
	for (auto note: notes) {
		notes_for_currency[note]++;
	}
    }

    // Снять сумму amount в валюте currency, выдав её максимально крупными купюрами
    // - если операция прошла успешно, учесть выданные купюры в банкомате и вернуть их в возвращаемом vector-е
    // - если целиком запрошенную сумму выдать невозможно, не выдавать ничего и вернуть пустой vector
    std::vector<unsigned int> withdraw_large(unsigned int amount, unsigned short int currency) {
	    std::vector<unsigned> output;
	    auto available_for_currency = data[currency];
	    for (auto it = available_for_currency.rbegin(); it != available_for_currency.rend(); it++) {
		    auto nominal = it->first;
		    auto& available = it->second;
		    for(;amount >= nominal && available > 0;) {
			    	output.push_back(nominal);
			    	available--;
			    	amount -= nominal;
		    }
	    }
	    if (amount == 0) {
		    data[currency] = available_for_currency;
		    return output;
	    }
	    return std::vector<unsigned>{};
    }

    // Снять сумму amount в валюте currency, выдав её максимально мелкими купюрами
    // - если операция прошла успешно, учесть выданные купюры в банкомате и вернуть их в возвращаемом vector-е
    // - если целиком запрошенную сумму выдать невозможно, не выдавать ничего и вернуть пустой vector
    std::vector<unsigned int> withdraw_small(unsigned int amount, unsigned short int currency) {
	    std::vector<unsigned> output;
	    auto available_for_currency = data[currency];
	    for (auto it = available_for_currency.begin(); it != available_for_currency.end(); it++) {
		    auto nominal = it->first;
		    auto& available = it->second;
		    for(;amount >= nominal && available > 0;) {
			    	output.push_back(nominal);
			    	available--;
			    	amount -= nominal;
		    }
	    }
	    if (amount == 0) {
		    data[currency] = available_for_currency;
		    return output;
	    }
	    return std::vector<unsigned>{};
    }
    // Вернуть максимальную сумму, доступную в валюте currency
    unsigned int check_reserve(unsigned short int currency) {
	    auto& available = data[currency];
	    return std::accumulate(std::begin(available), std::end(available), 0u,
			    [](auto lhs, auto rhs){
			    	return lhs + rhs.first * rhs.second;
			    });
    }

private:
    std::map<unsigned short, std::map<unsigned, unsigned>> data;
};

using namespace std;

const unsigned short int RUB = 0;
const unsigned short int USD = 1;
const unsigned short int NCC = 2;

int main()
{
    vector<unsigned int> rubles = {50, 100, 100, 500, 50, 1000, 100, 100, 1000, 5000};
    vector<unsigned int> dollars = {100, 100, 100};
    vector<unsigned int> nuka_cola_caps = {1, 1, 1, 1, 1};

    ATM atm;
    atm.deposit(rubles, RUB);
    atm.deposit(dollars, USD);
    atm.deposit(nuka_cola_caps, NCC);

    cout << "Reserves: " << endl;
    for(unsigned short int code = 0; code <= 2; code++) {
        cout << "Currency " << code << ": " << atm.check_reserve(code) << endl;
    }

    vector<unsigned int> result;
    result = atm.withdraw_large(1000, RUB);
    cout << "Asked withdraw_large for 1000 RUB, got " << result.size() << " banknotes" << endl;

    result = atm.withdraw_small(1000, RUB);
    cout << "Asked withdraw_small for 1000 RUB, got " << result.size() << " banknotes" << endl;

    result = atm.withdraw_small(1000, USD);
    cout << "Asked withdraw_small for 1000 USD, got " << result.size() << " banknotes" << endl;

    result = atm.withdraw_large(3, NCC);
    cout << "Asked withdraw_large for 3 NCC, got " << result.size() << " banknotes" << endl;

    cout << "Reserves: " << endl;
    for(unsigned short int code = 0; code <= 2; code++) {
        cout << "Currency " << code << ": " << atm.check_reserve(code) << endl;
    }

    return 0;
}
