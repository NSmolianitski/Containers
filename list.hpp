#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP

#include "vector.hpp"

#include <sstream>
#include <iostream>

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
			Node				() : m_value(value_type()) {}
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
		template<class InputIterator>
			list		(InputIterator first, typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last);

		list			();
		list			(const list &x);
		explicit list	(size_type n, const value_type &val = value_type());
		~list			();

		list<T>& operator= (const list &x);

		//Iterators
		iterator				begin	();
		const_iterator			begin	() const;
		iterator				end		();
		const_iterator			end		() const;
		reverse_iterator		rbegin	();
		const_reverse_iterator	rbegin	() const;
		reverse_iterator		rend	();
		const_reverse_iterator	rend	() const;

		//Capacity
		bool		empty	() const;
		size_type	size	() const;
		size_type	max_size() const;

		//Element access
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;

		//Modifiers
		template <class InputIterator>
			void assign (InputIterator first, typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last);
		void assign		(size_type n, const value_type& val);
		void push_front	(const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();

	private:
		class Iterator
		{
		public:
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	std::ptrdiff_t					difference_type;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;

			Iterator() : m_ptr(0) {}
			explicit Iterator(Node *ptr) : m_ptr(ptr) {}

			reference		operator*  () const 				{ return m_ptr->m_value; }
			pointer			operator-> () const 				{ return m_ptr->m_value; }

			Iterator&		operator++ ()						{ m_ptr = m_ptr->m_next; return *this; }
			Iterator		operator++ (int)					{ Iterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_next; return tmp; }

			Iterator&		operator-- ()						{ m_ptr = m_ptr->m_prev; return *this; }
			Iterator		operator-- (int)					{ Iterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_prev; return tmp; }

			bool			operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

		private:
			Node	*m_ptr;
		};

		class ReverseIterator
		{
		public:
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	std::ptrdiff_t					difference_type;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;

			ReverseIterator() : m_ptr(0) {}
			explicit ReverseIterator(Node *ptr) : m_ptr(ptr) {}

			reference				operator*  () const 						{ return m_ptr->m_value; }
			pointer					operator-> () const 						{ return m_ptr->m_value; }

			ReverseIterator&		operator++ ()								{ m_ptr = m_ptr->m_prev; return *this; }
			ReverseIterator			operator++ (int)							{ ReverseIterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_prev; return tmp; }

			ReverseIterator&		operator-- ()								{ m_ptr = m_ptr->m_next; return *this; }
			ReverseIterator			operator-- (int)							{ ReverseIterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_next; return tmp; }

			bool					operator== (const ReverseIterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool					operator!= (const ReverseIterator &other)	{ return this->m_ptr != other.m_ptr; }

		private:
			Node	*m_ptr;
		};

	};

	//Constructors and destructor
	template<typename T>
	list<T>::list()
		: m_size(0)
		, m_head(0)
		, m_tail(0) {}

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

	template<typename T>
	template<class InputIterator>
	list<T>::list(InputIterator first, typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last)
	{
		m_head = new Node(*first);
		++first;
		m_size = 1;
		Node *ptr = m_head;
		for (; first != last; ++first)
		{
			ptr->m_next = new Node(*first);
			ptr->m_next->m_prev = ptr;
			ptr = ptr->m_next;
			++m_size;
		}
		ptr->m_next = 0;
		m_tail = ptr;
	}

	template<typename T>
	list<T>::list(const list &x)
	{
		m_head = new Node(*x.begin());
		Node *ptr = m_head;
		m_size = x.m_size;

		iterator it = x.begin();
		++it;
		for (; it != x.end(); ++it)
		{
			ptr->m_next = new Node(*it);
			ptr->m_next->m_prev = ptr;
			ptr = ptr->m_next;
		}

		ptr->m_next = 0;
		m_tail = ptr;
	}

	template<typename T>
	list<T>::~list()
	{
		if (m_size > 0)
		{
			Node *ptr = m_head->m_next;
			for (; ptr; ptr = ptr->m_next)
				delete ptr->m_prev;
			delete m_tail;
		}
	}

	template<typename T>
	list<T> &list<T>::operator= (const list &x)
	{
		if (this != &x)
		{
			if (m_size > 0)
			{
				m_head = m_head->m_next;
				for (; m_head; m_head = m_head->m_next)
					delete m_head->m_prev;
				delete m_tail;
			}
			m_head = new Node(*x.begin());
			m_size = x.m_size;
			Node *ptr = m_head;
			iterator it = x.begin();
			++it;
			for (; it != x.end(); ++it)
			{
				ptr->m_next = new Node(*it);
				ptr->m_next->m_prev = ptr;
				ptr = ptr->m_next;
			}
			ptr->m_next = 0;
			m_tail = ptr;
		}
		return *this;
	}

	//Iterators
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

	template<typename T>
	typename list<T>::reverse_iterator list<T>::rbegin()
	{
		return ReverseIterator(m_tail);
	}

	template<typename T>
	typename list<T>::const_reverse_iterator list<T>::rbegin() const
	{
		return ReverseIterator(m_tail);
	}

	template<typename T>
	typename list<T>::reverse_iterator list<T>::rend()
	{
		return ReverseIterator(m_head->m_prev);
	}

	template<typename T>
	typename list<T>::const_reverse_iterator list<T>::rend() const
	{
		return ReverseIterator(m_head->m_prev);
	}

	//Capacity
	template<typename T>
	bool list<T>::empty() const
	{
		if (m_size == 0)
			return true;
		return false;
	}

	template<typename T>
	typename list<T>::size_type list<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	typename list<T>::size_type list<T>::max_size() const
	{
		return SIZE_T_MAX / sizeof(Node);
	}

	//Element access
	template<typename T>
	typename list<T>::reference list<T>::front()
	{
		return m_head->m_value;
	}

	template<typename T>
	typename list<T>::const_reference list<T>::front() const
	{
		return m_head->m_value;
	}

	template<typename T>
	typename list<T>::reference list<T>::back()
	{
		return m_tail->m_value;
	}

	template<typename T>
	typename list<T>::const_reference list<T>::back() const
	{
		return m_tail->m_value;
	}

	//Modifiers
	template<typename T>
		template<class InputIterator>
	void list<T>::assign(InputIterator first, typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last)
	{
		if (m_size > 0)
		{
			Node *ptr = m_head->m_next;
			for (; ptr; ptr = ptr->m_next)
				delete ptr->m_prev;
			delete m_tail;
			m_size = 0;
		}

		m_head = new Node(*first);
		Node *ptr = m_head;
		++first;

		for (; first != last; ++first)
		{
			ptr->m_next = new Node(*first);
			ptr->m_next->m_prev = ptr;
			ptr = ptr->m_next;
			++m_size;
		}

		ptr->m_next = 0;
		m_tail = ptr;
		++m_size;
	}

	template<typename T>
	void list<T>::assign(list::size_type n, const value_type &val)
	{
		if (m_size > 0)
		{
			Node *ptr = m_head->m_next;
			for (; ptr; ptr = ptr->m_next)
				delete ptr->m_prev;
			delete m_tail;
		}

		m_head = new Node(val);
		Node *ptr = m_head;
		m_size = 1;

		for (int i = 1; i < n; ++i)
		{
			ptr->m_next = new Node(val);
			ptr->m_next->m_prev = ptr;
			ptr = ptr->m_next;
			++m_size;
		}

		ptr->m_next = 0;
		m_tail = ptr;
		++m_size;
	}

	template<typename T>
	void list<T>::push_front(const value_type &val)
	{
		Node *ptr = new Node(val);

		ptr->m_next = m_head;
		m_head->m_prev = ptr;
		m_head = ptr;
		++m_size;
	}

	template<typename T>
	void list<T>::pop_front()
	{
		m_head = m_head->m_next;
		delete m_head->m_prev;
		--m_size;
	}

	template<typename T>
	void list<T>::push_back(const value_type &val)
	{
		m_tail->next = new Node(val);

		m_tail->m_next->prev = m_tail;
		m_tail = m_tail->m_next;
		m_tail->m_next = nullptr;
		++m_size;
	}

	template<typename T>
	void list<T>::pop_back()
	{
		m_tail = m_tail->m_prev;
		delete m_tail->m_next;
		m_tail->m_next = nullptr;
		--m_size;
	}
}

#endif
