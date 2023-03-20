#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

const size_t BORDER_SIZE = 1000u;

template<typename Iter, typename T>
void accumulate_block(Iter begin, Iter end, T init, T& result) {
	result = std::accumulate(begin, end, init);
}

template<typename Iter, typename T>
T parallel_accumulate(Iter begin, Iter end, T init) {
	auto size = st>
d::distance(begin, end);
	if (size <= BORDER_SIZE) {
		return std::accumulate(begin, end, init);
	}

	auto num_threads = std::thread::hardware_concurrency();
	auto block_size = size / num_threads;
	std::vector<std::thread> threads;
	std::vector<T> results(num_threads - 1);

	for(auto i = 0u; i + 1 < num_threads; i++) {
		threads.emplace_back(
			accumulate_block<Iter, T>,
			std::next(begin, i * block_size),
			std::next(begin, (i + 1) * block_size),
			0,
			std::ref(results[i])
		);
	}
	auto last_result = std::accumulate(
		std::next(begin, (num_threads - 1) * block_size),
		end,
		init
	);
	for(auto& thread: threads) {
		thread.join();
	}
	return std::accumulate(results.begin(), results.end(),
			last_result);
}

int main() {
	std::vector<int> numbers(10000u);
	std::iota(std::begin(numbers), std::end(numbers), 1);
	std::cout << parallel_accumulate(std::begin(numbers),
		std::end(numbers), 0) << std::endl;
}

