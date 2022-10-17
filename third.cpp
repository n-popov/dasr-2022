#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<bool> is_winnable(N + 1);

    for(auto i = (N + 1) / 2 - 1; i > 0; i--) {
        is_winnable[i] = !is_winnable[i + 2] &&
                         !is_winnable[i + 5] &&
                         !is_winnable[i * 2];
    }
    for(auto i = 1; i <= N; i++) {
        if(is_winnable[i]) {
            std::cout << i << std::endl;
            return 0;
        }
    }
}
