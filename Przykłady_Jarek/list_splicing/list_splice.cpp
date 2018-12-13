#include <iostream>
#include <list>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& list){
	for(auto& item: list){
		os<< item << " ";
	}
	return os;
}

int main(){
	std::cout<<std::endl<<"Wartosci poczatkowe"<<std::endl;
	std::list<char> list1 = { 'a', 'b', 'c', 'd', 'e', 'f'};
	std::list<char> list2 = { '1', '2', '3', '4'};

	std::cout<<"list1: "<<list1<<std::endl;
	std::cout<<"list2: "<<list2<<std::endl;

	std::cout<<std::endl<<"Wyciagamy jeden element z list1"<<std::endl;
	auto it = list1.begin();
	advance(it, 3);
	list1.splice(++(++list2.begin()), list1, it);

	std::cout<<"list1: "<<list1<<std::endl;
	std::cout<<"list2: "<<list2<<std::endl;

	std::cout<<std::endl<<"Wyciagamy zakres z list1"<<std::endl;
	auto it2 = list1.end();
	it = list1.begin();
	advance(it, 2);
	list1.splice(list2.begin(), list1, it, it2);


	std::cout<<"list1: "<<list1<<std::endl;
	std::cout<<"list2: "<<list2<<std::endl;

	std::cout<<std::endl<<"Przenosimy calosc z list2 do list1"<<std::endl;
	list2.splice(list1.end(), list2);

	std::cout<<"list1: "<<list1<<std::endl;
	std::cout<<"list2: "<<list2<<std::endl;

	return 0;
}