/*
 Drugi przyklad obrazujacy dzialanie unii znanych ze starych standardow 
 jezyka. Ukazuje kolejne problemy wynikajace z ich bezposredniego uzycia.
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

//#define ERROR1
//#define ERROR2

union BrokenUnion
{
	std::string data_1;
	std::vector<int> data_2;
	~BrokenUnion() {} // jako ze unia zawiera pola ktora maja nietrywialne 
	// konstruktory, to domyslnie jej destruktor jest ustawiony na = delete
};

int main()
{
	#ifdef ERROR1
		BrokenUnion brokenExample; // domyslny konstruktor = delete, 
		// bo nietrywialny w polu std::string
	#endif

	BrokenUnion test = {"Jakis tekst"};

	#ifdef ERROR2
		test.data_2 = std::vector<int> {1, 2, 3 }; // segfault, bo nie bylo konstruktora
	#endif

	std::cout << test.data_1 << std::endl;

	// Zeby zadzialalo trzeba zrobic tak:
	test.data_1.~basic_string(); // jawnie wywolujemy destruktor
	new (&test.data_2) std::vector<int> {1, 2 ,3}; // uzywamy placement new
	test.data_2.push_back(4);
	std::for_each(test.data_2.begin(), test.data_2.end(), [] (
		int elem) { std::cout << elem << " "; } );
	std::cout << std::endl;

	test.data_2.~vector(); // bez tego wyciek pamieci !!!

	// Powyzszy schemat nie jest raczej oczywisty i zdecydowanie nie kazdy
	// o tym wie - przez co uzywanie klasycznych unii staje sie troche
	// niebezpieczne - nie mamy gwarancji ze ktos z zewnatrz czegos nie 
	// zepsuje. 
}