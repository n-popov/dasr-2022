#include <iostream>
#include <vector>

int main() {
    int X, Y;
    std::cin >> X >> Y;

    std::vector<std::vector<bool>> field(Y);
    for(auto i = 0u; i < field.size(); i++) {
        field[i].resize(X);
    }

    int N;
    std::cin >> N;
    for(auto i = 0; i < N; i++) {
        int x, y, d;

        std::cin >> x >> y >> d;

        if (d < 0) continue;

        int xl = std::max(0, x - d);
        int xr = std::min(X, x + d + 1);
        int yl = std::max(0, y - d);
        int yr = std::min(Y, y + d + 1);

        for (int yi = yl; yi < yr; yi++) {
            for (int xi = xl; xi < xr; xi++) {
                field[yi][xi] = 1;
            }
        }
    }

    int cells = X * Y;
    for (int yi = 0; yi < Y; yi++) {
        for (int xi = 0; xi < X; xi++) {
            cells -= field[yi][xi];
        }
    }

    std::cout << cells << std::endl;
}

