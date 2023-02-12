#include <iostream>

int sqr(int x) {
    return x * x;
}

double sqr(int x) {
    return x * x;
}

double sqr(double x) {
    return x * x;
}

int main() {
    auto integer = 5;
    auto floating = 4.2;

    std::cout << sqr(integer) / 2 << std::endl;
    std::cout << sqr(floating) / 2 << std::endl;
}
