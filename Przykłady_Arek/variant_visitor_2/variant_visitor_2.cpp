/*
 Przykład 2 obrazujący działanie std::visit
*/

#include <string>
#include <variant>
#include <iostream>

using namespace std::literals::string_literals;

class AddTenVisitor
{
public:

	void operator()(int& arg) { arg += 10; }
	void operator()(std::string& arg) { arg += "10"; }
	void operator()(float& arg) { arg += 10.0f; }
};

int main()
{
	std::variant<int, float, std::string> toModify = 10;
	std::cout << std::get<int>(toModify) << std::endl;

	std::visit(AddTenVisitor(), toModify);
	std::cout << std::get<int>(toModify) << std::endl;

	toModify = "Wynik wynosi: "s;
	std::cout << std::get<std::string>(toModify) << std::endl;
	std::visit(AddTenVisitor(), toModify);
	std::cout << std::get<std::string>(toModify) << std::endl;

	toModify = 25.5f;
	std::cout << std::get<float>(toModify) << std::endl;
	std::visit(AddTenVisitor(), toModify);
	std::cout << std::get<float>(toModify) << std::endl;
}