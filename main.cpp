//#include "List.hpp"
#include "Vector.hpp"

#include <iostream>
#include <list>
#include <vector>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"

#define CLR		"\033[0m"

template <typename T>
void printVector(const T &vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << "[" << i << "] " <<  vec[i] << "\n";
}

void vectorTest()
{
	std::cout << BLUE "**********************\\\\\\\\VECTOR////**********************" CLR << "\n";
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████[CAPACITY && SIZE]██████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[CAPACITY && SIZE]" CLR << "\n";
	{

		int a = 10;

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 3 ELEMENTS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* PUSH 3 ELEMENTS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(a);
		v.push_back(a);
		v.push_back(a);
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft_v;

		ft_v.push_back(a);
		ft_v.push_back(a);
		ft_v.push_back(a);

		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 2 MORE ELEMENTS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* PUSH 2 MORE ELEMENTS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		v.push_back(a);
		v.push_back(a);
		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		ft_v.push_back(a);
		ft_v.push_back(a);
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[RESIZE TO 20]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* RESIZE TO 20 *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		v.resize(20);
		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		ft_v.resize(20);
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████[RESIZE]████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[RESIZE]" CLR << "\n";
	{
		int a = 10;

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 3 ELEMENTS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* PUSH 3 ELEMENTS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(a);
		v.push_back(a);
		v.push_back(a);

		printVector(v);
		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft_v;

		ft_v.push_back(a);
		ft_v.push_back(a);
		ft_v.push_back(a);

		printVector(ft_v);
		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[RESIZE TO 6]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* RESIZE TO 6 *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		v.resize(6);
		printVector(v);
		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_v.resize(6);
		printVector(ft_v);
		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[RESIZE TO 2]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* RESIZE TO 2 *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		v.resize(2);
		printVector(v);
		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_v.resize(2);
		printVector(ft_v);
		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░[RESIZE BACK TO 6 AND PUSH TWO NUMBERS]░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* RESIZE BACK TO 6 AND PUSH TWO NUMBERS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		v.resize(6);
		v.push_back(88);
		v.push_back(88);
		printVector(v);
		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_v.resize(6);
		ft_v.push_back(88);
		ft_v.push_back(88);
		printVector(ft_v);
		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//███████████████████████████████████████[EMPTY]████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[EMPTY]" CLR << "\n";
	{

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[CHECK EMPTY VECTOR]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* CHECK EMPTY VECTOR *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//

		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<std::string> v;
		printVector(v);
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";

		if (v.empty())
			std::cout << "Vector is empty" << std::endl;
		else
			std::cout << "Vector is not empty" << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<std::string> ft_v;

		printVector(ft_v);
		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";

		if (ft_v.empty())
			std::cout << "Vector is empty" << std::endl;
		else
			std::cout << "Vector is not empty" << std::endl;
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░[PUSH 2 ELEMENTS AND CHECK NOT EMPTY VECTOR]░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* PUSH 2 ELEMENTS AND CHECK NOT EMPTY VECTOR *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		v.push_back("hello");
		v.push_back("world");

		printVector(v);
		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";

		if (v.empty())
			std::cout << "Vector is empty" << std::endl;
		else
			std::cout << "Vector is not empty" << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_v.push_back("hello");
		ft_v.push_back("world");

		printVector(ft_v);
		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";

		if (ft_v.empty())
			std::cout << "Vector is empty" << std::endl;
		else
			std::cout << "Vector is not empty" << std::endl;
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//███████████████████████████████████████[RESERVE]████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[RESERVE]" CLR << "\n";
	{

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░[CREATE VECTOR WITH 5 ELEMENTS]░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* CREATE VECTOR WITH 5 ELEMENTS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<std::string> v(5);
		printVector(v);

		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<std::string> ft_v(5);
		printVector(ft_v);

		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[INCREASE RESERVE TO 20]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* INCREASE RESERVE TO 20 *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		v.reserve(20);
		printVector(v);

		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_v.reserve(20);
		printVector(ft_v);

		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[DECREASE RESERVE TO 15]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* DECREASE RESERVE TO 15 *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		v.reserve(15);
		printVector(v);

		std::cout << "\nCapacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_v.reserve(15);
		printVector(ft_v);

		std::cout << "\nCapacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████[MAX SIZE]██████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[MAX SIZE]" CLR << "\n";
	{
		std::vector<char> v;
		std::vector<int> v1;
		std::vector<float> v2;
		std::vector<std::string> v3;

		ft::Vector<char> ft_v;
		ft::Vector<int> ft_v1;
		ft::Vector<float> ft_v2;
		ft::Vector<std::string> ft_v3;

		std::cout << GREEN "Standard " CLR << "CHAR max size:  " << v.max_size() << std::endl;
		std::cout << YELLOW "Custom " CLR << "  CHAR max size:  " << ft_v.max_size() << "\n" << std::endl;

		std::cout << GREEN "Standard " CLR << "INT max size:   " << v1.max_size() << std::endl;
		std::cout << YELLOW "Custom " CLR << "  INT max size:   " << ft_v1.max_size() << "\n" << std::endl;

		std::cout << GREEN "Standard " CLR << "FLOAT max size: " << v2.max_size() << std::endl;
		std::cout << YELLOW "Custom " CLR << "  FLOAT max size: " << ft_v2.max_size() << "\n" << std::endl;

		std::cout << GREEN "Standard " CLR << "STRING max size: " << v3.max_size() << std::endl;
		std::cout << YELLOW "Custom " CLR << "  STRING max size: " << ft_v3.max_size() << "\n" << std::endl;
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//████████████████████████████████████████[ASSIGN]██████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[ASSIGN]" CLR << "\n";
	{

		int a = 10;

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 3 ELEMENTS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* PUSH 3 ELEMENTS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(a);
		v.push_back(a);
		v.push_back(a);
		printVector(v);

		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft_v;

		ft_v.push_back(a);
		ft_v.push_back(a);
		ft_v.push_back(a);
		printVector(ft_v);

		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[ASSIGN 5 ELEMENTS (8)]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* ASSIGN 5 ELEMENTS (8) *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";

		v.assign(5, 8);
		printVector(v);
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";

		ft_v.assign(5, 8);
		printVector(ft_v);
		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[ASSIGN 2 ELEMENTS (54)]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* ASSIGN 2 ELEMENTS (54) *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";

		v.assign(2, 54);
		printVector(v);
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";

		ft_v.assign(2, 54);
		printVector(ft_v);
		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size " << ft_v.size() << "\n";
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████[ITERATORS]█████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[ITERATORS]" CLR << "\n";
	{
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 2 ELEMENTS AND PRINT ITERATORS]░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "* PUSH 3 ELEMENTS AND PRINT ITERATORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;
		std::cout << "Size " << v.size() << "\n\n";

		std::cout << "Push 5, 8 and 10" << std::endl;
		v.push_back(5);
		v.push_back(8);
		v.push_back(10);

		std::cout << "Begin:   " << *(v.begin()) << std::endl;
		std::cout << "End - 1: " << *(v.end() - 1) << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft_v;
		std::cout << "Size " << ft_v.size() << "\n\n";

		std::cout << "Push 5, 8 and 10" << std::endl;
		ft_v.push_back(5);
		ft_v.push_back(8);
		ft_v.push_back(10);

		std::cout << "Begin:   " << *(ft_v.begin()) << std::endl;
		std::cout << "End - 1: " << *(ft_v.end() - 1) << std::endl;
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[COPY THROUGH ITERATORS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* COPY THROUGH ITERATORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Source:"<< "\n";
		printVector(v);

		std::cout << "\nCopy from begin + 1 to end:"<< "\n";
		std::vector<int> v2(v.begin() + 1, v.end());
		printVector(v2);
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Source:"<< "\n";
		printVector(ft_v);

		std::cout << "\nCopy from begin + 1 to end:"<< "\n";
		ft::Vector<int> ft_v2(ft_v.begin() + 1, ft_v.end());
		printVector(ft_v2);
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//█████████████████████████████████[REVERSED ITERATORS]█████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[REVERSED ITERATORS]" CLR << "\n";
	{
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 3 ELEMENTS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* PUSH 3 ELEMENTS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;
		v.push_back(1);
		v.push_back(4);
		v.push_back(20);

		printVector(v);
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft_v;
		ft_v.push_back(1);
		ft_v.push_back(4);
		ft_v.push_back(20);

		printVector(ft_v);
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░[SHOW RBEGIN AND (REND - 1) ITERATORS]░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* SHOW RBEGIN AND (REND - 1) ITERATORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "RBegin:     " << *v.rbegin() << std::endl;
		std::cout << "(REnd - 1): " << *(v.rend() - 1) << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "RBegin:     " << *ft_v.rbegin() << std::endl;
		std::cout << "(REnd - 1): " << *(ft_v.rend() - 1) << std::endl;
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[INCREASE AND DECREASE RBEGIN]░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* INCREASE AND DECREASE RBEGIN *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		printVector(v);

		std::vector<int>::reverse_iterator rit = v.rbegin();

		std::cout << "\nRBegin:   " << *rit << std::endl;
		std::cout << "++RBegin: "   << *(++rit) << std::endl;
		std::cout << "++RBegin: "   << *(++rit) << std::endl;

		std::cout << "\nRBegin:   "   << *rit << std::endl;
		std::cout << "--RBegin: "   << *(--rit) << std::endl;
		std::cout << "--RBegin: "   << *(--rit) << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		printVector(ft_v);

		ft::Vector<int>::reverse_iterator ft_rit = ft_v.rbegin();

		std::cout << "\nRBegin:   " << *ft_rit << std::endl;
		std::cout << "++RBegin: "   << *(++ft_rit) << std::endl;
		std::cout << "++RBegin: "   << *(++ft_rit) << std::endl;

		std::cout << "\nRBegin:   "   << *ft_rit << std::endl;
		std::cout << "--RBegin: "	<< *(--ft_rit) << std::endl;
		std::cout << "--RBegin: "   << *(--ft_rit) << std::endl;
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[INCREASE AND DECREASE REND]░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* INCREASE AND DECREASE REND *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		printVector(v);

		std::vector<int>::reverse_iterator reit = v.rend();

		std::cout << "\n--REnd: " << *(--reit) << std::endl;
		std::cout << "--REnd: "   << *(--reit) << std::endl;
		std::cout << "--REnd: "   << *(--reit) << std::endl;

		std::cout << "\nREnd:   " << *reit << std::endl;
		std::cout << "++REnd: "   << *(++reit) << std::endl;
		std::cout << "++REnd: "   << *(++reit) << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		printVector(ft_v);

		ft::Vector<int>::reverse_iterator ft_reit = ft_v.rend();

		std::cout << "\n--REnd: " << *(--ft_reit) << std::endl;
		std::cout << "--REnd: "   << *(--ft_reit) << std::endl;
		std::cout << "--REnd: "   << *(--ft_reit) << std::endl;

		std::cout << "\nREnd:   " << *ft_reit << std::endl;
		std::cout << "++REnd: "   << *(++ft_reit) << std::endl;
		std::cout << "++REnd: "   << *(++ft_reit) << std::endl;
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//████████████████████████████████████████[SWAP]████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[SWAP]" CLR << "\n";
	{
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[CREATE TWO VECTORS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* CREATE TWO VECTORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;
		std::vector<int> v2;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);

		std::cout << "Vector 1:" << std::endl;
		printVector(v);
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size     " << v.size() << "\n";

		std::cout << "\nVector 2 is empty:\n" << std::endl;
		printVector(v2);
		std::cout << "Capacity " << v2.capacity() << "\n";
		std::cout << "Size     " << v2.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft_v;
		ft::Vector<int> ft_v2;
		ft_v.push_back(1);
		ft_v.push_back(2);
		ft_v.push_back(3);

		std::cout << "Vector 1:" << std::endl;
		printVector(ft_v);
		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size     " << ft_v.size() << "\n";

		std::cout << "\nVector 2 is empty:\n" << std::endl;
		printVector(ft_v2);
		std::cout << "Capacity " << ft_v2.capacity() << "\n";
		std::cout << "Size     " << ft_v2.size() << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[SWAP VECTORS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* SWAP VECTORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		v.swap(v2);

		std::cout << "Vector 1 is empty:\n" << std::endl;
		printVector(v);
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size     " << v.size() << "\n";

		std::cout << "\nVector 2:" << std::endl;
		printVector(v2);
		std::cout << "Capacity " << v2.capacity() << "\n";
		std::cout << "Size     " << v2.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_v.swap(ft_v2);

		std::cout << "Vector 1 is empty:\n" << std::endl;
		printVector(ft_v);
		std::cout << "Capacity " << ft_v.capacity() << "\n";
		std::cout << "Size     " << ft_v.size() << "\n";

		std::cout << "\nVector 2:" << std::endl;
		printVector(ft_v2);
		std::cout << "Capacity " << ft_v2.capacity() << "\n";
		std::cout << "Size     " << ft_v2.size() << "\n";
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//███████████████████████████████████████[INSERT]███████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[INSERT]" CLR << "\n";
	{
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 4 ELEMENTS AND INSERT]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* PUSH 4 ELEMENTS AND INSERT *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);
		std::cout << "Before:" << std::endl;
		printVector(v);
		std::cout << std::endl;

		std::vector<int>::iterator it = v.begin() + 2;
		v.insert(it, 2);
		std::cout << "After:" << std::endl;
		printVector(v);
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(30);
		ft.push_back(40);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::Vector<int>::iterator ft_it = ft.begin() + 2;
		ft.insert(ft_it, 2);
		std::cout << "After:" << std::endl;
		printVector(ft);
	}
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 5 ELEMENTS AND INSERT 3]░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* PUSH 5 ELEMENTS AND INSERT 3 *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
	{
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);
		v.push_back(50);
		std::cout << "Before:" << std::endl;
		printVector(v);
		std::cout << std::endl;

		std::vector<int>::iterator it = v.begin() + 2;
		v.insert(it, 3, 8);
		std::cout << "After:" << std::endl;
		printVector(v);
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(30);
		ft.push_back(40);
		ft.push_back(50);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::Vector<int>::iterator ft_it = ft.begin() + 2;
		ft.insert(ft_it, 3, 8);
		std::cout << "After:" << std::endl;
		printVector(ft);
	}
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░[PUSH 5 ELEMENTS AND INSERT THROUGH ITERATORS]░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
	std::cout << RED "\n* PUSH 5 ELEMENTS AND INSERT THROUGH ITERATORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
	{
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << "Before:" << std::endl;
		printVector(v);
		std::cout << std::endl;

		std::vector<int>::iterator it = v.begin() + 1;
		v.insert(it, v.begin(), v.begin() + 3);
		std::cout << "After:" << std::endl;
		printVector(v);
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(3);
		ft.push_back(4);
		ft.push_back(5);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::Vector<int>::iterator ft_it = ft.begin() + 1;
		ft.insert(ft_it, ft.begin(), ft.begin() + 3);
		std::cout << "After:" << std::endl;
		printVector(ft);
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//███████████████████████████████████████[ERASE]████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[ERASE]" CLR << "\n";
	{
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 4 ELEMENTS AND ERASE]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* PUSH 4 ELEMENTS AND ERASE *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);
		std::cout << "Before:" << std::endl;
		printVector(v);
		std::cout << std::endl;

		std::vector<int>::iterator it = v.begin() + 2;
		std::cout << *v.erase(it);
		std::cout << "After:" << std::endl;
		printVector(v);
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(30);
		ft.push_back(40);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::Vector<int>::iterator ft_it = ft.begin() + 2;
		std::cout << *ft.erase(ft_it);
		std::cout << "After:" << std::endl;
		printVector(ft);
	}
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░[PUSH 4 ELEMENTS AND ERASE TWO]░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
	{
		std::cout << RED "\n* PUSH 4 ELEMENTS AND ERASE TWO *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << "Before:" << std::endl;
		printVector(v);
		std::cout << std::endl;

		std::cout << "After:" << std::endl;
		v.erase(v.begin(), v.begin() + 2);
		printVector(v);
		std::cout << "Capacity " << v.capacity() << "\n";
		std::cout << "Size     " << v.size() << "\n";
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft;

		ft.push_back(1);
		ft.push_back(2);
		ft.push_back(3);
		ft.push_back(4);
		ft.push_back(5);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		std::cout << "After:" << std::endl;
		ft.erase(ft.begin(), ft.begin() + 2);
		printVector(ft);
		std::cout << "Capacity " << ft.capacity() << "\n";
		std::cout << "Size     " << ft.size() << "\n";
	}
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//█████████████████████████████████[VECTOR COMPARISON]██████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
//██████████████████████████████████████████████████████████████████████████████████████//
	std::cout << RED "\n[VECTOR COMPARISON]" CLR << "\n";
	{
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[COMPARE TWO VECTORS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* COMPARE TWO VECTORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(1);
		v.push_back(2);

		std::vector<int> v1 = v;

		std::cout << "Vector one:" << std::endl;
		printVector(v);
		std::cout << "Vector two:" << std::endl;
		printVector(v1);

		if (v == v1)
			std::cout << "\nEqual" << std::endl;
		else
			std::cout << "\nNot equal" << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft;

		ft.push_back(1);
		ft.push_back(2);

		ft::Vector<int> ft1 = ft;

		std::cout << "Vector one:" << std::endl;
		printVector(ft);
		std::cout << "Vector two:" << std::endl;
		printVector(ft1);

		if (ft == ft1)
			std::cout << "\nEqual" << std::endl;
		else
			std::cout << "\nNot equal" << std::endl;
	}
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[ONE MORE COMPARE]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
		std::cout << RED "\n* ONE MORE COMPARE *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
	{
		std::cout << GREEN "Standard:" CLR << "\n";
		std::vector<int> v;

		v.push_back(1);
		v.push_back(2);

		std::vector<int> v1;
		v1.push_back(2);

		std::cout << "Vector one:" << std::endl;
		printVector(v);
		std::cout << "Vector two:" << std::endl;
		printVector(v1);

		if (v == v1)
			std::cout << "\nEqual" << std::endl;
		else
			std::cout << "\nNot equal" << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::Vector<int> ft;

		ft.push_back(1);
		ft.push_back(2);

		ft::Vector<int> ft1;
		ft1.push_back(2);

		std::cout << "Vector one:" << std::endl;
		printVector(ft);
		std::cout << "Vector two:" << std::endl;
		printVector(ft1);

		if (ft == ft1)
			std::cout << "\nEqual" << std::endl;
		else
			std::cout << "\nNot equal" << std::endl;

	}
}

int main()
{
	vectorTest();

}
