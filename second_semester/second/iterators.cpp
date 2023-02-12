#include <vector>
#include <iostream>
#include <unordered_map>

int main() {
	std::vector<int> vector;

	for (auto i = 0; i < 5;){
		vector.push_back(i++);
	}

	std::vector<int>::iterator it = vector.begin();
	std::cout << *it << std::endl;

	std::cout << *(it + 3) << std::endl;

	for(auto iter = std::next(vector.begin(), 2); iter != vector.end(); iter = std::next(iter)) {
		std::cout << *iter << ' ';
	}

	std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>>::const_iterator map_iterator;
}

