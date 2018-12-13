#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>
#include <execution>

int main(){
	std::vector<long long int> dane(1e8, 1);
	{
		std::cout<<"Dla wykonania sekwencyjnego"<<std::endl;
		auto czas_start = std::chrono::high_resolution_clock::now();
		double wynik = std::reduce(dane.begin(), dane.end());
		auto czas_koniec = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli>czas_wykonania = czas_koniec - czas_start;
		std::cout << "Otrzymano wynik: " << wynik << " W czasie: " << czas_wykonania.count() << std::endl;
	}
	{
		std::cout<<"Dla wykonania zrównoleglonego"<<std::endl;
		auto czas_start = std::chrono::high_resolution_clock::now();
		double wynik = std::reduce(std::execution::par, dane.begin(), dane.end());
		auto czas_koniec = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli>czas_wykonania = czas_koniec - czas_start;
		std::cout << "Otrzymano wynik: " << wynik << " W czasie: " << czas_wykonania.count() << std::endl;
	}
	{
		std::cout<<"Dla wykonania zrównoleglonego i zwektoryzowanego"<<std::endl;
		auto czas_start = std::chrono::high_resolution_clock::now();
		double wynik = std::reduce(std::execution::par_unseq, dane.begin(), dane.end());
		auto czas_koniec = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli>czas_wykonania = czas_koniec - czas_start;
		std::cout << "Otrzymano wynik: " << wynik << " W czasie: " << czas_wykonania.count() << std::endl;
	}
}