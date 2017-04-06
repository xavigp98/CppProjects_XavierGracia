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
	std::map<std::string, int>ranking1;
	std::vector<jugador>ranking2;
	
	ranking1["Pedro"] = 35;
	ranking1["Raul"] = 40;
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
			std::cout << "Introduce tu puntuacion" << std::endl;
			std::cin >> p;
			ranking1[nom] = p;
		}
	}
	int* personas = new int[ranking1.size()];

	for (int i = 0; i < ranking1.size(); i++)
		personas[i] = ranking1.begin()++->second;

	for (int i = 0; i < ranking1.size(); i++) {
		for (int j = 0;j < ranking1.size()-1; j++){
			if (personas[j] < personas[j + 1]) {
				int tmp = personas[j + 1];
				personas[j + 1] = personas[j];
				personas[j] = tmp;
			}
		}
	}

	ranking2.push_back({ "Pedro", 35 });
	ranking2.push_back({ "Raul", 40 });
	ranking2.push_back({ "Joan", 22 });
	ranking2.push_back({ "XaviO", 10 });

	/*system("CLS");
	std::cout << "Introduce tu puntuacion" << std::endl;
	std::cin >> p;

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
			ranking1[nom] = p;
		}
	}*/

	return 0;
}