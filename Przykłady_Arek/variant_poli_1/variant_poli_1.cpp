#include <iostream>
#include <variant>
#include <string>
#include <vector>

class Car {
public:
	Car (double velocity) : m_velocity(velocity) {}

	void print() const {
		std::cout << "This is a car. It's velocity = " << m_velocity << std::endl;
	}

private:
	double m_velocity;
};

class Building {
public:
	void print() const {
		std::cout << "This is a building" << std::endl;
	}
};

class Person {
public:
	Person (const std::string& name) : m_name(name) {}

	void print() const {
		std::cout << "This is " << m_name << std::endl;
	}

private:
	std::string m_name;
};

int main() {

	// Mozna umiescic w vectorze - bo to vector variantow - czyli
	// tych samych typow
	std::vector<std::variant<Building, Car, Person>> townStuff {
		Car (50), Building(), Person("John"), Building()
	};

	// kazdy typ, ktory zostanie przekazany jako obj, ma miec
	// metode print - i to jest jedyna rzecz, ktora musi je 
	// laczyc
	auto printInfo = [] (auto& obj) { obj.print(); };

	for (auto elem: townStuff) {
		std::visit(printInfo, elem);
	}
}