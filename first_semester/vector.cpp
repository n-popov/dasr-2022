#include <iostream>



struct VectorInt {
    int* data;
    int size, actual_size;

    VectorInt(int new_size = 1) {
        std::cout << "Constructor called" << std::endl;
        size = new_size;
        actual_size = 0;
        data = new int[size];
    }

    ~VectorInt() {
        std::cout << "Destructor called" << std::endl;
        delete[] data;
    }

    int get(int index) {
        return data[index];
    }

    void set(int index, int value) {
        data[index] = value;
    }

    void resize(int new_size) {
        int* new_array = new int[new_size];
        for (auto i = 0; i < size; i++) {
            new_array[i] = data[i];
        }
        delete[] data;
        data = new_array;
    }

    void push(int value) {
        if (actual_size == size) {
            size *= 2;
            resize(size);
        }
        data[actual_size++] = value;
    }

};

int main(){
    VectorInt array;
    for (auto i = 0; i < 5; i++) {
        array.push(i * i);
    }
    for (auto i = 0; i < array.actual_size; i++) {
        std::cout << array.get(i) << ' ';
    }
    std::cout << "Actual size:" << array.actual_size << std::endl;
    std::cout << "Size:" << array.size << std::endl;
}
