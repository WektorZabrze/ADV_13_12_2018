/*
 Przykład służący za wstęp do tematu std::variant. Przykład ten obrazuje 
 sytuację przed C++17 i bez Boost - czyli użycie klasycznych unii znanych
 od starych standardów języka.
*/

#include <cstdint> // std::uint32_t
#include <iostream> // std::cout, std::endl

//#define Undefined

union SimpleUnion
{
	std::uint32_t dWord;
	float floatingPoint;
};

union SimpleUnion2
{
	std::uint32_t dWord;
	std::uint16_t word;
};

int main()
{
	SimpleUnion a = {1024}; // inicjalizacja pierwszego elementu - on jest domyslny
	// uwaga - bez {} blad kompilacji
	std::cout << a.dWord << std::endl; // w tym momencie odczyt a.floatingPoint to UB

	a.floatingPoint = 2.5; // a.floatingPoint jest teraz aktywne
	std::cout << a.floatingPoint << std::endl;

	#ifdef Undefined
		std::cout << a.dWord << std::endl; // UB - dostajemy jakas losowa wartosc

	SimpleUnion2 test = {15};
	std::cout << test.dWord << std::endl;
	std::cout << test.word << std::endl; // tu widac ze trzymane w jednym miejscu
	// kompilator czesto implementuje tak zeby dzialalo, ale wedlug standardu - UB

	#endif

}