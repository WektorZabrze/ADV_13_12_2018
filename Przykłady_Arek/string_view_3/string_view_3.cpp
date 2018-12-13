/**
 * Dostęp do elementów łańcucha za pomocą string_view
 */

#include <string_view>
#include <iostream>

// #define ERROR

int main()
{
	std::string_view exampleSV ("Kolejny przykladowy napis");

	// constexpr const_reference operator[](size_type pos) const;
	std::cout << "Pierwszy znak: " << exampleSV[0] << std::endl;

	for (unsigned i = 0; i < exampleSV.length(); ++i){
		std::cout << exampleSV[i];
	}
	std::cout << std::endl;

	#ifdef ERROR
		exampleSV[0] = 'k'; // error: assignment of read-only location
	#endif

	/**
	 * Podobnie jak dla std::string - brak sprawdzania zakresu używając [] - 
	 * zakres jest sprawdzany tylko, gdy używany metody at
	 */

	// constexpr const_reference at(size_type pos) const;
	std::cout << "Metoda at: " << exampleSV.at(10) << std::endl;

	// front i back - stala referencja do pierwszego i ostatniego znaku
	// przechowywanego łancucha
	std::cout << exampleSV.front() << std::endl;
	std::cout << exampleSV.back() << std::endl;

	// Stały wskaznik na tablicę znaków
	std::cout << exampleSV.data() << std::endl;

	// Największa możliwa ilość znaków, do których można się odwoływać
	// za pomocą std::string_view
	std::cout << exampleSV.max_size() << std::endl;

	std::string_view emptyExample;
	if (emptyExample.empty()) {
		std::cout << "string_view jest pusty" << std::endl;
	}

	return 0;
}