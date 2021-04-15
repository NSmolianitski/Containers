#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP

#include <cstdlib>

namespace ft
{
	template<typename T>
	class List
	{
		T		m_value;
		size_t	m_size;
		T		*m_next;
		T		*m_prev;

	public:
		List();
		explicit List(size_type n, const value_type &val = value_type());
		template<class InputIterator>
		List(InputIterator first, InputIterator last);
		List(const List &x);

		~List();

		List<T> &operator=(const List &x);


	};

	template<typename T>
	List<T>::List() : m_size(0), m_value(0), m_next(0) {}

	template<typename T>
	List<T>::List(size_type n, const value_type &val)
	{

	}

	template<typename T>
	template<class InputIterator>
	List<T>::List(InputIterator first, InputIterator last)
	{

	}

	template<typename T>
	List<T>::List(const List &x)
	{

	}

	template<typename T>
	List<T>::~List()
	{

	}

	template<typename T>
	List<T> &List<T>::operator=(const List &x)
	{
		if (this != x)
		{

		}
		return *this;
	}
}

#endif
