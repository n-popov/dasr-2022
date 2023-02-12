#include <iostream>
#include <vector>
#include <chrono>


std::vector<int>
merge(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    std::vector<int> merged;
    auto i = 0, j = 0;
    for (; i < lhs.size() && j < rhs.size();) {
        if (lhs[i] < rhs[j]) {
                merged.push_back(lhs[i++]);
            } else {
                merged.push_back(rhs[j++]);
        }
    }
    for(; i < lhs.size(); merged.push_back(lhs[i++]));
    for(; j < rhs.size(); merged.push_back(rhs[j++]));
    return merged;
}

std::vector<int> merge_sort(const std::vector<int>& array) {
    if (array.size() > 1) {
        auto middle = array.size() / 2;
        std::vector<int> left, right;
        for(auto i = 0; i < middle; i++) {
            left.push_back(array[i]);
        }
        for(auto i = middle; i < array.size(); i++) {
            right.push_back(array[i]);
        }
        auto sorted_left = merge_sort(left);
        auto sorted_right = merge_sort(right);
        return merge(sorted_left, sorted_right);
    }
    return array;
}

struct Timer {

    std::chrono::high_resolution_clock::time_point start;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << (end - start).count() << std::endl;
    }

};


int main() {

    std::vector<int> initial = {5, 1, 42, 3, -254, 6, 7};

    std::vector<int> result;

    {
        Timer t;
        result = merge_sort(initial);
    }


    for(auto number: result) {
        std::cout << number << ' ';
    }
}
