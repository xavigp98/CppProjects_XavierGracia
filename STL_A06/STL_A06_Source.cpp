#include <vector>
#include <string>
#include <time.h>

struct persona
{
	std::string nom;
	int dia;
	int mes;
	int año;
};

std::vector<int> AddVectors(std::vector<int>&input1, std::vector<int>&input2) {
	if (input1.size() != input2.size()) {

	}
	else {
		std::vector<int>output;
		for (int i = 0; i < input1.size();i++) {
			output.push_back(input1[i]+ input2[i]);
		}
		return output;
	}
}

void ConcatVectors(std::vector<int>&input1, std::vector<int>&input2) {
	for (int i = 0; i < input2.size(); i++)
		input1.push_back(input2[i]);
}

void ShiftRight(std::vector<int>&input) {
	srand(time(nullptr));
	input.insert(input.begin(), rand());
	input.pop_back();
}

void RotateLeft(std::vector<int>&input) {
	int last = input[0];
	for (int i = 0; i < input.size()-1; i++) {
		input[i] = input[i + 1];
	}
	input.back() = last;
}

void SearchAdjacent(std::vector<int>&input) {
	for (int i = 0; i < input.size() - 2; i++) {
		if (input[i] == input[i + 1] && input[i + 1] == input[i + 2]) {
			input.erase(input.begin()+i, input.begin()+i+2);
			input.push_back(rand());
			input.push_back(rand());
			input.push_back(rand());
		}
	}
}

int main() {
	std::vector<int> v1{5};
	std::vector<int> v2{ 10, 0 };
	std::vector<int> v3{{ 10,9,8,7,6,5,4,3,2,1 }};
	std::vector<std::string> v4{ { "Gertrudiz", "Pancracia", "Anacleto", "Hipolito", "Eustaquio", "Fulgencia" } };
	std::vector<int> v5{ v3 };
	std::vector<persona> v6{ { v4[rand() % 6],1 + rand() % 31, 1 + rand() % 12, 1920 + rand() % 1001 }, { v4[rand() % 6],1 + rand() % 31, 1 + rand() % 12, 1920 + rand() % 1001 }, { v4[rand() % 6],1 + rand() % 31, 1 + rand() % 12, 1920 + rand() % 1001 } };
	return 0;
}