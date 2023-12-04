#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;

    double x0, y0, t0;
    std::cin >> t0 >> x0 >> y0;
    double distance = 0;

    for(int i = 1; i < N; i++) {
        double x, y, t;
        std::cin >> t >> x >> y;

        auto s = std::sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
        if (s < 330 * (t - t0)) distance += s;
        x0 = x;
        y0 = y;
        t0 = t;
    }
    std::cout << std::fixed << std::setprecision(1) << distance << std::endl;
}

