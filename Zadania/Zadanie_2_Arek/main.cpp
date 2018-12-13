/**
 * Zadanie 2
 * Autor: Arkadiusz Kasprzak
 * Prostsze zadanie do poćwiczenia korzystania z nowych typów.
 * W zadaniu nie można w sposób bezpośredni korzystać z typów 
 * innych niż std::string_view, std::any i std::optional.
 * Proszę napisać funkcję wypiszBezSpacjiZPrzodu która wypisuje
 * przekazany napis z usuniętymi spacjami na początku. Nie wolno
 * używać pętli. 
 * Następnie proszę napisać szablon wypisujący obiekt przechowywany
 * w typie jakisTyp. Proszę pomyśleć czym jest jakisTyp.
 * Proszę również rozwiązać problem z literałem sv - jak skłonić go
 * do działania?
 * Proszę napisac funkcje funkcjaKtoraCzasemNieDziala ktora dziala 
 * w sposob podany w outpucie. Prosze uzyc typu poznanego w czasie
 * prezentacji.
 * Tego pliku nie wolno zmieniac. Oczekiwane wyjscie na dole pliku.
 */

#include "zadanie2.h"

int main()
{
	const char * napis = "     Tym napisem bedziemy sie bawic.  ";
	std::cout << "Usuniete spacje: " << std::endl;
	wypiszBezSpacjiZPrzodu(napis);
	std::cout << "A tu nie: " << std::endl;
	std::cout << napis << std::endl;

	jakisTyp jakisObiekt = 5;
	wypiszJakisObiekt<int>(jakisObiekt);
	jakisObiekt = "Napis"sv;
	wypiszJakisObiekt<std::string_view>(jakisObiekt);
	wypiszJakisObiekt<float>(jakisObiekt);

	std::cout << "__Tutaj__" << std::endl;
	auto dziala = funkcjaKtoraCzasemNieDziala(false);
	if (dziala) std::cout << *dziala << std::endl;
	auto nieDziala = funkcjaKtoraCzasemNieDziala(true);
	if (nieDziala) std::cout << *nieDziala << std::endl;

	return 0;
}

/*
Oczekiwane wyjście: 
Usuniete spacje:
Tym napisem bedziemy sie bawic.
A tu nie:
     Tym napisem bedziemy sie bawic.
5
Napis
Nie dziala :(
__Tutaj__
Dziala
*/