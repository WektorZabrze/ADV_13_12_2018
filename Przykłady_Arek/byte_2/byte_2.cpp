/**
 * Przykład 2
 * Autor: Arkadiusz Kasprzak
 * Przykład obrazuje trochę bardziej nietypowe zastosowanie 
 * std::byte - do reprezentacji obiektu jako sekwencji bajtów
 * i modyfikacji w ten sposób tego obiektu. 
 */

#include <cstddef>
#include <iostream>

// Object representation
// Dla danego typu T object representation to sekwencja sizeof(T) 
// unsigned char-ow (a dla nas, jako ze jestesmy w C++17 - std::byte)
// zaczynajaca sie na tym samym adresie co obiekt typu T

struct Simple {
	int a;
	char b;
};

class SimplePrivate
{
public:
	SimplePrivate(char x, char y) : m_x(x), m_y(y) {}

	void print() const {
		std::cout << m_x << m_y << std::endl;
	}

private:
	char m_x;
	char m_y;
};

int main()
{
	Simple test = {1, 'a'};
	std::cout << test.a << " " << test.b << std::endl;

	// Rzutujemy wskaznik typu Simple na wskaznik na std::byte
	// Dzieki temu mozemy indeksowac jak tablice std::byte
	reinterpret_cast<std::byte*>(&test)[4] = std::byte('b');

	std::cout << test.b << std::endl;	

	// Dostęp do składowej prywatnej
	SimplePrivate test2 ('a', 'z');
	test2.print();

	reinterpret_cast<std::byte*>(&test2)[0] = std::byte('x');
	reinterpret_cast<std::byte*>(&test2)[1] = std::byte('d');

	test2.print();

	// To sie oczywiście dało zrobić wcześniej, natomiast teraz
	// jest to czytelniejsze. 

	return 0;
}