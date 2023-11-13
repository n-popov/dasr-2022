#include <iostream>

template <typename T>
struct Vector {
    T* data;
    int _size; // current size
    int _capacity; // maximum number of elements available

    // Create vector
    Vector(int start_size = 0) {
        data = new T[start_size];
        _capacity = start_size;
        _size = 0;
    }

    // Add element to end
    void push_back(T element) {
        if (_size == _capacity) {
            _capacity = (_capacity ? _capacity * 2 : 1);
            auto new_data = new T[_capacity];

            for (auto i = 0; i < _size; i++) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
        }

        data[_size++] = element;
    }

    void insert(T elem, int index) {

    }

    // Address element by index
    int at(int index) {
        return data[index];
    }

    int operator[](int index) {
        return data[index];
    }

    // Remove element from end
    void pop_back() {
        _size--;
    }


    // Destroy vector (free memory)
    ~Vector() {
        std::cout << "Hello from destructor" << std::endl;
        delete[] data;
    }

    // Size of vector
    int size() {
        return _size;
    }

    // Capacity of vector
    int capacity() {
        return _capacity;
    }

};

template <typename K>
struct Stack {
    void push(K elem) {
        v.push_back(elem);
    }

    int top() {
        return v.at(v.size() - 1);
    }

    int pop() {
        auto last = top();
        v.pop_back();
        return last;
    }

    Vector<K> v;
};


int main() {
    {
        auto array = Vector<int>(3);
        for (auto i = 0; i < 7; i++) {
            array.push_back(i);
            std::cout << array[i] << ' ' <<
                array.size() << ' ' <<
                array.capacity() << std::endl;
        }
    }

    auto s = Stack<float>();
    for (auto i = 0; i < 3; i++) {
        s.push(i);
    }
    for (auto i = 0; i < 3; i++) {
        std::cout << s.pop() << std::endl;
    }
}




