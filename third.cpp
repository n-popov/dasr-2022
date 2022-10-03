#include <iostream>

int main() {
    int amount;
    int ones = 0, fives = 0, sevens = 0, tens = 0;
    std::cin >> amount;
    tens = amount / 10 - 1;
    tens = ((tens < 0) ? 0 : tens);
    amount -= tens * 10;
    switch(amount) {
        case 19:
            sevens += 2;
            fives += 1;
            break;
        case 14:
            sevens += 2;
            break;
        case 13:
            sevens += 1;
            fives += 1;
            ones += 1;
            break;
        case 12:
            sevens += 1;
            fives += 1;
            break;
        default:
            tens += amount / 10;
            amount %= 10;
            sevens += amount / 7;
            amount %= 7;
            fives += amount / 5;
            amount %= 5;
            ones += amount;
            break;
    }
    auto print_coins = [](int number, int value){
        for(auto i = 0; i < number; i++) {
            std::cout << value << ' ';
        }
    };
    print_coins(ones, 1);
    print_coins(fives, 5);
    print_coins(sevens, 7);
    print_coins(tens, 10);

}
