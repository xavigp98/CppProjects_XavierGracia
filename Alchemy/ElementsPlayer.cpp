#include "ElementsPlayer.h"
#include <iostream>
#include <string>
#include <Windows.h>



ElementsPlayer::ElementsPlayer()
{
	ElementsPlayer::PlayerElements = { {"Aire"},{"Fuego"},{"Tierra"},{"Agua"} };
}

ElementsPlayer::~ElementsPlayer()
{

}


std::string ElementsPlayer::PlayerInput()
{
	std::string input;
	getline(std::cin, input);
	return input;
}

void ElementsPlayer::ManageInput(std::string input)
{
	
	int espacio = input.find(" ");

	std::string segunda = input.substr(espacio + 1);

	if (input.find("add basics") != std::string::npos) {
		
			ElementsPlayer::PlayerElements.push_back("Aire");
			ElementsPlayer::PlayerElements.push_back("Fuego");
			ElementsPlayer::PlayerElements.push_back("Tierra");
			ElementsPlayer::PlayerElements.push_back("Agua");
	}
	else if(input.find("add")!=std::string::npos) {
			if ((stoi(segunda)-1) < ElementsPlayer::PlayerElements.size()) {
				ElementsPlayer::PlayerElements.push_back(ElementsPlayer::PlayerElements[stoi(segunda) - 1]);
			}
	}


	else if (input.find("delete") != std::string::npos) {
		if ((stoi(segunda) - 1) < ElementsPlayer::PlayerElements.size()) {
			ElementsPlayer::PlayerElements.erase(ElementsPlayer::PlayerElements.begin() + stoi(segunda) - 1);
		}
	}

	else if (input.find("info") != std::string::npos) {
		std::string url = "https://es.wikipedia.org/wiki/";
		if ((stoi(segunda) - 1) < ElementsPlayer::PlayerElements.size()) {
			ShellExecuteA(nullptr, "open", (url + ElementsPlayer::PlayerElements[stoi(segunda) - 1]).c_str(), nullptr, nullptr, SW_SHOWNORMAL);
		}
	}

}

void ElementsPlayer::PrintElements()
{
	system("CLS");
	for (int i = 0; i < ElementsPlayer::PlayerElements.size(); i++) {
		std::cout << i+1 << ": " << ElementsPlayer::PlayerElements[i] << std::endl;
	}
}
