#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include "ElementsPlayer.h"

template<>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> & p) const {
		return ((hash<std::string>()(p.first) ^ (hash<std::string>()(p.second) << 1) >> 1));
	}
};

int main() {

	
	std::ifstream fentrada("elements.dat");
	std::unordered_map<std::pair<std::string, std::string>, std::string> combinaciones;
	std::string linea;
	

	while (!fentrada.eof()) {
		getline(fentrada,linea);

		int igual = linea.find("=");
		std::string primero = linea.substr(0,igual - 1);
		std::string segundo = linea.substr(igual + 2);
		int mas = segundo.find("+");
		std::string k1 = segundo.substr(0,mas-1);
		std::string k2 = segundo.substr(mas + 2);

		combinaciones.insert({ {{k1},{k2}},{primero} });
	}
	bool partida = true;

	std::string input;

	ElementsPlayer el;

	while (partida == true) {
		el.PrintElements();
		input = el.PlayerInput();
		el.ManageInput(input);
	}
	

	return 0;
}