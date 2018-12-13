#include <iostream>
#include <tuple>

struct Loud{
	Loud(int a, int b, char c, std::string d, bool e){
		std::cout<<"Do konstruktora przekazano"<<std::endl
		<<"a: "<<a<<std::endl
		<<"b: "<<b<<std::endl
		<<"c: "<<c<<std::endl
		<<"d: "<<d<<std::endl
		<<std::boolalpha <<"e: "<<e<<std::endl;
	}

	void print(){
		std::cout<<"Obiekt typu Loud"<<std::endl;
	}
};

using namespace std::string_literals;

int main(){
	std::tuple a { 1,2,'c', "witam"s, true};

	std::cout<<"make_from_tuple<Loud>:"<<std::endl;
	auto obiekt = std::make_from_tuple<Loud>(a);

	std::cout<<std::endl<<"obiekt.print():"<<std::endl;
	obiekt.print();
}