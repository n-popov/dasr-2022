#include <iostream>
#include <thread>

using namespace std;

class Rational {
public:
    // Конструктор дроби, здесь a - числитель, b - знаменатель
    Rational(int a, int b) {
    	if (b == 0) {
		throw std::invalid_argument("Denominator is zero");
	}
	this->a = a;
	this->b = b;
    }

    
    // Реализуйте операторы:
    // - сложения двух дробей
    auto operator+(Rational other) {
    	return Rational(a * other.b + b * other.a, b * other.b);
    }

    // - вычитания двух дробей

    Rational operator-(Rational other) {
	return {a * other.b - b * other.a, b * other.b};
    }
    // - умножения двух дробей
    //
    auto operator*(Rational other) {
	return Rational(a * other.a, b * other.b);
    }	
    // - деления двух дробей
    //
    auto operator/(Rational other) {
	    return Rational(a * other.b, b * other.a);
    }
    // - умножения дроби на целое число (должно работать при любом порядке операндов)
    auto operator*(int number) {
	    return Rational(a * number, b);
    }

    friend std::ostream& operator<<(std::ostream&, Rational);

private:
    int a, b;
};

auto operator*(int number, Rational rational) {
	return rational * number;
}

std::ostream& operator<<(std::ostream& os, Rational r){
	return os << r.a << '/' << r.b;
}

int main()
{
    Rational a(1, 2);
    Rational b(2, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;
 	
    //std::thread t([](Rational a, Rational b){for (;;) a = a + b;}, a, b);

    try {
        Rational impossible(42, 0);
    } catch(std::invalid_argument& ex) {
	    std::cout << "Caught invalid argument" << std::endl;
	    std::cout << ex.what() << std::endl;
    } catch(std::exception& ex) {
	    std::cout << "Caught base exception" << std::endl;
    } catch(...) {
	    std::cout << "Caught something" << std::endl;
    }

    return 0;
}
