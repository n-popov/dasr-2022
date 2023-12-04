
double mean(unsigned* arr, unsigned len) {
    double sum = 0.;
    for (auto i = 0u; i < len; i++) {
        sum += i[arr];
    }
    return sum / len;
}

void swap(unsigned* left, unsigned* right, unsigned len) {
    for (auto i = 0u; i < len; i++) {
        auto tmp = left[i];
        left[i] = right[i];
        right[i] = tmp;
    }
}

void sort_errors(unsigned int** errors, unsigned int n, unsigned int m) {
    for(auto i = 1u; i < n; i++) {
        for(auto j = i; j > 0; j--) {
            if (mean(errors[j], m) + 0.01 < mean(errors[j - 1], m))
                swap(errors[j], errors[j - 1], m);
        }
    }
}
