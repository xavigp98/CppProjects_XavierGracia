#include <vector>
#include <string>
#include <iostream>
#include <time.h>


struct persona {
	std::string nom;
	int dia;
	int mes;
	int año;
};

std::vector<int> AddVectors(std::vector<int>&a, std::vector<int>&b) {
	if (a.size() != b.size()) { return; }

	else {
		std::vector<int>salida(a.size());
		for (int i = 0; i < a.size(); i++) {
			salida[i] = a[i] + b[i];
		}
		return salida;
	}
}

void ConcatVectors(std::vector<int>&a, std::vector<int>&b){
	a.insert(std::end(a), std::begin(b), std::end(b));
}

void ShiftRight(std::vector<int>&a) {
	a.insert(std::begin(a), rand());
	a.pop_back();
}

void RotateLeft(std::vector<int>&a) {
	int current, previous{ a.back() };

	for (auto & i : a) {
		current = i;
		i = previous;
		previous = current;
	}
}

void SearchAdjacent(std::vector<int>&a) {
	for (int i = 0; i < a.size() - 2; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
			a.erase(std::begin(a)+i, std::begin(a)+i+2);
			a.push_back(rand());
			a.push_back(rand());
			a.push_back(rand());
		}
	}
}

int main() {
	srand(time(nullptr));

	std::vector<int>v1(5);
	std::vector<int>v2(10, 0);
	std::vector<int>v3({ 10,9,8,7,6,5,4,3,2,1 });
	std::vector<std::string>v4({ "Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia" });
	std::vector<int>v5(v3);


	std::vector<persona>v6{
		{ v4[rand() % 6],rand() % 32,rand() % 13,1920 + (rand() % 1001) } ,
		{ v4[rand() % 6],rand() % 32,rand() % 13,1920 + (rand() % 1001) } ,
		{ v4[rand() % 6],rand() % 32,rand() % 13,1920 + (rand() % 1001) } };



	return 0;
}