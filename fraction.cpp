#include <iostream>

struct Fraction {
    int numerator;
    unsigned denominator;
};

void print_fraction(Fraction fraction) {
    std::cout << fraction.numerator << " / "
              << fraction.denominator << std::endl;
}

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


int main() {
    Fraction first, second;

    std::cin >> first >> second;

    std::cout << second << std::endl;
    std::cout << 3 + first + 1 << std::endl;

}
