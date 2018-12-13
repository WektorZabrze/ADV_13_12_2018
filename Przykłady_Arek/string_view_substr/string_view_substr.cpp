#include <string>
#include <string_view>
#include <iostream>
#include <chrono>

int main()
{
	std::string testString = "Testowy napis";
	auto substring = testString.substr(1, 4);

	std::cout << " -- Przed modyfikacja -- " << std::endl;  
	std::cout << testString << std::endl;
	std::cout << substring << std::endl;
	substring[1] = 'x';

	std::cout << " -- Po modyfikacji -- " << std::endl;
	std::cout << testString << std::endl;
	std::cout << substring << std::endl;	

	/**
	 * Wniosek - pierwotny napis sie nie zmienil - zostal wiec wykonana
	 * kopia poprzedniego
	 */

	std::string_view testSV = "Testowy napis 2";
	auto testViewSub = testSV.substr(1, 5);
	std::cout << std::boolalpha << (&testSV[1] == &testViewSub[0]) << std::endl;

	/**
	 * Te same adresy - brak kopiowania - znaczy wzrost wydajnosci (zlozonosc
	 * spada z linowej do stalej) - bo substr zwraca nowe string_view, gdzie 
	 * zmieniony jest tylko wskaznik na poczatek i wielkosc
	 */

	// Maly benchmark
	std::cout << "-- Dla std::string -- " << std::endl;
	auto start = std::chrono::steady_clock::now();
	std::string test ("Napis");
	for (int i = 0; i <= 1'000'000'0; ++i) {
		test.substr(1, 2);
	}
	auto end = std::chrono::steady_clock::now();
	auto difference = end - start;

	std::cout << std::chrono::duration <double, std::milli> (difference).count() 
		<< " ms" << std::endl;


	std::cout << "-- Dla std::string_view -- " << std::endl;
	start = std::chrono::steady_clock::now();
	std::string_view test2 ("Napis");
	for (int i = 0; i <= 1'000'000'0; ++i) {
		test2.substr(1, 2);
	}
	end = std::chrono::steady_clock::now();
	difference = end - start;

	std::cout << std::chrono::duration <double, std::milli> (difference).count() 
		<< " ms" << std::endl;

 	/* 
 	 * Mozna poeksperymentowac z rozmiarem substringa - dla std::string powinien
 	 * byc wplyw, a dla string_view - zaden
 	 */

	return 0;
}