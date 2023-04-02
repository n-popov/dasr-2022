#include <set>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	std::set<std::string> unique_words;
	std::string word;
	for (auto i = 0; i < N; i++) {
		std::cin >> word;
		unique_words.insert(word);
	}

	std::vector<std::string> words;

	std::copy(unique_words.begin(),
		unique_words.end(),
		std::back_inserter(words));

	std::sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.size() > rhs.size();
		});

	std::copy(words.begin(), words.end(),
		std::ostream_iterator<std::string>(std::cout, "\n"));

}
