#include <vector>
void untangle(CharNode* record) {
    std::vector<char> ordered;
    for(auto node = record; node; node = node->next) {
        ordered.push_back(node->c);
    }

    auto size = ordered.size();
    // "ordered" array contains chars in proper order
    for(auto i = 0u; i < size; i++) {
        record[i].c = ordered[i];
        record[i].next = record + i + 1; // shifting pointer by i + 1
    }
    record[size - 1].next = nullptr;

}
