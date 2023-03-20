#include <iostream>
#include <vector>

template<typename T>
using matrix = std::vector<std::vector<T>>;


template<typename T>
const T PI = 3.1412;


template<typename T1, typename T2>
auto mul(T1 lhs, T2 rhs) {
	return lhs * rhs;
}

template<typename T>
void _print(T first) {
	std::cout << first << std::endl;
}

template<typename T, typename ...Types>
void _print(T first, Types ...other) {
	std::cout << first << ' ';
	_print(other...);
}

template<typename ...Types>
void print(Types ...args) {
	_print(args...);
}


int main(){
	std::cout << mul(2, 5.5) << std::endl;
	
	//std::cout << mul(2, "azaza") << std::endl;

	print(1, 4.2, "dasr", false);
}
