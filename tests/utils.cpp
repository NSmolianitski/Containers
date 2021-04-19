//
// Created by Parfait Kentaurus on 4/19/21.
//

#include <iostream>

#define RED	"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BOLD	"\033[3m"

#define CLR	"\033[0m"

void printSuccess()
{
	std::cout << GREEN BOLD "OK" CLR;
}

void printFailure()
{
	std::cout << RED BOLD "OK" CLR;
}