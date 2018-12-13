#include <variant>
#include <string>
#include <iostream>
#include <vector>

class Car 
{
public:
	Car (double speed, const std::string& name) : 
		m_speed(speed), m_name(name) {}

	void move() const {
		std::cout << m_name << " moved (speed = " << m_speed << 
			") from position A to B" << std::endl;
	}

private:
	double m_speed;
	std::string m_name;
};

class Plane
{
public:
	Plane(double speed, double height, const std::string& name) : 
		m_speed(speed), m_height(height), m_name(name) {}

	void move() const {
		std::cout << m_name << " (" << m_height << ") moved (speed = " 
			<< m_speed << ") from position A to B" << std::endl;
	}

private:
	double m_speed;
	double m_height;
	std::string m_name;
};

class Bike 
{
public:
	Bike(double speed) : m_speed(speed) {}

	void move() const {
		std::cout << "Bike moved (speed = " << m_speed << 
			") from position A to B" << std::endl;
	}

private:
	double m_speed;
};

int main()
{
	using Vehicle = std::variant<Car, Plane, Bike>;

	std::vector<Vehicle> vehicles {
		Bike(10),
		Plane(600, 5000, "Boeing"),
		Bike(20),
		Car(70, "Toyota") 
	};

	auto moveObject = [] (auto& objectToMove) {
		objectToMove.move();
	};

	for (auto& vehicle : vehicles) {
		std::visit(moveObject, vehicle);
	}

	return 0;
}

/**
 * Cechy tego typu polimorfizmu:
 *  - "typ bazowy" (czyli variant) musi znac wszystkie typy pochodne - 
 *		oczywisty minus
 *  - brak ograniczenia do hierarchi - potencjalnie brać udział mogą 
 *		mocno niezwiązane ze sobą obiekty
 *	- brak interfejsu (obecny jedynie kontener)
 *  - proste dodawanie nowych operacji - piszemy poprostu jedną funkcję, 
 *		nie trzeba zmieniać interfejsu (a zatem całej hierarchi)
 */