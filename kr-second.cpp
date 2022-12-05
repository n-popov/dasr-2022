#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<bool>>;

int main() {
    int N, M;
    std::cin >> N >> M;
    auto field = matrix(M, std::vector<bool>(N));

    int K;
    std::cin >> K;

    for(auto i = 0; i < K; i++) {
        int X, Y, D;
        std::cin >> X >> Y >> D;
        if (D < 0) continue;
        for (auto i_y = Y - D; i_y <= Y + D; i_y++) {
            for (auto i_x = X - D; i_x <= X + D; i_x++) {
                if (0 <= i_x && i_x < N && 0 <= i_y && i_y < M) {
                    field[i_y][i_x] = true;
                }
            }
        }
    }

    auto count = 0;
    for(const auto& line: field) {
        for (auto cell: line) {
            count += cell;
        }
    }

    std::cout << N * M - count << std::endl;

}
