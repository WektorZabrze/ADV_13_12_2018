#pragma once

#include <any>
#include <string_view>
#include <iostream>
#include <optional>
#include <functional>
#include <regex>

using jakisTyp = std::any;
using namespace std::literals;

void wypiszBezSpacjiZPrzodu(std::string_view doWypisania) {
	doWypisania.remove_prefix(doWypisania.find_first_of("qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM"));
	std::cout << doWypisania << std::endl;
}

template<typename T>
void wypiszJakisObiekt(const jakisTyp& doWypisania){
	try{
		std::cout << std::any_cast<T>(doWypisania) <<std::endl;
	} catch(std::bad_any_cast& e){
		std::cout << "Nie dziala :(" << std::endl;
	}
}

std::optional<std::string_view> funkcjaKtoraCzasemNieDziala(bool val){
	if(val){
		return std::nullopt;
	}else{
		return "Dziala"sv;
	}
}