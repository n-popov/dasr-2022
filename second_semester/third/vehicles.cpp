#include <iostream>

using namespace std;

// Абстрактное транспортное средство
class Vehicle {
public:
    // Может ли ездить по суще
    virtual bool canDrive() const {
        return false;
    }

    // Может ли плавать
    virtual bool canSail() const {
        return false;
    }

    // Может ли летать
    virtual bool canFly() const {
        return false;
    }

    virtual ~Vehicle() {};
};

class Car: public Vehicle {
	public:
	bool canDrive() const override {
		return true;
	}
};

class Ship: public Vehicle {
	public:
	bool canSail() const override {
		return true;
	}
};

class Plane: public Vehicle {
	public:
	bool canFly() const override {
		return true;
	}
};

class Truck: public Car {};

int main()
{
    cout << boolalpha;
    Vehicle* v;

    v = new Car();
    cout << "Car can drive: " << v->canDrive() << endl;
    cout << "Car can sail: " << v->canSail() << endl;
    cout << "Car can fly: " << v->canFly() << endl;
    delete v;

    v = new Ship();
    cout << "Ship can drive: " << v->canDrive() << endl;
    cout << "Ship can sail: " << v->canSail() << endl;
    cout << "Ship can fly: " << v->canFly() << endl;
    delete v;

    v = new Plane();
    cout << "Plane can drive: " << v->canDrive() << endl;
    cout << "Plane can sail: " << v->canSail() << endl;
    cout << "Plane can fly: " << v->canFly() << endl;
    delete v;

    Car* c = new Truck();
    cout << "Truck can drive: " << c->canDrive() << endl;
    cout << "Truck can sail: " << c->canSail() << endl;
    cout << "Truck can fly: " << c->canFly() << endl;
    delete c;

    return 0;
}
