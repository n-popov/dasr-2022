#include <iostream>

namespace numeric {
    int gcd(int a, int b) {
        if (b > a) std::swap(a, b);
        return (b == 0) ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
}


class Fraction {
    int numerator;
    unsigned denominator;

    Fraction simplify() {
        auto gcd = numeric::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= (unsigned)gcd;
        return *this;
    }

public:
    Fraction(int numerator, unsigned denominator) {
        if (denominator == 0) denominator = 1;
        this->numerator = numerator;
        this->denominator = denominator;
        simplify();
    }

    Fraction(int number) {
        numerator = number;
        denominator = 1u;
    }

    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction operator+(Fraction other) {
        return Fraction{numerator * (int)(other.denominator) +
                    other.numerator * (int)(denominator) ,
                    denominator * other.denominator};
    }

    Fraction operator+=(Fraction other) {
        numerator = numerator * (int)(other.denominator) +
                    other.numerator * (int)(denominator);
        denominator *= other.denominator;
        return simplify();
    }

    void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

/*
Fraction operator+(Fraction left, Fraction right) {
    return Fraction{left.numerator * (int)(right.denominator) +
                    right.numerator * (int)(left.denominator) ,
                    left.denominator * right.denominator};
}

Fraction operator+(Fraction left, int right) {
    return Fraction{left.numerator + right * (int)(left.denominator),
                    left.denominator};
}

Fraction operator+(int left, Fraction right) {
    return right + left;
}

Fraction operator-(Fraction left, Fraction right) {
    return Fraction{left.numerator * int(right.denominator) -
                    right.numerator * int(left.denominator),
                    left.denominator * right.denominator};
}

Fraction operator*(Fraction left, Fraction right) {
    return Fraction{left.numerator * right.numerator,
                    left.denominator * right.denominator};
}


Fraction operator/(Fraction left, Fraction right) {
    return Fraction{left.numerator * int(right.denominator),
                    unsigned(int(left.denominator) * right.numerator)};
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char trash;
    in >> fraction.numerator >> trash >> fraction.denominator;
    return in;
}

std::ostream& operator<<(std::ostream& out, Fraction fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}
*/

int main() {

    Fraction fraction_0 = Fraction(1, 2);
    Fraction fraction_1(1, 2);
    Fraction fraction_2{1, 2};
    Fraction fraction_3 = {1, 2};
    // Fraction fraction_4 = (1, 2); impossible

    Fraction left = {2, 3};
    Fraction right = {2, 6};
    right.print();
    right += left;
    right.print();


    std::cout << numeric::gcd(36, 84) << std::endl;


    return 0;

}
