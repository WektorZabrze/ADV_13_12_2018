/*
 Przykład 3 obrazujący działanie std::variant. 
*/

#include <iostream>
#include <variant>
#include <vector>

//#define ERROR1
//#define ERROR2
//#define ERROR3

int main()
{
	std::variant<int, float, std::vector<int>> exampleVariant;

	// metoda index() zwraca indeks aktualnie aktywnego typu
	std::cout << "Current index = " << exampleVariant.index() << std::endl;
	exampleVariant = std::vector<int> {1, 2, 3, 4};
	std::cout << "Current index = " << exampleVariant.index() << std::endl;
	exampleVariant = 4.5f; // danie 4.5 powoduje blad kompilacji

	// dostep do przechowywanej wartości za pomocą get
	try 
	{
		std::cout << std::get<float>(exampleVariant) << std::endl;
		std::cout << std::get<1>(exampleVariant) << std::endl;

		std::cout << std::get<0>(exampleVariant) << std::endl; // wyjątek
	}
	catch (const std::bad_variant_access& e) {
		std::cout << e.what() << std::endl;
	}

	// dostepna jest rowniez funkcja std::get_if - zwraca wskaznik na
	// przechowywany element lub null pointer, jesli takiego nie ma
	// Uwage - variant przekazujemy tutaj przez wskaznik
	if (auto valPtr = std::get_if<float>(&exampleVariant)) {
		std::cout << "Stored value = " << *valPtr << std::endl;
	}
	else {
		std::cout << "Could not extract value" << std::endl;
	}

	// przykład, gdy nie zadziala
	if (auto valPtr = std::get_if<0>(&exampleVariant)) {
		std::cout << "Stored value = " << *valPtr << std::endl;
	}
	else {
		std::cout << "Wrong index" << std::endl;
	}

	// Szablon funkcji std::holds_alternative<T>() - sprawdza, czy aktualnie
	// variant przechowuje wartosc typu T
	if (std::holds_alternative<int>(exampleVariant)) {
		std::cout << "Variant przechowuje aktualnie int" << std::endl;
	}
	else if (std::holds_alternative<float>(exampleVariant)) {
		std::cout << "Variant przechowuje aktualnie float" << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(exampleVariant)) {
		std::cout << "Variant przechowuje aktualnie std::vector<int>" << std::endl;
	}


	// Jest jednak jeden problem - czasem może sie zdarzyc, że bedziemy chcieli miec
	// dwie wartosci tego samego typu w std::variant
	std::cout << "-- ZMIANA TYPOW --" << std::endl;
	std::variant<double, int, double> secondExample;

	#ifdef ERROR1
		if (std::holds_alternative<double>(secondExample)) {
			std::cout << "Variant przechowuje double" << std::endl;
		}
	#endif

	#ifdef ERROR2
		if (auto valPtr = std::get_if<double>(&secondExample)) {
			std::cout << *valPtr << std::endl;
		}
	#endif

	#ifdef ERROR3
		std::cout << std::get<double>(secondExample) << std::endl;
	#endif

	// Funkcje operujące na typach przestają wiec działać

	// Można jednak wciąż korzystać z indeksow

	std::cout << std::get<0>(secondExample) << std::endl;

	return 0;
}