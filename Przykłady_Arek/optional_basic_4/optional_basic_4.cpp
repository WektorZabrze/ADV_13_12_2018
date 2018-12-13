#include <optional>
#include <iostream>

class Comparable {
public:
	Comparable(double value) : m_value (value) {}

	friend bool operator< (const Comparable& lhs, const Comparable& rhs) {
		std::cout << "Porownuje " << lhs.m_value << " < " << rhs.m_value << std::endl;
		return lhs.m_value < rhs.m_value;
	}

private:
	double m_value;
};

int main() 
{
	std::optional<double> test1 (20);
	std::optional<double> test2 (-100.50);

	std::cout << std::boolalpha << (test1 < test2) << std::endl;
	std::cout << std::boolalpha << (test1 == test2) << std::endl;
	std::cout << std::boolalpha << (test1 > test2) << std::endl;
	std::cout << std::boolalpha << (test1 <= test2) << std::endl;
	std::cout << std::boolalpha << (test1 >= test2) << std::endl;
	std::cout << std::boolalpha << (test1 != test2) << std::endl;

	std::optional<Comparable> lhs {std::in_place, 4};
	std::optional<Comparable> rhs {std::in_place, 10};

	std::cout << std::boolalpha << (lhs < rhs) << std::endl;

	// A co jak damy pusty?
	std::optional<int> test3;

	// Uwaga!!!!
	std::cout << std::boolalpha << (test3 < test1) << std::endl;

	return 0;
}

