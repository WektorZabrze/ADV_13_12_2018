#include <iostream>
#include <map>

int main(){

	std::map<std::string, std::string> mapa;
	//auto result = mapa.insert_or_assign("klucz_1", 10, 'w');
	auto result = mapa.insert_or_assign("klucz_1", "wwwwwwwwww");
	auto result2 = mapa.insert_or_assign("klucz_2", "wwwww");
	auto result3 = mapa.insert_or_assign("klucz_1", "ww");

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