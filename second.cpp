#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int first, second, third;
    std::cin >> first;
    if (n == 1) {
        std::cout << 0;
        return 0;
    }
    std::cin >> second;
    for(auto i = 0; i+++ 2 < n;) {
        std::cin >> third;
        third = std::min(first + third, second + third);
        first = second;
        second = third;
    }
    std::cout << std::min(first, second);
}
