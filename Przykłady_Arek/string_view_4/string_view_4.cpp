/**
 * Dwie nowe metody, których nie było w std::string- remove_prefix
 * oraz remove_suffix
 */

#include <string_view>
#include <iostream>

int main()
{
	std::string testString = "To jest napis testowy";
	std::string_view testSV(testString);

	std::cout << " -- Przed uzyciem metod -- " << std::endl; 
	std::cout << "testString = " << testString << std::endl;
	std::cout << "testSV = " << testSV << std::endl;

	std::cout << " -- Uzycie remove_prefix -- " << std::endl;

	// constexpr void remove_prefix(size_type n);
	testSV.remove_prefix(3);
	std::cout << "testString = " << testString << std::endl;
	std::cout << "testSV = " << testSV << std::endl;

	/**
	 * Jak widac oryginalny napis nie ulegl zmianie - bo jedyne co ta 
	 * metoda robi, to przesuwa początek widoku o n znakow - nie nastepuje
	 * tu zadna modyfikacja wskazywanych lancuchow
	 */

	std::cout << " -- Uzycie remove_suffix -- " << std::endl;

	// constexpr void remove_suffix(size_type n); 
	testSV.remove_suffix(2);
	std::cout << "testString = " << testString << std::endl;
	std::cout << "testSV = " << testSV << std::endl;

	/**
	 * Jak widac sytuacja jak powyzej
	 */

	return 0;
}