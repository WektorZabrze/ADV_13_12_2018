#include <optional>
#include <iostream>
#include <string>

template<typename T>
void printOptional(const std::optional<T>& toPrint) {
	if (!toPrint) {
		std::cout << "Nie ma wartosci w srodku" << std::endl;
	}
	else {
		std::cout << *toPrint<< std::endl;
	}
}

int main()
{
	std::cout << " -- Test -- " << std::endl;
	std::optional<double> emptyOptional; // konstruktor domyslny
	printOptional(emptyOptional);

	std::cout << " -- Test 2 -- " << std::endl;
	std::optional secondEmpty(emptyOptional); // kopiowanie pustego 
	printOptional(secondEmpty);

	// Dzialanie value_or
	std::cout << "value_or: " << secondEmpty.value_or(-600.5) << std::endl; 

	std::cout << " -- Test 3 --" << std::endl;
	std::optional notEmpty(15.5); // dedukcja
	printOptional(notEmpty);

	// Dzialanie operatora ->
	std::optional<std::string> withString = "Napis";
	std::cout << "operator ->: " << withString->size() << std::endl;

	// Roznice pomiedzy * a value():
	std::cout << " -- Różnice pomiedzy * a .value() -- " << std::endl;
	try 
	{
		// rzuca wyjatek
		std::cout << emptyOptional.value() << std::endl;
	}
	catch (const std::bad_optional_access& e) {
		std::cout << e.what() << std::endl;
	}

	try 
	{
		// undefined
		std::cout << *emptyOptional << std::endl;
	}
	catch (const std::bad_optional_access& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}