#include <iostream>
#include <utility>
#include <map>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, std::map<T,U>& to_print){
	for(auto& item: to_print){
		os<<item.first<<" "<<item.second<<std::endl;
	}
	return os;
}

struct Screamer{
	Screamer(int i):i(i){};

	Screamer(const Screamer& to_cpy):i(to_cpy.i){
		std::cout<<"CPY Screamer"<<std::endl;
	}

	Screamer(Screamer&& to_move):i(to_move.i){
		std::cout<<"MV Screamer"<<std::endl;
	}

	Screamer& operator=(const Screamer& to_assign){
		i = to_assign.i;
		std::cout<<"CPYASN Screamer"<<std::endl;
		return *this;
	}

	Screamer& operator=(const Screamer&& to_move){
		i = to_move.i;
		std::cout<<"MVASN Screamer"<<std::endl;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Screamer& to_print){
		os<<"Screamer("<<to_print.i<<")";
		return os;
	}

	int i;
};

int main(){
	std::cout.setstate(std::ios_base::failbit);
	std::map mapa = { 
		{'a',Screamer(1)},
		std::pair{'b',Screamer(2)}, 
		{'c',Screamer(3)}, 
		{'d',Screamer(4)}, 
		{'e',Screamer(5)}, 
		{'f',Screamer(6)}
	};
	std::cout.clear();

	std::map<char, Screamer> mapa2;
	
	std::cout<<"mapa:\n"<<mapa<<std::endl;
	std::cout<<"mapa2:\n"<<mapa2<<std::endl;


	std::cout<<"Przeniesienie jednego \"node\" z mapa do mapa2"<<std::endl;
	{
		auto node_handler = mapa.extract('b');
		mapa2.insert(std::move(node_handler));
	}
	std::cout<<"mapa:\n"<<mapa<<std::endl;
	std::cout<<"mapa2:\n"<<mapa2<<std::endl;


	std::cout<<"Zmiana klucza jednego node w mapa bez realokacji"<<std::endl;
	{
		auto node_handler = mapa.extract('a');
		node_handler.key() = 'h';
		mapa.insert(std::move(node_handler));
	}
	std::cout<<"mapa:\n"<<mapa<<std::endl;
	std::cout<<"mapa2:\n"<<mapa2<<std::endl;


	std::cout<<"Przeniesienie wszystkich node z mapa do mapa2"<<std::endl;
	mapa2.merge(mapa);
	std::cout<<"mapa:\n"<<mapa<<std::endl;
	std::cout<<"mapa2:\n"<<mapa2<<std::endl;


	return 0;
}
