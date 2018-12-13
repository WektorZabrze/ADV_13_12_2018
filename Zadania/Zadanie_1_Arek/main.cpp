/**
 * Zadanie 1
 * Autor: Arkadiusz Kasprzak
 * Zadanie polega na zaimplementowaniu za pomocą std::variant prostej maszyny stanów.
 * Nasza maszyna opisywać będzie stan, w jakim w danym momencie znajduje się samochód.
 * Zakładamy, że może znajdować się on w danym momencie w jednym z trzech stanów - 
 * stać w miejscu, jechać do przodu lub jechać do tyłu. 
 * Pomiędzy tymi stanami możliwe są przejścia - reprezentowane za pomocą metod:
 * 	- startDrivingForward() - jeśli samochód stoi, to zaczyna jechać do przodu - 
 *		w innych przypadkach nie dzieje się nic.
 *	- startDrivingBackwards() - jeśli samochód stoi, to zaczyna jechać do tyłu - 
 * 		w innych przypadkach nie dzieje się nic.
 *	- stopDriving() - jeśli samochód jedzie do przodu lub do tyłu, to zatrzymuje się
 * W zadaniu należy zastosować std::variant. Nie wolno używać dziedziczenia.  
 * W pliku CarState.h znajduje się początek implementacji - należy na tej podstawie 
 * dokończyć kod.
 * Klasa CarState powinna zawierać metodę printCurrentState - korzysta ona z polimorfizmu
 * który daje std::variant to wypisania aktualnego stanu. Wskazówka - można użyć generic lambdy.
 * Pliki main.cpp nie wolno zmieniać. Oczekiwane wyjście z programu podano poniżej. 
 */

#include "CarState.h"

int main()
{
	CarState car;
	car.printCurrentState();
	car.startDrivingBackwards();
	car.printCurrentState();
	car.startDrivingForward();
	car.printCurrentState();
	car.stopDriving();
	car.printCurrentState();
	car.startDrivingForward();
	car.printCurrentState();
	car.startDrivingBackwards();
	car.stopDriving();
	car.printCurrentState();

	return 0;
}


/* 
OCZEKIWANE WYJŚCIE:
Car is not moving.
Car started driving backwards.
Car is driving backwards.
Car is driving backwards - must stop before driving forward.
Car is driving backwards.
Car stoped driving backwards. Now it is not moving.
Car is not moving.
Car started driving forward.
Car is driving forward.
Car is driving forward - must stop before driving backwards.
Car stoped driving forward. Now it is not moving.
Car is not moving.
*/