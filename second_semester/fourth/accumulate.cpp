#include <iostream>
#include <thread>
#include <numeric>
#include <vector>
#include <future>
#include <chrono>
#include <random>
#include <algorithm>

using steady_clock = std::chrono::steady_clock;

class Timer {
public:
	Timer(): start(steady_clock::now()) {}

	~Timer() {
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(steady_clock::now() - start).count() << std::endl;
	}
private:
	steady_clock::time_point start;
};

template <typename Iterator, typename T>
void accumulate_block(Iterator begin, Iterator end, T init, T& result) {
	result = std::accumulate(begin, end, init);
}

template <typename Iterator, typename T>
T parallel_accumulate(Iterator begin, Iterator end, T init) {
	auto size = std::distance(begin, end);
	auto middle = std::next(begin, size / 2);

	auto result = 0;
	std::thread other(accumulate_block<Iterator, T>,
			begin, middle, 0, std::ref(result));
	auto main_result = std::accumulate(middle, end, 0);
	
	other.join();
	return init + main_result + result;
}

template <typename Iterator, typename T>
T future_accumulate(Iterator begin, Iterator end, T init) {
	auto size = std::distance(begin, end);
	auto middle = std::next(begin, size / 2);

	auto result = std::async(std::launch::async, std::accumulate<Iterator, T>, begin, middle, 0);
	auto main_result = std::accumulate(middle, end, init);
       	return main_result + result.get();
}


int main() {
	std::vector<int> numbers(10'000);

	std::iota(numbers.begin(), numbers.end(),1);
	
	std::cout << future_accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> d(1, 10);
	std::vector<int> test_nums;
	std::generate_n(std::back_inserter(test_nums), 10'000'000,
			[&gen, &d](){return d(gen);});

	std::cout << "Parallel" << std::endl;
	{
		Timer t;

		auto result = future_accumulate(test_nums.begin(),
				test_nums.end(),
				0);
	}
	std::cout << "Sequential" << std::endl;
	{
		Timer t;

		auto result = std::accumulate(test_nums.begin(),
				test_nums.end(),
				0);
	}



}
