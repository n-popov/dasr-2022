#include <iostream>

template<typename T>
struct Wrapper {
	Wrapper(T value): value(value) {}
	T value;	
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Wrapper<T> wrapper) {
	return os << wrapper.value << ' ';
}

template<typename T>
void print_one(T arg) {
	std::cout << arg << ' ' << std::endl;
}

template<typename T, typename ...Types>
void print_one(T arg, Types ...other) {
	std::cout << arg << ' ';
	print_one<Types...>(other...);	
}


template <typename ...Types>
void print(Types ...args) {
	return print_one(args...);
}

template <typename ...Types>
void print_alt(Types ...args) {
	(std::cout << ... << Wrapper(args));
	std::cout << std::endl;
}


int main() {
	print(1, 3, 'c', true, "azaza");
	print_alt(1, 3, 'c', true, "ababa");
}
