#include <iostream>
#include <vector>

template <typename T>
using matrix = std::vector<std::vector<T>>;

template <typename T>
const T PI = 3.14152926535897;

template <typename T> T cube(T value) {
    return value * value * value;
}

int main() {
    matrix<int> M;
    std::cout << 4 * PI<float>;

/*
    unsigned number;
    std::cin >> number;
    auto cubed = cube(number);

    std::cout << cubed;
    */
}
