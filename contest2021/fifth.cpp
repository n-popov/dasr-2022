Sequence* make_sequence(int size) {
    auto s = new Sequence();
    if (size) s->data = new int[size];
    else s->data = nullptr;
    s->size = 0;
    return s;
}
void separate_odd_even(const Sequence* input, Sequence** odd, Sequence** even) {
    Sequence* new_odd = make_sequence(input->size);
    Sequence* new_even = make_sequence(input->size);

    for(int i = 0; i < input->size; i++) {
        auto elem = input->data[i];
        if (elem % 2) {
            new_odd->data[new_odd->size++] = elem;
        } else {
            new_even->data[new_even->size++] = elem;
        }
    }
    *odd = new_odd;
    *even = new_even;
}
void clear(Sequence* s) {
    delete[] s->data;
    delete s;
}
