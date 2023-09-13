#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

std::string to_lower(std::string s) {
	std::transform(std::begin(s), std::end(s), std::begin(s), [](unsigned char c){return std::tolower(c);});
	return s;
}

int main() {
	std::map<std::string, std::set<std::string>> data;
	std::vector<std::pair<std::string, int>> filtered;

	int N;
	std::cin >> N;
	std::string word;
	for (auto i = 0u; i < N; i++) {
		std::cin >> word;
		data[to_lower(word)].insert(word);
	}

	for (const auto& pair: data) {
		auto variants = pair.second.size();
		if (variants > 2) {
			filtered.emplace_back(pair.first, variants);
		}
	}

	std::sort(std::begin(filtered), std::end(filtered), [](auto lhs, auto rhs){
		return (lhs.second == rhs.second) ? (lhs.first < rhs.first) : (lhs.second > rhs.second);
			});

	for (const auto& pair: filtered) {
		std::cout << pair.first << std::endl;
	}
}


