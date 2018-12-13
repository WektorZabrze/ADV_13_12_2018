#include <iostream>
#include <any>
#include <vector>
#include <typeinfo>
#include <string>

using namespace std::literals::string_literals;

int main()
{
	std::vector<std::any> testVector = {5.5, "Przykladowy napis"s, 1};

	// Oczywiscie powyzsze w zaden sposob nie zastapi nam kontenerow
	// stworzonych specjalnie do przechowywania kolekcji o roznych typach,
	// np std::tuple. 
	// Ponizej przyklad dlaczego - zeby wyciagnac wartosc, nalezy sprawdzic
	// za pomoca if-ow typ - co ogranicza nasze opcje i znacznie wydluza kod

	std::cout << " -- PIERWSZA PROBA -- " << std::endl;
	try 
	{
		for (auto& elem : testVector) {
			std::cout << std::any_cast<double>(elem)  << std::endl; // wszystko ok, dopoki wartosc jest doublem
			// jak nie jest, to rzuca wyjatek.
		}
	}	
	catch (const std::bad_any_cast& except) {
		std::cout << except.what() << std::endl;
	}

	std::cout << " -- DRUGA PROBA -- " << std::endl;
	try 
	{
		for (auto& elem : testVector) 
		{
			// konstrukcja zlozona z if-ow !!!
			if (elem.type() == typeid(double)) {
				std::cout << std::any_cast<double>(elem) << std::endl;
			}
			else if (elem.type() == typeid(std::string)) {
				std::cout << std::any_cast<std::string>(elem) << std::endl;
			}
			else if (elem.type() == typeid(int)) {
				std::cout << std::any_cast<int>(elem) << std::endl;
			}
		}
	}
	catch(const std::bad_any_cast& except){
		std::cout << except.what() << std::endl;
	}

	return 0;
}