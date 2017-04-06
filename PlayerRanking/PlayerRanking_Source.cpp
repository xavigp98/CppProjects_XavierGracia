#include <map>
#include <vector>
#include <iostream>
#include <string>

struct jugador
{
	std::string nombre;
	int puntuacion;
};

int main() {
	std::string decision;

	std::cout << "Quieres usar un map o un vector ?" << std::endl;
	std::cin >> decision;


	std::map<std::string, int>ranking1;
	std::vector<jugador>ranking2;
	
	if (decision == "map" || decision == "Map") {

		ranking1["Pedro"] = 35;
		ranking1["Raul"] = 78;
		ranking1["Joan"] = 22;
		ranking1["XaviO"] = 10;

		int c = 0;
		int p = 0;
		bool igual;
		std::string nom;

		while (c != 1) {
			igual = false;
			system("CLS");
			std::cout << "Introduce tu nombre de jugador:" << std::endl;
			std::cin >> nom;
			for (auto i = ranking1.begin(); i != ranking1.end(); i++) {
				if (i->first == nom) {
					igual = true;
				}
			}

			if (!igual) {
				c = 1;
				system("CLS");
				std::cout << "Introduce tu puntuacion:" << std::endl;
				std::cin >> p;
				ranking1[nom] = p;
			}
		}
		int* personas = new int[ranking1.size()];

		int cont = 0;

		for (auto it = ranking1.begin(); it != ranking1.end(); it++) {
			personas[cont] = it->second;
			cont++;
		}

		for (int i = 0; i < ranking1.size(); i++) {
			for (int j = 0;j < ranking1.size() - 1; j++) {
				if (personas[j] < personas[j + 1]) {
					int tmp = personas[j + 1];
					personas[j + 1] = personas[j];
					personas[j] = tmp;
				}
			}
		}

		system("CLS");

		for (int i = 0; i < ranking1.size(); i++) {
			std::cout << " Puntuacion: " << personas[i];
			for (auto it = ranking1.begin(); it != ranking1.end(); it++) {
				if (it->second == personas[i])
					std::cout << "	Nombre: " << it->first << std::endl;
			}
		}
	}

	else if (decision == "Vector" || decision == "vector") {

		ranking2.push_back({ "Pedro", 35 });
		ranking2.push_back({ "Raul", 40 });
		ranking2.push_back({ "Joan", 22 });
		ranking2.push_back({ "XaviO", 10 });

		int c = 0;
		bool igual;
		std::string nom;
		int p;
		int cont = 0;

		while (c != 1) {
			igual = false;
			system("CLS");
			std::cout << "Introduce tu nombre de jugador:" << std::endl;
			std::cin >> nom;
			for (auto i = ranking2.begin(); i != ranking2.end(); i++) {
				if (i->nombre == nom) {
					igual = true;
				}
			}

			if (!igual) {
				c = 1;
				system("CLS");
				std::cout << "Introduce tu puntuacion:" << std::endl;
				std::cin >> p;
				ranking2.push_back({ nom, p });
			}
		}

		int* personas2 = new int[ranking2.size()];

		for (auto it = ranking2.begin(); it != ranking2.end(); it++) {
			personas2[cont] = it->puntuacion;
			cont++;
		}

		for (int i = 0; i < ranking2.size(); i++) {
			for (int j = 0;j < ranking2.size() - 1; j++) {
				if (personas2[j] < personas2[j + 1]) {
					int tmp = personas2[j + 1];
					personas2[j + 1] = personas2[j];
					personas2[j] = tmp;
				}
			}
		}

		system("CLS");

		for (int i = 0; i < ranking2.size(); i++) {
			std::cout << " Puntuacion: " << personas2[i];
			for (auto it = ranking2.begin(); it != ranking2.end(); it++) {
				if (it->puntuacion == personas2[i])
					std::cout << "	Nombre: " << it->nombre << std::endl;
			}
		}
	}

	return 0;
}