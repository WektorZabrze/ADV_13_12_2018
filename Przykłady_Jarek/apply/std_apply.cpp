#include <iostream>
#include <utility>
#include <experimental/array>
#include <functional>
 
int add(int first, int second, int third) { 
	return first + second + third; 
}
 
template<typename T>
T templated_add(T first, T second, T third) { 
	return first + second + third; 
}
 
auto pseudo_templated = [](auto first, auto second, auto third) {
	return first + second + third;
};
 
int main()
{
   // OK
   std::cout << std::apply(add, std::experimental::make_array(2, 3, 4)) << std::endl; 
 
   // OK
   std::cout << std::apply(pseudo_templated, std::experimental::make_array(2.5, 3.5, 4.5)) << std::endl; 

   // Nie zadziała ponieważ nie jest w stanie wydedukować poprawnie typów
   std::cout << std::apply(templated_add<double>, std::experimental::make_array(2.0, 3.0, 4.5)) << std::endl; 
}