#include <iostream>
#include <map>

int main(){
	std::map <int, std::string> mapa;
	mapa.insert(std::make_pair(1, "jeden"));
	mapa.insert(std::make_pair(2, "dwa"));
	mapa.insert(std::make_pair(3, "trzy"));
	mapa.insert(std::make_pair(4, "cztery"));
	mapa.insert(std::make_pair(5, "pięć"));

	auto it = mapa.lower_bound(6);

	if(it != mapa.end() && it->first == 6){

	} else{
		mapa.try_emplace(it, 6, "sześć");
	}

	for(auto& item : mapa){
		std::cout<<item.first <<"   "<< item.second<<std::endl;
	}
}