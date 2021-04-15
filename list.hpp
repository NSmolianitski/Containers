#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP

#include <sstream>

namespace ft
{
	template<typename T>
	class list
	{
		//Members
		class Node
		{
		public:
			//Members
			T		m_value;

			Node	*m_next;
			Node	*m_prev;

			//Constructors and destructor
			Node				() : m_value(value_type()), m_next(0), m_prev(0) {}
			explicit Node		(T value) : m_value(value) {}
			Node				(const Node &other) : m_value(other.m_value), m_next(m_value), m_prev(m_value)	{}
			~Node				() {}

			//Assign operator
			Node &operator=		(const Node &other)
			{
				if (this != &other)
				{
					m_value = other.m_value;
					m_next = other.m_next;
					m_prev = other.m_prev;
				}
				return *this;
			}
		};

		Node	*m_head;
		Node	*m_tail;
		size_t	m_size;

		class Iterator;
		class ReverseIterator;

	public:

		typedef T						value_type;
		typedef std::size_t 			size_type;
		typedef T&						reference;
		typedef const T&				const_reference;
		typedef	Iterator				iterator;
		typedef	const Iterator			const_iterator;
		typedef	ReverseIterator			reverse_iterator;
		typedef	const ReverseIterator	const_reverse_iterator;

		//Constructors and destructor
//		template<class InputIterator>
//			list		(InputIterator first, InputIterator last);

		list			();
		list			(const list &x);
		explicit list	(size_type n, const value_type &val = value_type());
		~list			();

		list<T>& operator= (const list &x);

		//Iterators
		iterator		begin	();
		const_iterator	begin	() const;
		iterator		end		();
		const_iterator	end		() const;

	private:
		class Iterator
		{
		public:
			typedef	std::random_access_iterator_tag	iterator_category;
			typedef	std::ptrdiff_t					difference_type;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;

			Iterator() : m_ptr(0) {}
			explicit Iterator(Node *ptr) : m_ptr(ptr) {}

			reference		operator*  () const 				{ return m_ptr->m_value; }
			pointer			operator-> () const 				{ return &m_ptr->m_value; }

			Iterator&		operator++ ()						{ m_ptr = m_ptr->m_next; return *this; }
			Iterator		operator++ (int)					{ Iterator tmp = *this; ++(*this); return tmp; }

			Iterator&		operator-- ()						{ m_ptr = m_ptr->m_prev; return *this; }
			Iterator		operator-- (int)					{ Iterator tmp = *this; --(*this); return tmp; }

			bool			operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

		private:
			Node	*m_ptr;
		};

		class ReverseIterator
		{
		public:
			typedef	std::random_access_iterator_tag	iterator_category;
			typedef	std::ptrdiff_t					difference_type;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;

			ReverseIterator() : m_ptr(0) {}
			explicit ReverseIterator(pointer ptr) : m_ptr(ptr) {}

			reference				operator*  () const 						{ return *m_ptr; }
			pointer					operator-> () const 						{ return m_ptr; }

			ReverseIterator&		operator++ ()								{ --m_ptr; return *this; }
			ReverseIterator			operator++ (int)							{ ReverseIterator tmp = *this; --(*this); return tmp; }

			ReverseIterator&		operator-- ()								{ ++m_ptr; return *this; }
			ReverseIterator			operator-- (int)							{ ReverseIterator tmp = *this; ++(*this); return tmp; }

			bool			operator== (const ReverseIterator &other)			{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const ReverseIterator &other)			{ return this->m_ptr != other.m_ptr; }

		private:
			pointer	m_ptr;
		};

	};

	template<typename T>
	list<T>::list()
		: m_size(0),
		  m_head(0),
		  m_tail(0) {}

	template<typename T>
	list<T>::list(size_type n, const value_type &val) : m_size(n)
	{
		m_head = new Node(val);
		Node *ptr = m_head;
		for (int i = 0; i < m_size - 1; ++i)
		{
			ptr->m_next = new Node(val);
			ptr->m_next->m_prev = ptr;
			ptr = ptr->m_next;
		}
		ptr->m_next = 0;
		m_tail = ptr;
	}

//	template<typename T>
//	template<class InputIterator>
//	list<T>::list(InputIterator first, InputIterator last)
//	{
//
//	}

	template<typename T>
	list<T>::list(const list &x)
	{

	}

	template<typename T>
	list<T>::~list()
	{

	}

	template<typename T>
	list<T> &list<T>::operator= (const list &x)
	{
		if (this != x)
		{

		}
		return *this;
	}

	template<typename T>
	typename list<T>::iterator list<T>::begin()
	{
		return Iterator(m_head);
	}

	template<typename T>
	typename list<T>::const_iterator list<T>::begin() const
	{
		return Iterator(m_head);
	}

	template<typename T>
	typename list<T>::iterator list<T>::end()
	{
		return Iterator(m_tail->m_next);
	}

	template<typename T>
	typename list<T>::const_iterator list<T>::end() const
	{
		return Iterator(m_tail->m_next);
	}
}

#endif
