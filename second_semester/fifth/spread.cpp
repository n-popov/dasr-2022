#include <iostream>

template<typename T>
struct DelimiterAdder {
	DelimiterAdder(T value): value(value) {}	
	T value;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, DelimiterAdder<T> d) {
	return os << d.value << ' ';
}

template<typename ...Types>
void print(Types ...args) {
	(std::cout << ... << DelimiterAdder(args));
	std::cout << std::endl;
}

int main() {
	print(42, "biba", std::string("boba"), 12.5);
}
