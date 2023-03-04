#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

using point_t = std::pair<double, double>;

class Polyline {
public:
    // Конструктур и деструктор, если необходимы

    // Добавить очередную точку в ломаную
    void addPoint(double x, double y) {
    	points.push_back({x, y});
    }
    
    // Получить количесто точек в ломаной в данный момент
    	unsigned int getNumberOfPoints() const {
		return points.size();
    	}
    
    // Получить длину ломаной в данный момент
    	double getLength() const {
	    	auto length = 0.;
	    	for (auto i = 0u; i + 1 < points.size(); i++) {
			length += std::sqrt(std::pow(points[i + 1].first - points[i].first, 2)
				+ std::pow(points[i + 1].second - points[i].second, 2));
		}
		return length;
    }

    // Получить x-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getX(unsigned int i) const {
	    return points[i].first;
    }
    
    // Получить y-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getY(unsigned int i) const {
	    return points[i].second;
    }

private:
    std::vector<point_t> points;
};

int main()
{
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    cout << "Length: " << p.getLength() << endl;
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
        cout << p.getX(i) << " " << p.getY(i) << endl;
    }
    return 0;
}
