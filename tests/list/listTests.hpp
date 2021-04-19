//
// Created by Parfait Kentaurus on 4/19/21.
//

#ifndef FT_CONTAINERS_LISTTESTS_HPP
#define FT_CONTAINERS_LISTTESTS_HPP

#include "../../list.hpp"
#include "../tests.hpp"

class TestClass
{
	int	m_value;
public:
	TestClass() : m_value(10) {}
	~TestClass() {}
	bool operator== (const TestClass &other) const { return (m_value == other.m_value); }
};

//EMPTY TESTS |==============================================================================|

template <typename T>
void emptyTest()
{
	std::list<T> list;
	ft::list<T> ft_list;

	assert(list.empty() == ft_list.empty());
}

void testEmptyTypes()
{
	std::cout << "Empty: ";
	emptyTest<int>();
	emptyTest<float>();
	emptyTest<double>();
	emptyTest<long>();
	emptyTest<unsigned int>();
	emptyTest<char>();
	emptyTest<std::string>();
	emptyTest<TestClass>();

	printSuccess();
	std::cout << std::endl;
}

//COPY CONSTRUCTOR TESTS |==============================================================================|
template <typename T>
void copyConstructorTest()
{
	std::list<T> list;
	list.push_back(T());
	list.push_back(T());

	std::list<T> listCopy(list);

	ft::list<T> ft_list;
	ft_list.push_back(T());
	ft_list.push_back(T());

	ft::list<T> ft_listCopy(ft_list);

	assert(listCopy.size() == ft_listCopy.size());
	assert(listCopy.front() == ft_listCopy.front());
}

void testCopyConstructorTypes()
{
	std::cout << "Copy constructor: ";
	copyConstructorTest<int>();
	copyConstructorTest<float>();
	copyConstructorTest<double>();
	copyConstructorTest<long>();
	copyConstructorTest<unsigned int>();
	copyConstructorTest<char>();
	copyConstructorTest<std::string>();
	copyConstructorTest<TestClass>();

	printSuccess();
	std::cout << std::endl;
}

//COPY CONSTRUCTOR TESTS |==============================================================================|
template <typename T>
void assignTest()
{
	std::list<T> list;
	list.push_back(T());
	list.push_back(T());

	std::list<T> listCopy(list);

	ft::list<T> ft_list;
	ft_list.push_back(T());
	ft_list.push_back(T());

	ft::list<T> ft_listCopy(ft_list);

	assert(listCopy.size() == ft_listCopy.size());
	assert(listCopy.front() == ft_listCopy.front());
}

//template <typename T, typename F>
//struct TestFunctor
//{
//	T operator() (F func) { return func(); };
//};
//
//template <template<typename> class TestF, typename F>
//void testAssignTypes(F func)
//{
//	std::cout << "Copy constructor: ";
//	TestF<int>()(func);
//	TestF<float>()(func);
//	TestF<double>()(func);
//	TestF<long>()(func);
//	TestF<char>()(func);
//	TestF<unsigned int>()(func);
//	TestF<std::string>()(func);
//	TestF<TestClass>()(func);
//
//	printSuccess();
//	std::cout << std::endl;
//}

#endif
