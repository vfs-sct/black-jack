#pragma once

#include <iostream>
#include <string>

#define LOG(X) std::cout << X
#define LOG_LN(X) std::cout << X << std::endl
#define EMPTY_LN std::cout << "" << std::endl
#define String std::string

#define INPUT(INPUT_TEXT, INPUT_VAR)\
do{\
	LOG(INPUT_TEXT, INPUT_VAR);\
	std::cin >> INPUT_VAR;\
	if(!std::cin.fail())\
	{\
		break;\
	}\
	std::cin.clear();\
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
	std::cerr << "Invalid Input. try again " << std::endl;\
}\
while(true);