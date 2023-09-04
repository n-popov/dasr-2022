#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
	int symbol_index = ((i < n / 2) ? i : (n - i - 1));
	int symbols = 2 * symbol_index + 1;
        int spaces = (n - symbols) / 2;

        for (int j = 0; j < n; j++) {
            if (j < spaces || j >= spaces + symbols) {
                std::cout << ' ';
            } else {
                std::cout << '+';
            }
        }
        std::cout << std::endl;
    }
}

