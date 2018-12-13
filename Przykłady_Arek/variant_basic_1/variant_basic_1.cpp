/*
 std::variant - przykład 1
 Przykład obrazujący podstawy działania std::variant.
*/

#include <iostream>
#include <variant>
#include <string>

using namespace std::literals;

//#define ERROR1
//#define ERROR2

int main()
{
	std::variant<int, float, std::string> exampleVariant;
	exampleVariant = 128; // domyślnie pierwszy typ - int
	std::cout << std::get<int>(exampleVariant) << std::endl;
	std::cout << std::get<0>(exampleVariant) << std::endl;

	#ifdef ERROR1
		// w srodku nie ma typu double
		std::cout << std::get<double>(exampleVariant) << std::endl; 
	#endif

	#ifdef ERROR2
		// niepoprawny indeks
		std::cout << std::get<4>(exampleVariant) << std::endl;
	#endif

	// Powyższe sytuacje pokazują zachowanie, gdy chcemy typ lub indeks którego
	// w std::variant poprostu nie ma. 
	// Inaczej prezentuje się natomiast sytuacja, gdy chcemy pobrać typ poprawny
	// dla variant, ale nie będący aktualnie tym aktywnym.

	// Wtedy używamy mechanizmu wyjątków
	try 
	{
		// aktualnie aktywny typ to int
		std::cout << std::get<float>(exampleVariant) << std::endl;
	}
	catch (const std::bad_variant_access& e) {
		std::cout << e.what() << std::endl; // Unexpected index
	}

	try
	{
		// aktualny indeks to 0
		std::cout << std::get<1>(exampleVariant) << std::endl;
	}
	catch (const std::bad_variant_access& e) {
		std::cout << e.what() << std::endl;
	}	

	exampleVariant = "Jakis tekst"s; // zmiana typu

	std::cout << std::get<std::string>(exampleVariant) << std::endl;

	return 0;
}