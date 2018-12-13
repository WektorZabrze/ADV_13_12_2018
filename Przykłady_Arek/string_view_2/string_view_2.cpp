#include <string_view>
#include <iostream>
#include <typeinfo>
#include <cassert>

//#define ERROR

int main()
{
	std::string_view stringViewExample("Przykladowy napis");

	// constexpr const_iterator begin() const noexcept;
	auto stringBegin = stringViewExample.begin();

	// constexpr const_iterator cbegin() const noexcept;
	auto stringConstBegin = stringViewExample.cbegin();

	/**
	 * Ważna obserwacja - begin() i cbegin() zwracają w tym przypadku
	 * iterator tego samego typu - w obu przypadkach jest const. Wynika
	 * to z faktu niemodyfikowalności danych za pośrednictwem string_view.
	 */

	for (auto it = stringBegin; it != stringViewExample.end(); ++it) {
		std::cout << *it;
	}
	std::cout << std::endl;

	#ifdef ERROR
		*stringBegin = 'a'; // assignment to read-only location
	#endif

	// Pokazuję, że wskazują na dokładnie to samo miejsce:
	assert(stringBegin == stringConstBegin);
	assert(*stringBegin == *stringConstBegin);

	std::cout << "Asercja pozwolila przejsc dalej" << std::endl;

	/**
	 * Na dokładnie takiej samej zasadzie działają iteratory 
	 * zwracane przez end() i cend()
	 */ 

	auto stringEnd = stringViewExample.end();
	auto stringConstEnd = stringViewExample.cend();

	std::cout << "Ostatni znak: " << stringConstEnd - 1 << std::endl;
	std::cout << "I to samo: " << stringEnd - 1 << std::endl;

	/**
	 * Oraz iteratory odwrotne (zwracane przez rbegin, rend itp.)
	 */

	std::cout << " -- ODWROCONE -- " << std::endl;
	for (auto it = stringViewExample.rbegin(); it != stringViewExample.rend(); ++it) {
		std::cout << *it;
	}
	std::cout << std::endl;

	/**
	 * Wniosek: Już tutaj widzimy różnicę pomiędzy std::string na std::string_view
	 * std::string_view jest widokiem na niemodyfikowalny łańcuch znakowy, co 
	 * sprawia, że musi udostępniać tylko stałe iteratory. 
	 */

}