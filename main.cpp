#include "list.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "map.hpp"

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"

#define CLR		"\033[0m"

bool single_digit(const int &value)
{
	return (value < 10);
}

bool is_second_lower(int first, int second)
{
	return (first > second);
}

template <typename T>
void printVector(const T &vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << "[" << i << "] " <<  vec[i] << "\n";
}

template <typename T>
void printList(T &list)
{
	int i = 0;
	for (typename T::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << "[" << i << "] " << *it << "\n";
		++i;
	}
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
		ft::vector<int> ft_v;

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
		ft::vector<int> ft_v;

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
		ft::vector<std::string> ft_v;

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
		ft::vector<std::string> ft_v(5);
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

		ft::vector<char> ft_v;
		ft::vector<int> ft_v1;
		ft::vector<float> ft_v2;
		ft::vector<std::string> ft_v3;

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
		ft::vector<int> ft_v;

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
		ft::vector<int> ft_v;
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
		ft::vector<int> ft_v2(ft_v.begin() + 1, ft_v.end());
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
		ft::vector<int> ft_v;
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

		ft::vector<int>::reverse_iterator ft_rit = ft_v.rbegin();

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

		ft::vector<int>::reverse_iterator ft_reit = ft_v.rend();

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
		ft::vector<int> ft_v;
		ft::vector<int> ft_v2;
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
		ft::vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(30);
		ft.push_back(40);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::vector<int>::iterator ft_it = ft.begin() + 2;
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
		ft::vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(30);
		ft.push_back(40);
		ft.push_back(50);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::vector<int>::iterator ft_it = ft.begin() + 2;
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
		ft::vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(3);
		ft.push_back(4);
		ft.push_back(5);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::vector<int>::iterator ft_it = ft.begin() + 1;
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
		ft::vector<int> ft;

		ft.push_back(10);
		ft.push_back(20);
		ft.push_back(30);
		ft.push_back(40);
		std::cout << "Before:" << std::endl;
		printVector(ft);
		std::cout << std::endl;

		ft::vector<int>::iterator ft_it = ft.begin() + 2;
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
		ft::vector<int> ft;

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
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░[COMPARE TWO VECTORS]░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
	std::cout << RED "\n* COMPARE TWO VECTORS *" CLR << "\n";
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░//
	{
		std::cout << RED "\n* SORT MORE *" CLR << "\n";
		std::vector<int> v;
		std::vector<int> v2;
		ft::vector<int> ft_v;
		ft::vector<int> ft_v2;

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		v.push_back(400);
		v.push_back(500);
		v.push_back(400);
		printVector(v);
		std::cout << "\nList two:\n";
		v2.push_back(200);
		v2.push_back(500);
		v2.push_back(200);
		printVector(v2);

		std::cout << "Vector one == Vector two:" <<std::endl;
		if (v == v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one != Vector two:" <<std::endl;
		if (v != v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one < Vector two:" <<std::endl;
		if (v < v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one <= Vector two:" <<std::endl;
		if (v <= v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one > Vector two:" <<std::endl;
		if (v > v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one >= Vector two:" <<std::endl;
		if (v >= v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_v.push_back(400);
		ft_v.push_back(500);
		ft_v.push_back(400);
		printVector(ft_v);
		std::cout << "\nList two:\n";
		ft_v2.push_back(200);
		ft_v2.push_back(500);
		ft_v2.push_back(200);
		printVector(ft_v2);

		std::cout << "Vector one == Vector two:" <<std::endl;
		if (ft_v == ft_v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one != Vector two:" <<std::endl;
		if (ft_v != ft_v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one < Vector two:" <<std::endl;
		if (ft_v < ft_v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one <= Vector two:" <<std::endl;
		if (ft_v <= ft_v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one > Vector two:" <<std::endl;
		if (ft_v > ft_v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Vector one >= Vector two:" <<std::endl;
		if (ft_v >= ft_v2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
	}
}

void listTest()
{
	std::cout << BLUE "**********************\\\\\\\\LIST////**********************" CLR << "\n";
	{
		std::cout << RED "* CREATE, EMPTY, SIZE *" CLR << "\n";

		std::list<int> list;

		list.push_back(1);
		list.push_back(20);
		list.push_back(999);

		ft::list<int> ft_list(list.begin(), list.end());

		std::cout << GREEN "Standard:" CLR << "\n";
		printList(list);
		if (list.empty())
			std::cout << "List is empty" << std::endl;
		else
			std::cout << "List is not empty" << std::endl;
		std::cout << "Size: " << list.size() << std::endl;
		std::cout << "Max size: " << list.max_size() << std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		printList(ft_list);
		if (ft_list.empty())
			std::cout << "List is empty" << std::endl;
		else
			std::cout << "List is not empty" << std::endl;
		std::cout << "Size: " << ft_list.size() << std::endl;
		std::cout << "Max size: " << ft_list.max_size() << std::endl;

//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* FRONT, BACK, ASSIGN *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		printList(list);
		std::cout << "Front: " << list.front() << std::endl;
		std::cout << "Back:  " << list.back() << std::endl;
		std::cout << "Assign:" << std::endl;
		list.assign(3, 2);
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		printList(ft_list);
		std::cout << "Front: " << ft_list.front() << std::endl;
		std::cout << "Back:  " << ft_list.back() << std::endl;
		std::cout << "Assign:" << std::endl;
		ft_list.assign(list.begin(), list.end());
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* PUSH, POP FRONT *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Push front" << "\n";
		list.push_front(16);
		std::cout << "Push front" << "\n";
		list.push_front(73);
		printList(list);

		std::cout << "\n";
		std::cout << "Pop front" << "\n";
		list.pop_front();
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Push front" << "\n";
		ft_list.push_front(16);
		std::cout << "Push front" << "\n";
		ft_list.push_front(73);
		printList(ft_list);

		std::cout << "\n";
		std::cout << "Pop front" << "\n";
		ft_list.pop_front();
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* PUSH, POP BACK *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Push back" << "\n";
		list.push_back(5);
		printList(list);

		std::cout << "\nPop back" << "\n";
		list.pop_back();
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Push back" << "\n";
		ft_list.push_back(5);
		printList(ft_list);

		std::cout << "\nPop back" << "\n";
		ft_list.pop_back();
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* INSERT *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		std::list<int>::iterator it = list.begin().operator++();
		list.insert(it, 44);
		printList(list);
		std::cout << "\n";

		std::list<int>::iterator it2 = list.begin().operator++();
		list.insert(it2, 2, 58);
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::list<int>::iterator ft_it = ft_list.begin().operator++();
		ft_list.insert(ft_it, 44);
		printList(ft_list);
		std::cout << "\n";

		ft::list<int>::iterator ft_it2 = ft_list.begin().operator++();
		ft_list.insert(ft_it2, 2, 58);
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* INSERT ITERATORS *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		std::list<int> list2;
		list2.push_back(9999);
		list2.push_back(4718);
		list2.push_back(3571);
		list2.push_back(1985);

		list.insert(list.begin().operator++(), list2.begin(), list2.begin().operator++().operator++());
		printList(list);
		std::cout << "Size: " << list.size() << std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::list<int> ft_list2;
		ft_list2.push_back(9999);
		ft_list2.push_back(4718);
		ft_list2.push_back(3571);
		ft_list2.push_back(1985);

		ft_list.insert(ft_list.begin().operator++(), ft_list2.begin(), ft_list2.begin().operator++().operator++());
		printList(ft_list);
		std::cout << "Size: " << ft_list.size() << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* ERASE *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		list.pop_back();
		list.pop_back();
		list.pop_back();
		printList(list);
		std::cout << "\nErase Iterator: " << *list.erase(list.begin().operator++()) << std::endl;
		printList(list);
		std::cout << "\nErase Iterator: " << *list.erase(list.begin().operator++(), list.begin().operator++().operator++()) << std::endl;
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft_list.pop_back();
		ft_list.pop_back();
		ft_list.pop_back();

		printList(ft_list);
		std::cout << "\nErase Iterator: " << *ft_list.erase(ft_list.begin().operator++()) << std::endl;
		printList(ft_list);
		std::cout << "\nErase Iterator: " << *ft_list.erase(ft_list.begin().operator++(), ft_list.begin().operator++().operator++()) << std::endl;
		printList(ft_list);
	}
	{
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* SWAP *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		std::list<int> list;
		list.push_back(5);
		std::list<int> list2;
		list2.push_back(10);
		list2.push_back(20);
		std::cout << "List one:\n";
		printList(list);
		std::cout << "List two:\n";
		printList(list2);

		std::cout << "\n";
		list.swap(list2);

		std::cout << "List one:\n";
		printList(list);
		std::cout << "List two:\n";
		printList(list2);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::list<int> ft_list;
		ft_list.push_back(5);
		ft::list<int> ft_list2;
		ft_list2.push_back(10);
		ft_list2.push_back(20);
		std::cout << "List one:\n";
		printList(ft_list);
		std::cout << "List two:\n";
		printList(ft_list2);

		std::cout << "\n";
		ft_list.swap(ft_list2);

		std::cout << "List one:\n";
		printList(ft_list);
		std::cout << "List two:\n";
		printList(ft_list2);

//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* RESIZE *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		printList(list);
		std::cout << "\nResize to 5:\n";
		list.resize(5, 8);
		printList(list);
		std::cout << "\nResize to 3:\n";
		list.resize(3);
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		printList(ft_list);
		std::cout << "\nResize to 5:\n";
		ft_list.resize(5, 8);
		printList(ft_list);
		std::cout << "\nResize to 3:\n";
		ft_list.resize(3);
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* CLEAR *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		printList(list);
		std::cout << "\nClear:\n";
		list.clear();
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		printList(ft_list);
		std::cout << "\nClear:\n";
		ft_list.clear();
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* SPLICE *" CLR << "\n";
		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(10);
		list.push_back(4);
		list.push_back(2);
		printList(list);
		std::cout << "\nList two:\n";
		list2.push_back(875);
		printList(list2);
		list.splice(list.end(), list2);
		std::cout << "\nList one after splice:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(10);
		ft_list.push_back(4);
		ft_list.push_back(2);
		printList(ft_list);
		std::cout << "\nList two:\n";
		ft_list2.push_back(875);
		printList(ft_list2);
		ft_list.splice(ft_list.end(), ft_list2);
		std::cout << "\nList one after splice:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* SPLICE MORE *" CLR << "\n";
		list.clear();
		ft_list.clear();

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		printList(list);
		std::cout << "\nList two:\n";
		list2.push_back(100);
		list2.push_back(200);
		list2.push_back(300);
		printList(list2);
		list.splice(list.end().operator--(), list2, list2.begin().operator++());
		std::cout << "\nList one after splice:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(1);
		ft_list.push_back(2);
		ft_list.push_back(3);
		printList(ft_list);
		std::cout << "\nList two:\n";
		ft_list2.push_back(100);
		ft_list2.push_back(200);
		ft_list2.push_back(300);
		printList(ft_list2);
		ft_list.splice(ft_list.end().operator--(), ft_list2, ft_list2.begin().operator++());
		std::cout << "\nList one after splice:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* REMOVE *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List:\n";
		list.push_back(200);
		list.push_front(200);
		printList(list);

		list.remove(200);
		std::cout << "\nList after remove:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List:\n";
		ft_list.push_front(200);
		ft_list.push_back(200);
		printList(ft_list);

		ft_list.remove(200);
		std::cout << "\nList after remove:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* REMOVE_IF *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List:\n";
		list.push_back(200);
		list.push_front(200);
		printList(list);

		list.remove_if(single_digit);
		std::cout << "\nList after remove:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List:\n";
		ft_list.push_front(200);
		ft_list.push_back(200);
		printList(ft_list);

		ft_list.remove_if(single_digit);
		std::cout << "\nList after remove:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* UNIQUE *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List:\n";
		list.push_back(80);
		list.push_back(5);
		list.push_back(5);
		list.push_front(5);
		list.push_front(80);
		printList(list);

		list.unique();
		std::cout << "\nList after unique:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List:\n";
		ft_list.push_back(80);
		ft_list.push_back(5);
		ft_list.push_back(5);
		ft_list.push_front(5);
		ft_list.push_front(80);
		printList(ft_list);

		ft_list.unique();
		std::cout << "\nList after unique:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* UNIQUE WITH PARAM *" CLR << "\n";
		list.clear();
		ft_list.clear();


		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List:\n";
		list.push_back(10);
		list.push_back(10);
		list.push_back(20);
		list.push_back(88);
		list.push_back(20);
		list.push_back(15);
		list.push_back(60);
		printList(list);

		list.unique(is_second_lower);
		std::cout << "\nList after unique:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List:\n";
		ft_list.push_back(10);
		ft_list.push_back(10);
		ft_list.push_back(20);
		ft_list.push_back(88);
		ft_list.push_back(20);
		ft_list.push_back(15);
		ft_list.push_back(60);
		printList(ft_list);

		ft_list.unique(is_second_lower);
		std::cout << "\nList after unique:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* MERGE *" CLR << "\n";
		list.clear();
		list2.clear();
		ft_list.clear();
		ft_list2.clear();


		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(5);
		list.push_back(8);
		list.push_back(12);
		printList(list);

		std::cout << "\nList two:\n";
		list2.push_back(4);
		list2.push_back(8);
		list2.push_back(10);
		printList(list2);

		list.merge(list2);
		std::cout << "\nList one after merge:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(1);
		ft_list.push_back(2);
		ft_list.push_back(3);
		ft_list.push_back(5);
		ft_list.push_back(8);
		ft_list.push_back(12);
		printList(ft_list);

		std::cout << "\nList two:\n";
		ft_list2.push_back(4);
		ft_list2.push_back(8);
		ft_list2.push_back(10);
		printList(ft_list2);

		ft_list.merge(ft_list2);
		std::cout << "\nList one after merge:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* MERGE WITH CUSTOM COMPARISON *" CLR << "\n";
		list.clear();
		list2.clear();
		ft_list.clear();
		ft_list2.clear();


		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(12);
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(5);
		list.push_back(8);
		printList(list);

		std::cout << "\nList two:\n";
		list2.push_back(4);
		list2.push_back(8);
		list2.push_back(10);
		printList(list2);

		list.merge(list2, is_second_lower);
		std::cout << "\nList one after merge:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(12);
		ft_list.push_back(1);
		ft_list.push_back(2);
		ft_list.push_back(3);
		ft_list.push_back(5);
		ft_list.push_back(8);
		printList(ft_list);

		std::cout << "\nList two:\n";
		ft_list2.push_back(4);
		ft_list2.push_back(8);
		ft_list2.push_back(10);
		printList(ft_list2);

		ft_list.merge(ft_list2, is_second_lower);
		std::cout << "\nList one after merge:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* REVERSE *" CLR << "\n";
		list.clear();
		list2.clear();
		ft_list.clear();
		ft_list2.clear();


		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(1);
		list.push_back(10);
		list.push_back(500);
		list.push_back(8000);
		printList(list);

		list.reverse();
		std::cout << "\nList after reverse:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(1);
		ft_list.push_back(10);
		ft_list.push_back(500);
		ft_list.push_back(8000);
		printList(ft_list);

		ft_list.reverse();
		std::cout << "\nList after reverse:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* SORT *" CLR << "\n";
		list.clear();
		list2.clear();
		ft_list.clear();
		ft_list2.clear();

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(1);
		list.push_back(8000);
		list.push_back(500);
		list.push_back(10);
		printList(list);

		list.sort();
		std::cout << "\nList after reverse:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(1);
		ft_list.push_back(8000);
		ft_list.push_back(500);
		ft_list.push_back(10);
		printList(ft_list);

		ft_list.sort();
		std::cout << "\nList after reverse:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* SORT MORE *" CLR << "\n";
		list.clear();
		ft_list.clear();

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(1);
		list.push_back(8000);
		list.push_back(500);
		list.push_back(10);
		printList(list);

		list.sort(is_second_lower);
		std::cout << "\nList after reverse:\n";
		printList(list);



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(1);
		ft_list.push_back(8000);
		ft_list.push_back(500);
		ft_list.push_back(10);
		printList(ft_list);

		ft_list.sort(is_second_lower);
		std::cout << "\nList after reverse:\n";
		printList(ft_list);
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* COMPARE *" CLR << "\n";
		list.clear();
		list2.clear();
		ft_list.clear();
		ft_list2.clear();

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "List one:\n";
		list.push_back(500);
		list.push_back(400);
		list.push_back(400);
		printList(list);
		std::cout << "\nList two:\n";
		list2.push_back(500);
		list2.push_back(200);
		printList(list2);

		std::cout << "List one == list two:" <<std::endl;
		if (list == list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one != list two:" <<std::endl;
		if (list != list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one < list two:" <<std::endl;
		if (list < list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one <= list two:" <<std::endl;
		if (list <= list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one > list two:" <<std::endl;
		if (list > list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one >= list two:" <<std::endl;
		if (list >= list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "List one:\n";
		ft_list.push_back(500);
		ft_list.push_back(400);
		ft_list.push_back(400);
		printList(ft_list);
		std::cout << "\nList two:\n";
		ft_list2.push_back(500);
		ft_list2.push_back(200);
		printList(ft_list2);

		std::cout << "List one == list two:" <<std::endl;
		if (ft_list == ft_list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one != list two:" <<std::endl;
		if (ft_list != ft_list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one < list two:" <<std::endl;
		if (ft_list < ft_list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one <= list two:" <<std::endl;
		if (ft_list <= ft_list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one > list two:" <<std::endl;
		if (ft_list > ft_list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "List one >= list two:" <<std::endl;
		if (ft_list >= ft_list2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
	}
}

void stackTest()
{
	std::cout << BLUE "**********************\\\\\\\\STACK////**********************" CLR << "\n";
	{
		std::cout << RED "* CREATE, PUSH, EMPTY, SIZE *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::stack<int> stack;

		if (stack.empty())
			std::cout << "Stack is empty" << std::endl;
		else
			std::cout << "Stack is not empty" << std::endl;
		std::cout << "Size: " << stack.size() << std::endl;

		std::cout << "Push 1" << std::endl;
		stack.push(1);
		std::cout << "Push 20" << std::endl;
		stack.push(20);
		std::cout << "Push 999" << std::endl;
		stack.push(999);

		if (stack.empty())
			std::cout << "Stack is empty" << std::endl;
		else
			std::cout << "Stack is not empty" << std::endl;
		std::cout << "Size: " << stack.size() << std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::stack<int> ft_stack;

		if (ft_stack.empty())
			std::cout << "Stack is empty" << std::endl;
		else
			std::cout << "Stack is not empty" << std::endl;
		std::cout << "Size: " << ft_stack.size() << std::endl;

		std::cout << "Push 1" << std::endl;
		ft_stack.push(1);
		std::cout << "Push 20" << std::endl;
		ft_stack.push(20);
		std::cout << "Push 999" << std::endl;
		ft_stack.push(999);

		if (ft_stack.empty())
			std::cout << "Stack is empty" << std::endl;
		else
			std::cout << "Stack is not empty" << std::endl;
		std::cout << "Size: " << ft_stack.size() << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* TOP, POP *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Top: " << stack.top() << std::endl;
		std::cout << BLUE "Pop" CLR << std::endl;
		stack.pop();
		std::cout << "Top: " << stack.top() << std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Top: " << ft_stack.top() << std::endl;
		std::cout << BLUE "Pop" CLR << std::endl;
		ft_stack.pop();
		std::cout << "Top: " << ft_stack.top() << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* COMPARE *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Stack one:\n";
		std::cout << "Push 500" << std::endl;
		stack.push(500);
		std::cout << "Push 400" << std::endl;
		stack.push(400);
		std::cout << "Push 400" << std::endl;
		stack.push(400);

		std::cout << "\nStack two:\n";
		std::stack<int> stack2;
		std::cout << "Push 500" << std::endl;
		stack2.push(500);
		std::cout << "Push 200" << std::endl;
		stack2.push(200);

		std::cout << "\nStack one == Stack two:" <<std::endl;
		if (stack == stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one != Stack two:" <<std::endl;
		if (stack != stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one < Stack two:" <<std::endl;
		if (stack < stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one <= Stack two:" <<std::endl;
		if (stack <= stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one > Stack two:" <<std::endl;
		if (stack > stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one >= Stack two:" <<std::endl;
		if (stack >= stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "StackStack one:\n";
		std::cout << "Push 500" << std::endl;
		ft_stack.push(500);
		std::cout << "Push 400" << std::endl;
		ft_stack.push(400);
		std::cout << "Push 400" << std::endl;
		ft_stack.push(400);

		std::cout << "\nStackStack two:\n";
		ft::stack<int> ft_stack2;
		std::cout << "Push 500" << std::endl;
		ft_stack2.push(500);
		std::cout << "Push 200" << std::endl;
		ft_stack2.push(200);

		std::cout << "\nStack one == Stack two:" <<std::endl;
		if (ft_stack == ft_stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one != Stack two:" <<std::endl;
		if (ft_stack != ft_stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one < Stack two:" <<std::endl;
		if (ft_stack < ft_stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one <= Stack two:" <<std::endl;
		if (ft_stack <= ft_stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one > Stack two:" <<std::endl;
		if (ft_stack > ft_stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Stack one >= Stack two:" <<std::endl;
		if (ft_stack >= ft_stack2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
	}
}

void queueTest()
{
	std::cout << BLUE "**********************\\\\\\\\QUEUE////**********************" CLR << "\n";
	{
		std::cout << RED "* CREATE, PUSH, EMPTY, SIZE, BACK, FRONT *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::queue<int> queue;

		if (queue.empty())
			std::cout << "Queue is empty" << std::endl;
		else
			std::cout << "Queue is not empty" << std::endl;
		std::cout << "Size: " << queue.size() << std::endl;

		std::cout << "Push 1" << std::endl;
		queue.push(1);
		std::cout << "Front: " << queue.front() << std::endl;
		std::cout << "Back: " << queue.back() << std::endl;
		std::cout << "\nPush 20" << std::endl;
		queue.push(20);
		std::cout << "Front: " << queue.front() << std::endl;
		std::cout << "Back: " << queue.back() << std::endl;
		std::cout << "\nPush 999" << std::endl;
		queue.push(999);
		std::cout << "Front: " << queue.front() << std::endl;
		std::cout << "Back: " << queue.back() << std::endl;

		if (queue.empty())
			std::cout << "\nQueue is empty" << std::endl;
		else
			std::cout << "Queue is not empty" << std::endl;
		std::cout << "Size: " << queue.size() << std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::queue<int> ft_queue;

		if (ft_queue.empty())
			std::cout << "Queue is empty" << std::endl;
		else
			std::cout << "Queue is not empty" << std::endl;
		std::cout << "Size: " << ft_queue.size() << std::endl;

		std::cout << "Push 1" << std::endl;
		ft_queue.push(1);
		std::cout << "Front: " << ft_queue.front() << std::endl;
		std::cout << "Back: " << ft_queue.back() << std::endl;
		std::cout << "\nPush 20" << std::endl;
		ft_queue.push(20);
		std::cout << "Front: " << ft_queue.front() << std::endl;
		std::cout << "Back: " << ft_queue.back() << std::endl;
		std::cout << "\nPush 999" << std::endl;
		ft_queue.push(999);
		std::cout << "Front: " << ft_queue.front() << std::endl;
		std::cout << "Back: " << ft_queue.back() << std::endl;

		if (ft_queue.empty())
			std::cout << "Queue is empty" << std::endl;
		else
			std::cout << "Queue is not empty" << std::endl;
		std::cout << "Size: " << ft_queue.size() << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* POP *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Front: " << queue.front() << std::endl;
		std::cout << "Back: " << queue.back() << std::endl;
		std::cout << BLUE "Pop" CLR << std::endl;
		queue.pop();
		std::cout << "Front: " << queue.front() << std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Front: " << ft_queue.front() << std::endl;
		std::cout << "Back: " << ft_queue.back() << std::endl;
		std::cout << BLUE "Pop" CLR << std::endl;
		ft_queue.pop();
		std::cout << "Front: " << ft_queue.front() << std::endl;
//--------------------------------------------------------------------------------------//
		std::cout << RED "\n* COMPARE *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::cout << "Queue one:\n";
		std::cout << "Push 500" << std::endl;
		queue.push(500);
		std::cout << "Push 400" << std::endl;
		queue.push(400);
		std::cout << "Push 400" << std::endl;
		queue.push(400);

		std::cout << "\nList two:\n";
		std::queue<int> queue2;
		std::cout << "Push 500" << std::endl;
		queue2.push(500);
		std::cout << "Push 200" << std::endl;
		queue2.push(200);

		std::cout << "\nQueue one == Queue two:" <<std::endl;
		if (queue == queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one != Queue two:" <<std::endl;
		if (queue != queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one < Queue two:" <<std::endl;
		if (queue < queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one <= Queue two:" <<std::endl;
		if (queue <= queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one > Queue two:" <<std::endl;
		if (queue > queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one >= Queue two:" <<std::endl;
		if (queue >= queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		std::cout << "Queue one:\n";
		std::cout << "Push 500" << std::endl;
		ft_queue.push(500);
		std::cout << "Push 400" << std::endl;
		ft_queue.push(400);
		std::cout << "Push 400" << std::endl;
		ft_queue.push(400);

		std::cout << "\nList two:\n";
		ft::queue<int> ft_queue2;
		std::cout << "Push 500" << std::endl;
		ft_queue2.push(500);
		std::cout << "Push 200" << std::endl;
		ft_queue2.push(200);

		std::cout << "\nQueue one == Queue two:" <<std::endl;
		if (ft_queue == ft_queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one != Queue two:" <<std::endl;
		if (ft_queue != ft_queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one < Queue two:" <<std::endl;
		if (ft_queue < ft_queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one <= Queue two:" <<std::endl;
		if (ft_queue <= ft_queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one > Queue two:" <<std::endl;
		if (ft_queue > ft_queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
		std::cout << "Queue one >= Queue two:" <<std::endl;
		if (ft_queue >= ft_queue2)
			std::cout << GREEN "True" CLR <<std::endl;
		else
			std::cout << RED "False" CLR <<std::endl;
	}
}

void mapTest()
{
	std::cout << BLUE "**********************\\\\\\\\MAP////**********************" CLR << "\n";
	{
		std::cout << RED "*  *" CLR << "\n";

		std::cout << GREEN "Standard:" CLR << "\n";
		std::map<int, int> map;
		std::cout << "Max size: " << map.max_size() << std::endl;

		map.insert(std::pair<int, int>(10, 20));
		map.insert(std::pair<int, int>(20, 20));
		map.insert(std::pair<int, int>(4, 20));
		map.insert(std::pair<int, int>(50, 20));
		map.insert(std::pair<int, int>(1, 20));

		std::map<int, int>::iterator it = map.begin();
		std::cout << "Begin iterator key: " << it->first << std::endl;
		++it;
		std::cout << "++Iterator key: " << (*it).first << std::endl;



		std::cout << YELLOW "\nCustom:" CLR << "\n";
		ft::map<int, int> ft_map;
		std::cout << "Max size: " << ft_map.max_size() << std::endl;

		ft_map.insert(std::pair<int, int>(1, 20));
		ft_map.insert(std::pair<int, int>(2, 20));
		ft_map.insert(std::pair<int, int>(3, 20));
		ft_map.insert(std::pair<int, int>(4, 20));
		ft_map.insert(std::pair<int, int>(5, 20));
		ft_map.insert(std::pair<int, int>(6, 20));
		ft_map.insert(std::pair<int, int>(7, 20));
		ft_map.insert(std::pair<int, int>(8, 20));
		ft_map.insert(std::pair<int, int>(9, 20));
		ft_map.insert(std::pair<int, int>(10, 20));

		ft_map.erase(4);
		ft_map.erase(5);
		ft_map.erase(1);
		ft_map.erase(8);
		ft_map.erase(2);
		ft_map.erase(9);
		ft_map.erase(7);
		ft_map.erase(3);
		ft_map.erase(3);
//--------------------------------------------------------------------------------------//
		std::cout << "\n\n\n\n";
		ft_map.drawTree(ft_map.getRoot(), 0, 0);
		getchar();
		ft::map<int, int>::iterator ft_it = ft_map.begin();
		std::cout << "Begin iterator key: " << ft_it->first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
		++ft_it;
		std::cout << "Begin iterator key: " << (*ft_it).first << std::endl;
	}
}

int main()
{
//	vectorTest();
//	listTest();
//	stackTest();
//	queueTest();
	mapTest();
//	getchar();
}
