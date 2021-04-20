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
		Node	m_end;
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
			void assign (InputIterator first,
				typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last);

		void assign		(size_type n, const value_type& val);
		void push_front	(const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();

		template <class InputIterator>
			void insert (iterator position, InputIterator first,
				typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last);

		iterator	insert	(iterator position, const value_type& val);
		void		insert	(iterator position, size_type n, const value_type& val);
		iterator	erase	(iterator position);
		iterator	erase	(iterator first, iterator last);
		void		swap	(list& x);
		void		resize	(size_type n, value_type val = value_type());
		void		clear	();
		void		splice	(iterator position, list& x);
		void		splice	(iterator position, list& x, iterator i);
		void		splice	(iterator position, list& x, iterator first, iterator last);
		void		remove	(const value_type& val);
		void		unique	();

		template <class BinaryPredicate>
			void	unique		(BinaryPredicate binary_pred);

		template <class Predicate>
			void	remove_if	(Predicate pred);

		void		merge		(list& x);
		template <class Compare>
			void	merge		(list& x, Compare comp);

		void		reverse		();
		void		sort		();

		template <class Compare>
			void	sort		(Compare comp);

	private:

		class Iterator
		{
		public:
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	std::ptrdiff_t					difference_type;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;

			Iterator() {}
			explicit Iterator(Node *ptr) : m_ptr(ptr) {}
			explicit Iterator(const Node *ptr) : m_ptr(const_cast<Node *> (ptr)) {}

			reference		operator*  () const 				{ return m_ptr->m_value; }
			pointer			operator-> () const 				{ return m_ptr->m_value; }

			Iterator&		operator++ ()						{ m_ptr = m_ptr->m_next; return *this; }
			Iterator		operator++ (int)					{ Iterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_next; return tmp; }

			Iterator&		operator-- ()						{ m_ptr = m_ptr->m_prev; return *this; }
			Iterator		operator-- (int)					{ Iterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_prev; return tmp; }

			bool			operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

			Node			*getNode   () 						{ return m_ptr; }

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

			ReverseIterator() {}
			explicit ReverseIterator(Node *ptr) : m_ptr(ptr) {}
			explicit ReverseIterator(const Node *ptr) : m_ptr(const_cast<Node *> (ptr)) {}

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

	//Relational operators
	template <class T>
		bool operator== (const list<T> &lhs, const list<T> &rhs);
	template <class T>
		bool operator!= (const list<T> &lhs, const list<T> &rhs);
	template <class T>
		bool operator<  (const list<T> &lhs, const list<T> &rhs);
	template <class T>
		bool operator<= (const list<T> &lhs, const list<T> &rhs);
	template <class T>
		bool operator>  (const list<T> &lhs, const list<T> &rhs);
	template <class T>
		bool operator>= (const list<T> &lhs, const list<T> &rhs);

	//Constructors and destructor
	template<typename T>
	list<T>::list()
		: m_size(0), m_head(&m_end), m_tail(&m_end) { m_tail->m_next = &m_end; }

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
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
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
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
	}

	template<typename T>
	list<T>::list(const list &x)
	{
		if (!x.m_head)
			return;
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
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
	}

	template<typename T>
	list<T>::~list()
	{
		for (; m_size > 0;)
			pop_back();
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
			m_tail->m_next = &m_end;
			m_end.m_prev = m_tail;
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
		return Iterator(&m_end);
	}

	template<typename T>
	typename list<T>::const_iterator list<T>::end() const
	{
		return Iterator(&m_end);
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
			clear();

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
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
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
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
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
		if (m_size == 0)
		{
			m_head = new Node(val);
			m_tail = m_head;
			m_tail->m_next = &m_end;
			m_end.m_prev = m_tail;
			++m_size;
			return;
		}
		m_tail->m_next = new Node(val);

		m_tail->m_next->m_prev = m_tail;
		m_tail = m_tail->m_next;
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
		++m_size;
	}

	template<typename T>
	void list<T>::pop_back()
	{
		if (m_size == 1)
		{
			delete m_tail;
			m_head = &m_end;
			m_tail = m_head;
			m_tail->m_next = &m_end;
			m_end.m_prev = m_tail;
			--m_size;
			return;
		}
		m_tail = m_tail->m_prev;
		delete m_tail->m_next;
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
		--m_size;
	}

	template<typename T>
		template<class InputIterator>
	void list<T>::insert(list::iterator position, InputIterator first, typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last)
	{
		Node *ptr = new Node(*first);
		if (first != last)
			++first;
		size_t newSize = 1;
		Node *head = ptr;

		for (; first != last; ++first)
		{
			ptr->m_next = new Node(*first);
			ptr->m_next->m_prev = ptr;
			ptr = ptr->m_next;
			++newSize;
		}
		Node *old = position.getNode();
		if (m_size == 0)
		{
			m_head = head;
			m_tail = ptr;
			m_tail->m_next = &m_end;
			m_end.m_prev = m_tail;
		}
		else if (old == m_head)
		{
			m_head->m_prev = ptr;
			ptr->m_next = m_head;
			m_head = head;
		}
		else if (old == m_tail->m_next)
		{
			m_tail->m_next = head;
			head->m_prev = m_tail;
			m_tail = ptr;
			m_tail->m_next = &m_end;
			m_end.m_prev = m_tail;
		}
		else
		{
			Node *oldPrev = old->m_prev;
			oldPrev->m_next = head;
			ptr->m_next = old;
			head->m_prev = oldPrev;
			old->m_prev = ptr;
		}
		m_size += newSize;
	}

	template<typename T>
	typename list<T>::iterator list<T>::insert(list::iterator position, const value_type &val)
	{
		Node *ptr = new Node(val);
		Node *old = position.getNode();

		if (m_size == 0)
			push_back(val);
		else
		{
			ptr->m_prev = old->m_prev;
			ptr->m_next = old;
			if (old != m_head)
				old->m_prev->m_next = ptr;
			else
				m_head = ptr;
			old->m_prev = ptr;
		}
		++m_size;
		iterator it(ptr);
		return it;
	}

	template<typename T>
	void list<T>::insert(list::iterator position, list::size_type n, const value_type &val)
	{
		Node *old = position.getNode();

		if (m_size == 0)
			for (int i = 0; i < n; ++i)
				push_back(val);
		else if (old == m_head)
			for (int i = 0; i < n; ++i)
				push_front(val);
		else
		{
			for (int i = 0; i < n; ++i)
			{
				Node *ptr = new Node(val);
				ptr->m_prev = old->m_prev;
				ptr->m_next = old;
				old->m_prev->m_next = ptr;
				old->m_prev = ptr;
			}
		}
		m_size += n;
	}

	template<typename T>
	typename list<T>::iterator list<T>::erase(list::iterator position)
	{
		Node *ptr = position.getNode();
		Node *prev = ptr->m_prev;
		Node *next = ptr->m_next;

		if (ptr == m_head)
			m_head = next;
		else
			prev->m_next = next;

		if (ptr == m_tail)
		{
			m_tail = prev;
			m_tail->m_next = &m_end;
			m_end.m_prev = m_tail;
		}
		else
			next->m_prev = prev;

		delete ptr;
		--m_size;
		return Iterator(next);
	}

	template<typename T>
	typename list<T>::iterator list<T>::erase(list::iterator first, list::iterator last)
	{
		Node *prev = first.getNode()->m_prev;
		Node *next = last.getNode();

		prev->m_next = next;
		next->m_prev = prev;

		for (; first != last; ++first)
		{
			delete first.getNode();
			--m_size;
		}

		return Iterator(next);
	}

	template<typename T>
	void list<T>::swap(list &x)
	{
		Node	*tmpHead = x.m_head;
		Node	*tmpTail = x.m_tail;
		size_t	tmpSize = x.m_size;

		x.m_head = m_head;
		x.m_tail = m_tail;
		x.m_size = m_size;
		x.m_tail->m_next = &x.m_end;
		x.m_end.m_prev = x.m_tail;

		m_head = tmpHead;
		m_tail = tmpTail;
		m_size = tmpSize;
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
	}

	template<typename T>
	void list<T>::resize(list::size_type n, value_type val)
	{
		if (n < m_size)
			for (; n < m_size;)
				pop_back();
		else if (n > m_size)
			for (; n > m_size;)
				push_back(val);
	}

	template<typename T>
	void list<T>::clear()
	{
		for (; m_size > 0;)
			pop_back();
	}

	template<typename T>
	void list<T>::splice(list::iterator position, list &x)
	{
		insert(position, x.begin(), x.end());
		x.clear();
	}

	template<typename T>
	void list<T>::splice(list::iterator position, list &x, list::iterator i)
	{
		insert(position, i, i);
		x.erase(i);
	}

	template<typename T>
	void list<T>::splice(list::iterator position, list &x, list::iterator first, list::iterator last)
	{
		insert(position, first, last);
		x.erase(first, last);
	}

	template<typename T>
	void list<T>::remove(const value_type &val)
	{
		for (iterator it = begin(); it != end(); ++it)
		{
			if (*it == val)
				erase(it);
		}
	}

	template<typename T>
	template<class Predicate>
	void list<T>::remove_if(Predicate pred)
	{
		for (iterator it = begin(); it != end(); ++it)
		{
			if (pred(*it))
			{
				erase(it);
				--it;
			}
		}
	}

	template<typename T>
	void list<T>::unique()
	{
		for (iterator it = begin(); it != end().operator--(); ++it)
		{
			iterator tmpIt = it;
			++tmpIt;
			if (*tmpIt == *it)
			{
				erase(it);
				--it;
			}
		}
	}

	template<typename T>
	template<class BinaryPredicate>
	void list<T>::unique(BinaryPredicate binary_pred)
	{
		for (iterator it = begin(); it != end().operator--(); ++it)
		{
			iterator tmpIt = it;
			++tmpIt;
			if (binary_pred(*it, *tmpIt))
			{
				erase(tmpIt);
				--it;
			}
		}
	}

	template<typename T>
	void list<T>::merge(list &x)
	{
		iterator it = begin();
		for (iterator itX = x.begin(); itX != x.end(); ++itX)
		{
			for (; it != end(); ++it)
			{
				if (*it > *itX)
				{
					insert(it, *itX);
					break;
				}
			}
		}
		x.clear();
	}

	template<typename T>
	template<class Compare>
	void list<T>::merge(list &x, Compare comp)
	{
		iterator it = begin();
		for (iterator itX = x.begin(); itX != x.end(); ++itX)
		{
			for (; it != end(); ++it)
			{
				if (comp(*itX, *it))
				{
					insert(it, *itX);
					break;
				}
			}
		}
		x.clear();
	}

	template<typename T>
	void list<T>::reverse()
	{
		Node *ptr = m_head->m_prev;
		m_tail = m_head;
		m_end.m_prev = m_tail;
		for (int i = 0; i < m_size; ++i)
		{
			m_head->m_prev = m_head->m_next;
			m_head->m_next = ptr;
			if (m_head->m_prev != &m_end)
				m_head = m_head->m_prev;
			ptr = m_head->m_prev;
		}
		m_tail->m_next = &m_end;
		m_head->m_prev = nullptr;
	}

	template<typename T>
	void list<T>::sort()
	{
		for (iterator it = begin(); it != end().operator--(); ++it)
		{
			iterator tmpIt = it;
			++tmpIt;
			if (*it > *tmpIt)
			{
				Node *left = it.getNode();
				Node *right = tmpIt.getNode();

				left->m_next = right->m_next;
				right->m_next->m_prev = left;
				right->m_next = left;

				right->m_prev = left->m_prev;
				if (left != m_head)
					left->m_prev->m_next = right;
				left->m_prev = right;

				if (left == m_head)
					m_head = right;
				if (right == m_tail)
					m_tail = left;
				it = begin();
			}
		}
	}

	template<typename T>
	template<class Compare>
	void list<T>::sort(Compare comp)
	{
		for (iterator it = begin(); it != end().operator--(); ++it)
		{
			iterator tmpIt = it;
			++tmpIt;
			if (comp(*tmpIt, *it))
			{
				Node *left = it.getNode();
				Node *right = tmpIt.getNode();

				left->m_next = right->m_next;
				right->m_next->m_prev = left;
				right->m_next = left;

				right->m_prev = left->m_prev;
				if (left != m_head)
					left->m_prev->m_next = right;
				left->m_prev = right;

				if (left == m_head)
					m_head = right;
				if (right == m_tail)
					m_tail = left;
				it = begin();
			}
		}
	}

	template<typename T>
	bool operator==(const list<T> &lhs, const list<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		typename ft::list<T>::iterator lhsIt = lhs.begin();
		typename ft::list<T>::iterator rhsIt = rhs.begin();
		typename ft::list<T>::iterator lhsItEnd = const_cast< list<T> & >(lhs).end();
		typename ft::list<T>::iterator rhsItEnd = const_cast< list<T> & >(rhs).end();

		for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
		{
			if (*lhsIt != *rhsIt)
				return false;
		}
		return true;
	}

	template<typename T>
	bool operator!=(const list<T> &lhs, const list<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return true;

		typename ft::list<T>::iterator lhsIt = lhs.begin();
		typename ft::list<T>::iterator rhsIt = rhs.begin();
		typename ft::list<T>::iterator lhsItEnd = const_cast< list<T> & >(lhs).end();
		typename ft::list<T>::iterator rhsItEnd = const_cast< list<T> & >(rhs).end();

		for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
		{
			if (*lhsIt != *rhsIt)
				return true;
		}
		return false;
	}

	template<typename T>
	bool operator<(const list<T> &lhs, const list<T> &rhs)
	{
		typename ft::list<T>::iterator lhsIt = lhs.begin();
		typename ft::list<T>::iterator rhsIt = rhs.begin();
		typename ft::list<T>::iterator lhsItEnd = const_cast< list<T> & >(lhs).end();
		typename ft::list<T>::iterator rhsItEnd = const_cast< list<T> & >(rhs).end();

		for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
		{
			if (*lhsIt < *rhsIt)
				return true;
			else if (*lhsIt > *rhsIt)
				return false;
		}
		if (lhs.size() < rhs.size())
			return true;
		return false;
	}

	template<typename T>
	bool operator<=(const list<T> &lhs, const list<T> &rhs)
	{
		typename ft::list<T>::iterator lhsIt = lhs.begin();
		typename ft::list<T>::iterator rhsIt = rhs.begin();
		typename ft::list<T>::iterator lhsItEnd = const_cast< list<T> & >(lhs).end();
		typename ft::list<T>::iterator rhsItEnd = const_cast< list<T> & >(rhs).end();

		for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
		{
			if (*lhsIt < *rhsIt)
				return true;
			else if (*lhsIt > *rhsIt)
				return false;
		}
		if (lhs.size() <= rhs.size())
			return true;
		return false;
	}

	template<typename T>
	bool operator>(const list<T> &lhs, const list<T> &rhs)
	{
		typename ft::list<T>::iterator lhsIt = lhs.begin();
		typename ft::list<T>::iterator rhsIt = rhs.begin();
		typename ft::list<T>::iterator lhsItEnd = const_cast< list<T> & >(lhs).end();
		typename ft::list<T>::iterator rhsItEnd = const_cast< list<T> & >(rhs).end();

		for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
		{
			if (*lhsIt > *rhsIt)
				return true;
			else if (*lhsIt < *rhsIt)
				return false;
		}
		if (lhs.size() > rhs.size())
			return true;
		return false;
	}

	template<typename T>
	bool operator>=(const list<T> &lhs, const list<T> &rhs)
	{
		typename ft::list<T>::iterator lhsIt = lhs.begin();
		typename ft::list<T>::iterator rhsIt = rhs.begin();
		typename ft::list<T>::iterator lhsItEnd = const_cast< list<T> & >(lhs).end();
		typename ft::list<T>::iterator rhsItEnd = const_cast< list<T> & >(rhs).end();

		for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
		{
			if (*lhsIt > *rhsIt)
				return true;
			else if (*lhsIt < *rhsIt)
				return false;
		}
		if (lhs.size() >= rhs.size())
			return true;
		return false;
	}
}

template <class T>
void swap (ft::list<T> &x, ft::list<T> &y)
{
	x.swap(y);
}

#endif
