#include <iostream>

int main() {
    int n, x;
    int coins[1000];
    std::cin >> n;
    for (auto i = 0; i < n; std::cin >> coins[i++]);
    std::cin >> x;
    for (auto i = 0; i < n; i++) {
        for(auto j = n - 1; j > i; j--) {
            if (coins[j] > coins[j - 1]) {
                coins[j] = coins[j - 1] + coins[j];
                coins[j - 1] = coins[j] - coins[j - 1];
                coins[j] = coins[j] - coins[j - 1];
            }
        }
    }
    int count = 0;
    for(auto i = 0; i < n; i++) {
        if (coins[i] <= x) {
            count++;
            x -= coins[i];
        }
    }
    std::cout << ((x > 0) ? -1 : count);
}
