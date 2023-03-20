#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

struct Point{
	Point(int x, int y): x(x), y(y) {}
	int x, y;
};

std::ostream& operator<<(std::ostream& os, Point p) {
	return os << p.x << ' ' << p.y;
}

template<typename T>
class SmartPtr {
	public:
	template<typename ...Types>
	SmartPtr(Types ...args) {
		pointer = new T(args...);
	}
	SmartPtr(SmartPtr& other) = delete;

	SmartPtr& operator=(SmartPtr& other) = delete;

	~SmartPtr() {
		delete pointer;
	}

	T& operator*() {
		return *pointer;
	}

private:
	T* pointer;
};

int main() {
	SmartPtr<int> int_ptr(42);
	std::cout << *int_ptr << std::endl;
	*int_ptr = 5;
	std::cout << *int_ptr << std::endl;
	
	std::vector<Point> points;
	points.push_back({5, 5});
	points.push_back({1, 18});

	std::copy(std::begin(points), std::end(points), std::ostream_iterator<Point>(std::cout, "\n"));

	SmartPtr<Point> point_ptr(1, 2);
	auto point_ptr_copy = point_ptr;
	std::cout << *point_ptr_copy << std::endl;
}

