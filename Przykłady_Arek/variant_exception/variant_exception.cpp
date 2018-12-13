#include <variant>
#include <iostream>
#include <stdexcept>

class ItsATrap
{
public:
	ItsATrap(bool problems = false) {
		if (problems == false)
			throw std::runtime_error("It's a trap!!!");
	} 

	operator int() {
		throw std::runtime_error("It's a trap again!!!");
	}

};

int main()
{
	std::variant<int, ItsATrap> ups;
	try 
	{
		ups.emplace<1>(ItsATrap());
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		std::cout << std::boolalpha << ups.valueless_by_exception() << std::endl;
		//std::cout << std::get<1>(ups) << std::endl; // nie bylo zmiany stanu
		std::cout << std::get<0>(ups) << std::endl;
	}


	ups = 5;

	try 
	{
		ups.emplace<0>(ItsATrap(true));

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		std::cout << std::boolalpha << ups.valueless_by_exception() << std::endl;
		std::cout << ups.index() << std::endl; // std::variant_npos
	}

	return 0;
}

/*
 std::variant_npos - inline constexpr std::size_t variant_npos = -1;
 					Specjalna wartosc rowna najwiekszej wartosci dla 
 					typu std::size_t. Uzywane jako wartosc zwracana przez
 					index(), gdy valueless_be_exception jest prawda
 std::variant::valueless_by_exception - funkcja zwracajaca flage oznaczajaca
 					ze variant nie posiada wartosci - osiagalne w bardzo 
 					krytycznych sytuacjach, oznacza ze cos zepsulismy
*/