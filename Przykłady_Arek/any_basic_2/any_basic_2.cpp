/**
 * Autor: Arkadiusz Kasprzak
 * Opis: Przykład stanowiący wstęp do std::any. Pokazuje podstawowy sposób
 * użycia - przypisywanie nowych wartości, próba odzyskiwania przechowywanej
 * wartości, resetowanie itp.
 */

#include <any>
#include <iostream>
#include <string>

int main()
{
	std::any testContainer {1024};

	try
	{
		int value = std::any_cast<int>(testContainer);
		std::cout << value << std::endl;

		// Ponizej rzuca bad_any_cast - nie zachodzi konwersja, 
		// pomimo, ze by mogla
		float valueF = std::any_cast<float>(testContainer);
		std::cout << valueF << std::endl; 
	}
	catch (const std::bad_any_cast& except) {
		std::cout << except.what() << std::endl;
	}

	// Wykunujemy reset na obiekcie any - od tej pory nie przechowuje 
	// on juz wartosci.
	testContainer.reset();

	try 
	{
		// rzuca wyjatek, bo zrobilismy reset
		int value = std::any_cast<int>(testContainer);
		std::cout << value << std::endl;
	}
	catch(const std::bad_any_cast& except) {
		std::cout << except.what() << std::endl;
	}


	// Testujemy, czy any przechowuje jakas wartosc - nie powinno, bo
	// uzywany byl reset.
	if (testContainer.has_value()) {
		std::cout << "Mamy wartosc" << std::endl;
	}
	else {
		std::cout << "Nie mamy wartosci" << std::endl;
	}

	testContainer = 15.5;
	testContainer = std::string("Tak tez sie da"); // prawie jak python/ dynamiczne typowanie

	try 
	{
		// zwykla referencja nie pojdzie, blad kompilacji bo musi byc const
		// (bo zwraca r-value)
		const std::string& value = std::any_cast<std::string>(testContainer);
		std::cout << value << std::endl;
	}
	catch (const std::bad_any_cast& except) {
		std::cout << except.what() << std::endl;
	}

	// Dostep do typu za pomoca .type - mechanizm RTTI. 
	if (testContainer.type() == typeid(std::string))
		std::cout << "Przechowujemy string" << std::endl;

	// Dostep do nazwy typu za pomoca name()
	std::cout << "Typ: " << testContainer.type().name() << std::endl;

	return 0;
}