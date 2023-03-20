#include <iostream>
#include <thread>

void print_word(const std::string& word) {
	std::cout << word << std::endl;
}

int main() {
	std::thread other(print_word, "Hello from thread!");

	std::thread another(print_word, "Hello from another!");
	print_word("Hello from main!");
	other.join();
	another.join();
}
