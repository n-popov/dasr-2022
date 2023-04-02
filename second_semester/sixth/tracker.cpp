#include <map>
#include <iostream>

int main() {
	std::map<std::string, std::map<int, std::string>> data;

	int N;
	std::cin >> N;
	std::string id, loc;
	int time;
	for (auto i = 0; i < N; i++) {
		std::cin >> id >> loc >> time;
		data[id][time] = loc;
	}

	std::cin >> N;
	std::string trash;
	for (auto i = 0; i < N; i++) {
		std::cin >> trash >> id >> time;
		auto data_for_id_it = data.find(id);
		if (data_for_id_it == data.end()) {
			std::cout << "no data" << std::endl;
			continue;
		}
		auto& locs = data_for_id_it->second;
		auto bound = locs.upper_bound(time);
		if (bound == locs.begin()) {
			std::cout << "no data" << std::endl;
		} else {
			std::cout << std::prev(bound)->second << std::endl;
	}
	}
}
