#include <iostream>
#include <functional>

template<typename T>
void add_args(const T& lhs,const T& rhs){
	std::cout<<"lhs ("<<lhs<<") + rhs("<<rhs<<") = " <<lhs+rhs<<std::endl;
}

template<typename T>
struct AddArgs{
	void operator()(const T& lhs, const T& rhs){
		std::cout<<"lhs ("<<lhs<<") + rhs("<<rhs<<") = " <<lhs+rhs<<std::endl;
	}
};

template<typename T>
struct Wrapper{
	T data;
};

struct Foo{
	void print_hello_world(int times){
		for(int i = 0; i < times; ++i)
				std::cout<<"Hello world!"<<std::endl;
	}
};

int main(){
	Wrapper<double> a {6.25};
	Foo b;
	//invoke dla funkcji szablonowej
	std::invoke(add_args<int>, 4, 5);
	//invoke dla szablonowego funktora
	std::invoke(AddArgs<double>(), 4.5, 4.6);
	//invoke dla metody klasy
	std::invoke(&Foo::print_hello_world, b, 4);
	//invoke dla pola klasy
	std::cout<<std::invoke(&Wrapper<double>::data, a)<<std::endl;
}