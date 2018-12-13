#include <iostream>
#include <map>

class Screamer{
public:
	Screamer(int i):i(i){
		std::cout<<"Screamer()"<<std::endl;
	}
	Screamer(Screamer&& to_move):i(to_move.i){
		std::cout<<"Move Screamer()"<<std::endl;
	}
	void print(){
		std::cout<<"Screamer("<<i<<")"<<std::endl;
	}
private:
	int i;
};

int main(){
	std::map<int, Screamer> mapa1;
	std::cout<<std::endl;
	mapa1.try_emplace(1, Screamer(1));
	std::cout<<std::endl;
	mapa1.try_emplace(1, Screamer(2));
	std::cout<<std::endl;
	mapa1.emplace(1, Screamer(3));

	std::cout<<std::endl;
	for(auto& item: mapa1){
		item.second.print();
	}

	std::map<std::string, std::string> mapa;
	auto result = mapa.try_emplace("klucz_1", 10, 'w');
	auto result2 = mapa.try_emplace("klucz_2", 5, 'w');
	auto result3 = mapa.try_emplace("klucz_1", 2, 'w');

	std::cout<<std::endl;
	for(auto& item : mapa){
		std::cout << "klucz: " << item.first << " wartosc: " << item.second << std::endl;
	}

	std::cout << std::endl << "result" << std::endl
	<< "Pierwszy element : " << (*result.first).first << " | " << (*result.first).second << std::endl
	<< "Drugi element : " << result.second << std::endl << std::endl
	<< "result2" << std::endl
	<< "Pierwszy element : " << (*result2.first).first << " | " << (*result2.first).second << std::endl
	<< "Drugi element : " << result2.second << std::endl << std::endl
	<< "result3" << std::endl
	<< "Pierwszy element : " << (*result3.first).first << " | " << (*result3.first).second << std::endl
	<< "Drugi element : " << result3.second << std::endl << std::endl;
}