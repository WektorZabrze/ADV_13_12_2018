#include <any>
#include <iostream>

class Loud
{
public:
	Loud(int a, int b) : m_a(a), m_b(b) {
		std::cout << "Loud() with " << a << " and " << b << std::endl;
	}

	~Loud() {
		std::cout << "~Loud()" << std::endl;
	}

	void print() const {
		std::cout << m_a << " " << m_b << std::endl;
	}

private:
	int m_a;
	int m_b;
};

int main()
{
	std::any test (1);
	std::cout << test.has_value() << std::endl;

	test.emplace<Loud>(5, 10); // dzialanie emplace  - 
	// wynik to std::decay_t<Loud> - m.in usuwa cv, zamienia 
	// tablice na wskaznik
	std::any_cast<Loud>(test).print();

	std::cout << "-- UWAGA NA DESTRUKTORY --" << std::endl;
	test = 5.0;

	std::cout << std::any_cast<double>(test) << std::endl;

	// użycie make_any
	std::any test2 = std::make_any<Loud>(19, 97);
	std::any_cast<Loud>(test2).print();

	return 0;
}