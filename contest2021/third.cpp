
#include <vector>
void separate_rgba(unsigned int *data, unsigned int n) {
    std::vector<unsigned> ordered;

    for (int j = 0; j <= 3; j++) {
        for (unsigned i = 0u; i < n; i++) {
            ordered.push_back(data[4 * i + j]);
        }
    }

    for(auto i = 0u; i < ordered.size(); i++) {
        data[i] = ordered[i];
    }

}
