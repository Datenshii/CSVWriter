#pragma once

#include <string>

struct Island {
	std::string name = "";
	int width = 0;
	int height = 0;
};

int AskData(Island &island);
int CreateCSV(Island &island);
