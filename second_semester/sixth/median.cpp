#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	std::map<std::string, std::vector<int>> data;
	int N;
	std::cin >> N;
	std::string sensor;
	int value;
	for (auto i = 0; i < N; i++) {
		std::cin >> sensor >> value;
		data[sensor].push_back(value);
	}
	std::cin >> N;
	for (auto i = 0; i < N; i++) {
		std::cin >> sensor;
		auto found = data.find(sensor);

		if (found == data.end()) {
			std::cout << "no data" << std::endl;
			continue;
		}

		auto& values = found->second;
		auto nth = std::next(
			values.begin(),
			(std::distance(values.begin(), values.end()) + 1) / 2 - 1
		);
		std::nth_element(values.begin(), nth, values.end());
		std::cout << *nth << std::endl;
}
}
