/*
 Przykład obrazuje sposoby na zmianę wartości w std::variant
*/

#include <iostream>
#include <variant>

class TestClass {
public:
	TestClass(int x, int y) : m_x(x), m_y(y) {}

	void print() const {
		std::cout << m_x << " " << m_y << std::endl;
	}

private:
	int m_x;
	int m_y;
};

int main()
{
	std::variant <float, int> example {5.0f};

	// Operator przypisania
	example = 4.5f;
	std::cout << std::get<0>(example) << std::endl;
	example = 2;
	std::cout << std::get<1>(example) << std::endl;

	// emplace
	example.emplace<1>(3);
	std::cout << std::get<1>(example) << std::endl;
	example.emplace<0>(4.0f); // zmienia aktywny typ 
	std::cout << std::get<0>(example) << std::endl;

	example.emplace<int>(20);
	std::cout << std::get<int>(example) << std::endl;

	// std::get/ std::get_if
	auto& refToMember = std::get<int>(example);
	refToMember = 100;
	std::cout << std::get<int>(example) << std::endl;

	example = 20.5f;
	if (auto floatPtr = std::get_if<float>(&example)) {
		*floatPtr = 123.4567f;
	}

	std::cout << std::get<float>(example) << std::endl;

	// Inny przykład użycia emplace - widac ze dziala jak 
	// np. emplace_back w vectorze
	std::variant <int, TestClass> emplaceTest = 10;
	emplaceTest.emplace<1>(5, 10);
	std::get<1>(emplaceTest).print();

	return 0;
}