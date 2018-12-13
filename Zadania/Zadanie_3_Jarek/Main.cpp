#include <iostream>
#include "spliceable_map.h"

/* Celem zadania jest zaimplementowanie klasy spliceable_map, tak aby wynik działania programu był analogiczny do podanego na końcu.
zaimplementowany przez nas splice ma przypominać splice zaimplementowany w klasie std::list, 
czyli ma pozwalać na splice całej mapy, jednego obiektu w mapie oraz zakresu z mapy.
W przypadku  zaimplementowanego przez nas splice'a pomijamy wskazywanie miejsca w którym elementy mają być wstawione 
(pozwalamy mapie samej wybrać miejsce do wstawienia tych elementów)
poza tym należy zaimplementować metodę resolve_result, która pozwoli nam na wyświetlenie odpowiedniego komunikatu, 
czy try_emplace się powiódł czy też nie.
Plik Main.cpp można edytować w wyznaczonym miejscu (uzupełnij)
*/

template<typename T, typename T2>
void resolve_result(std::pair<T,T2>& result){
	/* uzupelnij */
}

int main(){
	int val = 5;

	std::map<int, int> mapa = {
		{1,1},
		{2,2},
		{3,3}
	};

	std::map<int, int> mapa2 = {
		{4,4},
	};

	spliceable_map s_mapa(mapa);
	spliceable_map<int, int> s_mapa2(mapa2);

	auto result = s_mapa2.try_emplace(val,val);
	auto result2 = s_mapa2.try_emplace(6,6);
	auto result3 = s_mapa2.try_emplace(6,7);

	resolve_result(result);
	resolve_result(result2);
	resolve_result(result3);

	std::cout<<"-------------------------"<<std::endl;
	std::cout<<"s_mapa\n"<<s_mapa<<std::endl;
	std::cout<<"s_mapa2\n"<<s_mapa2<<std::endl;
	std::cout<<"-------------------------"<<std::endl;
	s_mapa.splice(s_mapa2);
	std::cout<<"s_mapa\n"<<s_mapa<<std::endl;
	std::cout<<"s_mapa2\n"<<s_mapa2<<std::endl;
	std::cout<<"-------------------------"<<std::endl;
	s_mapa2.splice(s_mapa, ++s_mapa.begin());
	std::cout<<"s_mapa\n"<<s_mapa<<std::endl;
	std::cout<<"s_mapa2\n"<<s_mapa2<<std::endl;
	std::cout<<"-------------------------"<<std::endl;
	s_mapa2.splice(s_mapa, s_mapa.begin(), --s_mapa.end());
	std::cout<<"s_mapa\n"<<s_mapa<<std::endl;
	std::cout<<"s_mapa2\n"<<s_mapa2<<std::endl;
	std::cout<<"-------------------------"<<std::endl;
	return 0;
}

/* Wynik działania programu:
Wynik działania try_emplace
5  5  Element został dodany
Wynik działania try_emplace
6  6  Element został dodany
Wynik działania try_emplace
6  6  Element nie został dodany
-------------------------
s_mapa
1  1
2  2
3  3

s_mapa2
4  4
5  5
6  6

-------------------------
s_mapa
1  1
2  2
3  3
4  4
5  5
6  6

s_mapa2

-------------------------
s_mapa
1  1
3  3
4  4
5  5
6  6

s_mapa2
2  2

-------------------------
s_mapa
6  6

s_mapa2
1  1
2  2
3  3
4  4
5  5

-------------------------
*/