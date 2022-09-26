#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> data(n);
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < m; j++) {
            int temporary;
            std::cin >> temporary;
            data[i].push_back(temporary);
        }
    }
    for (auto i = 1; i < n; i++) {
        data[i][0] += data[i - 1][0];
    }
    for (auto i = 1; i < m; i++) {
        data[0][i] += data[0][i - 1];
    }

    for (auto i = 1; i < n; i++) {
        for (auto j = 1; j < m; j++) {
            data[i][j] += std::min(data[i - 1][j], data[i][j - 1]);
        }
    }
    std::vector<int> path; // 0 down, 1 right

    for(auto i = n - 1, j = m - 1;i > 0 || j > 0;) {
        if (i == 0 || j == 0) {
            for(;i > 0; i--) {
                path.push_back(0);
            }
            for(;j > 0; j--) {
                path.push_back(1);
            }
            break;
        }
        path.push_back(((data[i - 1][j] < data[i][j - 1]) ? 0 : 1));
        j -= (path[path.size() - 1] == 1) ? 1 : 0;
        i -= (path[path.size() - 1] == 0) ? 1 : 0;
    }
    for(auto i = 0; i < path.size(); i++) {
        if (path[path.size() - i - 1]) {
            std::cout << "right" << ' ';
        } else {
            std::cout << "down" << ' ';
        }
    }
}
