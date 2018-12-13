/*
 Przykład 2 ukazujący działanie std::variant.
 Ten przykład skupia się na sytuacjach, gdy może wystąpić błąd
*/

#include <variant>
#include <iostream>

class Test {
public:
	Test() = delete;
};

//#define ERROR1
//#define ERROR2
//#define ERROR3

int main()
{
	#ifdef ERROR1
		// static assertion failed: variant must have at least one
		// alternative
		std::variant<> brokenVariant;
	#endif

	#ifdef ERROR2
		// Nie można stworzyć instancji std::variant za pomocą 
		// konstruktora domyślnego jeśli pierwszy typ nie ma
		// takiego konstruktora
		std::variant<Test, double> brokenVariant2;
	#endif

	/// std::monostate - alternatywa dla pustego typu w std::variant
	/// - klasa pomocnicza. Pozwala stworzyć instancję std::variant za
	/// pomocą konstruktora bezargumentowego.
	std::variant <std::monostate, Test, double> workingVariant;
	std::cout << workingVariant.index() << std::endl; // indeks aktualnie
	// aktywnego typu

	#ifdef ERROR3
		std::variant<int, void> brokenVariant3; // błąd kompilacji - nie 
		// możemy mieć void w std::variant
	#endif

	std::variant<std::monostate> emptyVariant;

	return 0;
}