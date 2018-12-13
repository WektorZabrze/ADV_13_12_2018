#include <optional>
#include <iostream>
#include <cmath>

std::optional<double> safeSqrt(double value) {
	if (value >= 0) return std::sqrt(value);
	else return std::nullopt; // reprezentuje pustą wartość
}

int main()
{
	auto sqrtOf2 = safeSqrt(2.0);
	if (sqrtOf2) // konwersja do bool (to samo co metoda has_value())
	{
		std::cout << "Sqrt(2) = " << sqrtOf2.value() << std::endl;
		std::cout << "Sqrt(2) = " << *sqrtOf2 << std::endl;
	}
	else {
		std::cout << "Próba liczenia pierwiastka z liczby ujemnej" << std::endl;
	}

	auto sqrtOfNegative = safeSqrt(-2.0);
	if (sqrtOfNegative.has_value()) {
		std::cout << "Sqrt(-2) = " << sqrtOfNegative.value() << std::endl; 
	}
	else {
		std::cout << "Pierwiastek z liczby ujemnej" << std::endl;
	}

	return 0;
}