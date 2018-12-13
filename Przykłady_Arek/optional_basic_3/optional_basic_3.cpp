#include <optional>
#include <iostream>

struct Point {
	Point(double x = 0, double y = 0) :
		m_x(x), m_y(y) {}

	void print() const {
		std::cout << m_x << " " << m_y << std::endl;
	}

	~Point() {
		std::cout << "Niszczenie: " << m_x << " " << m_y << std::endl;
	}

private:
	double m_x;
	double m_y;
};

int main()
{
	// ciekawostka: std::in_place
	// Mozna przekazac do konstruktora optional, variant i any
	// Wskazuje, ze obiekt powinien zostac stworzony w miejscu
	// Dla optional nie trzeba podawac typu - dla pozostalych
	// dwoch tak
	std::optional<Point> test {std::in_place, 2.5, -1.5};
	test->print();
	test.emplace(10, 10);
	test->print();

	return 0;
}