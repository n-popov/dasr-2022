#include <iostream>
#include <cmath>

class MathMixin {
	public:
	const double pi() const {
		return std::acos(-1);
	}

	double approximate_ellipse_perimeter(double a, double b) const {
		return pi() * std::sqrt(2 * (a * a + b * b)); 
	}
};

class Figure {
public:
	virtual double perimeter() const = 0;
	virtual double square() const = 0;
};

class Ellipse: public Figure, private MathMixin {
public:
	Ellipse(double a, double b): a(a), b(b) {}

	double perimeter() const override {
		return approximate_ellipse_perimeter(a, b);
	}

	double square() const override {
		return pi() * a * b;
	}	
private:
	double a, b;
};

class Circle: public Ellipse {
public:
	Circle(double r): Ellipse(r, r) {}
};


int main() {
	Ellipse ellipse(4, 5);
	std::cout << ellipse.perimeter() << std::endl;
	std::cout << ellipse.square() << std::endl;

	Circle circle(3);
	std::cout << circle.perimeter() << std::endl;
	std::cout << circle.square() << std::endl;
}	

