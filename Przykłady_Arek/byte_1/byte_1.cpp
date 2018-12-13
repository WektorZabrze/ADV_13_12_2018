/**
 * Przykład 1
 * Autor: Arkadiusz Kasprzak
 * Przykład obrazuje podstawowe operacje na std::byte, takie jak:
 * inicjalizacja za pomocą typu całkowitego, konwersja do typu 
 * całkowitego (za pomocą std::to_integer<T>()), oraz operacje 
 * bitowe. Odkomentowanie linii z ERROR ukazuje jeden z możliwych
 * błędów kompilacji - gdy próbujemy niejawnie przekonwertować 
 * int na std::byte. 
 */

#include <cstddef> // std::byte
#include <iostream>

//#define ERROR

int main()
{

	std::cout << " -- Tworzenie i konwersja na wartość całkowitą -- " << std::endl; 

	// std::byte może zostać zainicjalizowany za pomocą typu całkowitego
	// (np. int) -  i to jest jedyny moment w którym mozna tak zrobić
	std::byte x {10};

	#ifdef ERROR
		x = 5; // error:  cannot convert ‘int’ to ‘std::byte’ in assignment
	#endif

	// Od tej pory mozna tylko tak:
	x = std::byte{15}; // Wynika to z faktu wprowadzenia nowych zasad dla inicjalizacji
	// enum classes, ale nie chce tutaj sie na tym skupiac

	x = (std::byte)20; // tak tez mozna, wazne ze nie mozna przypisac samego inta - trzeba
	// zrzutowac w sposob jawny

	std::byte testByte {0b0001}; // mozna tez uzyc binary literals - moznaby tez np char - wazne 
	// by nie robic tego niejawnie

	// std::to_integer konwertuje na dowolny typ calkowity (podajemy go jako argument szablonu)
	std::cout << std::to_integer<int> (testByte) << std::endl;
	std::cout << std::to_integer<int> (x) << std::endl;

	// Dzialaja rozne operacje bitowe - przesuniecia, negacje, sumy i iloczyny
	std::cout << " -- Operatory bitowe -- " << std::endl;


	testByte = testByte << 1; // testByte <<= 1;
	std::cout << std::to_integer<int> (testByte) << std::endl;	

	testByte = testByte >> 1;
	std::cout << std::to_integer<int> (testByte) << std::endl;

	testByte = ~testByte;
	std::cout << std::to_integer<int> (testByte) << std::endl;

	std::byte secondToTest {0b0100};
	testByte = testByte & secondToTest;
	std::cout << std::to_integer<int> (testByte) << std::endl;

	std::byte lhs {1};
	std::byte rhs {2};
	std::byte result = lhs | rhs;

	std::cout << std::to_integer<int> (result) << std::endl;

	std::cout << " -- Operator przypisania -- " << std::endl;
	std::cout << "Lhs: " << std::to_integer<int>(lhs) << std::endl;
	std::cout << "Rhs: " << std::to_integer<int>(rhs) << std::endl;
	// Wspierane przypisanie
	lhs = rhs;

	std::cout << "Po przypisaniu - lhs: " << std::to_integer<int> (lhs) << std::endl;
}