/*
 Przykład ilustrujący działanie std::visit
*/

#include <variant>
#include <iostream>
#include <string>

int main()
{
	std::variant<int, float, std::string> testVariant1 = 1;
	std::variant<std::string, double> testVariant2 = std::string("Testowy napis");

	// generic lambda
	auto Printer = [] (const auto& arg) { std::cout << arg << std::endl; };

	// najbardziej klasyczny przykład - wypisywanie
	std::visit(Printer, testVariant1);

	// A co jesli chcemy uzyc wiecej niz jednego std::variant?
	auto MultiPrinter = [] (const auto& arg1, const auto& arg2) {
		std::cout << arg1 << " and " << arg2 << std::endl;
	};

	std::visit(MultiPrinter, testVariant1, testVariant2);



	return 0;
}