#pragma once
#include <vector>
#include <iostream>

class ElementsPlayer
{
private:
	std::vector<std::string> PlayerElements;

public:
	ElementsPlayer();
	~ElementsPlayer();
	std::string PlayerInput();
	void ManageInput(std::string input);
	void PrintElements();
};

