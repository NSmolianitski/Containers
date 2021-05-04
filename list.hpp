#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP

#include "vector.hpp"
#include "utils.hpp"

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
		Node	m_rend;

		size_t	m_size;

		class Iterator;
		class ConstIterator;
		class ReverseIterator;
		class ConstReverseIterator;

	public:

		typedef T						value_type;
		typedef std::size_t 			size_type;
		typedef T&						reference;
		typedef const T&				const_reference;
		typedef	Iterator				iterator;
		typedef	ConstIterator			const_iterator;
		typedef	ReverseIterator			reverse_iterator;
		typedef	ConstReverseIterator	const_reverse_iterator;
		typedef	T*						pointer;
		typedef	const T*				const_pointer;
		typedef	std::ptrdiff_t			difference_type;

		//Constructors and destructor
		template<class InputIterator>
			list		(InputIterator first, typename enable_if<IsIteratorOrPointer<InputIterator>::value, InputIterator>::type last);

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
				typename enable_if<IsIteratorOrPointer<InputIterator>::value, InputIterator>::type last);

		void assign		(size_type n, const value_type& val);
		void push_front	(const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();

		template <class InputIterator>
			void insert (iterator position, InputIterator first,
				typename enable_if<IsIteratorOrPointer<InputIterator>::value, InputIterator>::type last);

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
		void swapNodes	(iterator& leftIt, iterator& rightIt);
		void fixEndRend	();

		class Iterator
		{
		public:
			typedef	std::bidirectional_iterator_tag	iterator_category;

			Iterator() {}
			Iterator(Node *ptr) : m_ptr(ptr) {}
			Iterator(const Iterator& it) : m_ptr(it.m_ptr) {}

			reference		operator*  () const 				{ return m_ptr->m_value; }
			pointer			operator-> () const 				{ return &m_ptr->m_value; }

			Iterator&		operator++ ()						{ m_ptr = m_ptr->m_next; return *this; }
			Iterator		operator++ (int)					{ Iterator tmp = *this; m_ptr = m_ptr->m_next; return tmp; }

			Iterator&		operator-- ()						{ m_ptr = m_ptr->m_prev; return *this; }
			Iterator		operator-- (int)					{ Iterator tmp = *this; m_ptr = m_ptr->m_prev; return tmp; }

			bool			operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

			Node			*getNode   () const					{ return m_ptr; }

		private:
			Node	*m_ptr;
		};
		class ConstIterator
		{
		public:
			typedef	std::bidirectional_iterator_tag	iterator_category;

			ConstIterator() {}
			ConstIterator(Node *ptr) : m_ptr(ptr) {}
			ConstIterator(const Iterator& it) : m_ptr(it.getNode()) {}

			const_reference			operator*  () const	{ return m_ptr->m_value; }
			const_pointer			operator-> () const	{ return &m_ptr->m_value; }

			ConstIterator&	operator++ ()		{ m_ptr = m_ptr->m_next; return *this; }
			ConstIterator	operator++ (int)	{ ConstIterator tmp = *this; m_ptr = m_ptr->m_next; return tmp; }

			ConstIterator&	operator-- ()		{ m_ptr = m_ptr->m_prev; return *this; }
			ConstIterator	operator-- (int)	{ ConstIterator tmp = *this; m_ptr = m_ptr->m_prev; return tmp; }

			bool	operator== (const ConstIterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool	operator!= (const ConstIterator &other)	{ return this->m_ptr != other.m_ptr; }

			Node *getNode() const { return m_ptr; }

		private:
			Node	*m_ptr;
		};

		class ReverseIterator
		{
		public:
			typedef	std::bidirectional_iterator_tag	iterator_category;

			ReverseIterator() {}
			ReverseIterator(Node *ptr) : m_ptr(ptr) {}
			ReverseIterator(const ReverseIterator& it) : m_ptr(it.m_ptr) {}
			ReverseIterator(const Iterator& it) : m_ptr(it.getNode()) {}

			reference			operator*  () const 						{ return m_ptr->m_value; }
			pointer				operator-> () const 						{ return m_ptr->m_value; }

			ReverseIterator&	operator++ ()								{ m_ptr = m_ptr->m_prev; return *this; }
			ReverseIterator		operator++ (int)							{ ReverseIterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_prev; return tmp; }

			ReverseIterator&	operator-- ()								{ m_ptr = m_ptr->m_next; return *this; }
			ReverseIterator		operator-- (int)							{ ReverseIterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_next; return tmp; }

			bool				operator== (const ReverseIterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool				operator!= (const ReverseIterator &other)	{ return this->m_ptr != other.m_ptr; }

			Node	*getNode   () const	{ return m_ptr; }

		private:
			Node	*m_ptr;
		};
		class ConstReverseIterator
		{
		public:
			typedef	std::bidirectional_iterator_tag	iterator_category;

			ConstReverseIterator() {}
			ConstReverseIterator(Node *ptr) : m_ptr(ptr) {}
			ConstReverseIterator(const ReverseIterator& it) : m_ptr(it.getNode()) {}
			ConstReverseIterator(const Iterator& it) : m_ptr(it.getNode()) {}

			const_reference			operator*  () const { return m_ptr->m_value; }
			const_pointer			operator-> () const { return m_ptr->m_value; }

			ConstReverseIterator&	operator++ ()		{ m_ptr = m_ptr->m_prev; return *this; }
			ConstReverseIterator	operator++ (int)	{ ConstReverseIterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_prev; return tmp; }

			ConstReverseIterator&	operator-- ()		{ m_ptr = m_ptr->m_next; return *this; }
			ConstReverseIterator	operator-- (int)	{ ConstReverseIterator tmp = *this; tmp.m_ptr = tmp.m_ptr->m_next; return tmp; }

			bool	operator== (const ConstReverseIterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool	operator!= (const ConstReverseIterator &other)	{ return this->m_ptr != other.m_ptr; }

			Node *getNode() const { return m_ptr; }
			
		private:
			Node	*m_ptr;
		};

		friend bool operator== (const list<T>& lhs, const list<T>& rhs)
		{
			if (lhs.m_size != rhs.m_size)
				return false;
			const_iterator itR = rhs.begin();
			for (const_iterator itL = lhs.begin(); itL != lhs.end(); ++itL, ++itR)
			{
				if (*itL != *itR)
					return false;
			}
			return true;
		}
		friend bool operator!= (const list<T>& lhs, const list<T>& rhs)
		{
			if (lhs.size() != rhs.size())
				return true;
			const_iterator itR = rhs.begin();
			for (const_iterator itL = lhs.begin(); itL != lhs.end(); ++itL, ++itR)
			{
				if (*itL != *itR)
					return true;
			}
			return false;
		}
		friend bool operator<  (const list<T>& lhs, const list<T>& rhs)
		{
			return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		friend bool operator<= (const list<T>& lhs, const list<T>& rhs)	{ return !(rhs < lhs); }
		friend bool operator>  (const list<T>& lhs, const list<T>& rhs)	{ return rhs < lhs; }
		friend bool operator>= (const list<T>& lhs, const list<T>& rhs)	{ return !(lhs < rhs); }

	};

	//Constructors and destructor
	template<typename T>
	list<T>::list()
		: m_head(&m_end), m_tail(&m_end), m_size(0)
	{
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
		m_rend.m_next = m_head;
	}

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
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
	}

	template<typename T>
	template<class InputIterator>
	list<T>::list(InputIterator first, typename enable_if<IsIteratorOrPointer<InputIterator>::value, InputIterator>::type last)
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
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
	}

	template<typename T>
	list<T>::list(const list &x)
			: m_head(&m_end), m_tail(&m_end), m_size(0)
	{
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
		m_rend.m_next = m_head;
		*this = x;
	}

	template<typename T>
	list<T>::~list()
	{
		clear();
	}

	template<typename T>
	list<T> &list<T>::operator= (const list &x)
	{
		if (this != &x)
		{
			if (m_size > 0)
				clear();
			if (x.m_size > 0)
			{
				m_head = new Node(*x.begin());
				m_size = x.m_size;
				Node* ptr = m_head;
				const_iterator it = x.begin();
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
				m_head->m_prev = &m_rend;
				m_rend.m_next = m_head;
			}
		}
		return *this;
	}

	//Iterators
	template<typename T>
	typename list<T>::iterator list<T>::begin()
	{
		return iterator(m_head);
	}

	template<typename T>
	typename list<T>::const_iterator list<T>::begin() const
	{
		return const_iterator(m_head);
	}

	template<typename T>
	typename list<T>::iterator list<T>::end()
	{
		return iterator(&m_end);
	}

	template<typename T>
	typename list<T>::const_iterator list<T>::end() const
	{
		return const_iterator(const_cast<Node *>(&m_end));
	}

	template<typename T>
	typename list<T>::reverse_iterator list<T>::rbegin()
	{
		return reverse_iterator(m_tail);
	}

	template<typename T>
	typename list<T>::const_reverse_iterator list<T>::rbegin() const
	{
		return const_reverse_iterator(m_tail);
	}

	template<typename T>
	typename list<T>::reverse_iterator list<T>::rend()
	{
		return reverse_iterator(&m_rend);
	}

	template<typename T>
	typename list<T>::const_reverse_iterator list<T>::rend() const
	{
		return const_reverse_iterator(&m_rend);
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
	void list<T>::assign(InputIterator first, typename enable_if<IsIteratorOrPointer<InputIterator>::value, InputIterator>::type last)
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
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
		++m_size;
	}

	template<typename T>
	void list<T>::assign(list::size_type n, const value_type &val)
	{
		if (m_size > 0)
			clear();

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
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
	}

	template<typename T>
	void list<T>::push_front(const value_type &val)
	{
		Node *ptr = new Node(val);

		ptr->m_next = m_head;
		m_head->m_prev = ptr;
		m_head = ptr;
		++m_size;
		if (m_tail == &m_end)
			m_tail = m_head;
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
	}

	template<typename T>
	void list<T>::pop_front()
	{
		m_head = m_head->m_next;
		delete m_head->m_prev;
		--m_size;
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
	}

	template<typename T>
	void list<T>::fixEndRend()
	{
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
	}

	template<typename T>
	void list<T>::push_back(const value_type &val)
	{
		if (m_size == 0)
		{
			m_head = new Node(val);
			m_tail = m_head;
		}
		else
		{
			m_tail->m_next = new Node(val);
			m_tail->m_next->m_prev = m_tail;
			m_tail = m_tail->m_next;
		}
		fixEndRend();
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
			m_tail->m_next = m_head;
			m_end.m_prev = m_head;
			m_head->m_prev = &m_rend;
			m_rend.m_next = m_head;
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
	void list<T>::insert(list::iterator position, InputIterator first, typename enable_if<IsIteratorOrPointer<InputIterator>::value, InputIterator>::type last)
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
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
		m_size += newSize;
	}

	template<typename T>
	typename list<T>::iterator list<T>::insert(list::iterator position, const value_type &val)
	{
		Node* newNode = new Node(val);
		Node* beforePos = position.getNode()->m_prev;

		beforePos->m_next = newNode;
		newNode->m_prev = beforePos;

		position.getNode()->m_prev = newNode;
		newNode->m_next = position.getNode();

		iterator newElement(newNode);

		if (m_head == position.getNode())
			m_head = newNode;

		if (m_size == 0)
			m_tail = newNode;

		fixEndRend();
		++m_size;
		return newElement;
	}

	template<typename T>
	void list<T>::insert(list::iterator position, list::size_type n, const value_type &val)
	{
		for (size_type i = 0; i < n; ++i)
			position = insert(position, val);
	}

	template<typename T>
	typename list<T>::iterator list<T>::erase(list::iterator position)
	{
		Node *ptr = position.getNode();
		Node *prev = ptr->m_prev;
		Node *next = ptr->m_next;

		if (ptr == m_head)
		{
			m_head = next;
			prev = m_head;
		}
		else
			prev->m_next = next;

		if (ptr == m_tail)
			m_tail = prev;
		else
			next->m_prev = prev;

		fixEndRend();
		delete ptr;
		--m_size;
		return Iterator(next);
	}

	template<typename T>
	typename list<T>::iterator list<T>::erase(list::iterator first, list::iterator last)
	{
		iterator it;

		for (; first != last; ++first)
			it = erase(first);

		return it;
	}

	template<typename T>
	void list<T>::swap(list &x)
	{
		Node	*tmpHead	= x.m_head;
		Node	*tmpTail	= x.m_tail;
		size_t	tmpSize		= x.m_size;

		x.m_head = m_head;
		if (m_head == &m_end)
			x.m_head = &x.m_end;
		x.m_tail = m_tail;
		if (m_tail == &m_end)
			x.m_tail = &x.m_end;
		x.m_size = m_size;
		x.m_tail->m_next = &x.m_end;
		x.m_end.m_prev = x.m_tail;

		m_head = tmpHead;
		if (tmpHead == &x.m_end)
			m_head = &m_end;
		m_tail = tmpTail;
		if (tmpTail == &x.m_end)
			m_tail = &m_end;
		m_size = tmpSize;
		m_tail->m_next = &m_end;
		m_end.m_prev = m_tail;
		m_head->m_prev = &m_rend;
		m_rend.m_next = m_head;
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
		while (m_size > 0)
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
		iterator it = begin();
		while (it != end())
		{
			if (*it == val)
			{
				erase(it);
				it = begin();
				continue;
			}
			++it;
		}
	}

	template<typename T>
	template<class Predicate>
	void list<T>::remove_if(Predicate pred)
	{
		iterator it = begin();
		while (it != end())
		{
			if (pred(*it))
			{
				erase(it);
				it = begin();
				continue;
			}
			++it;
		}
	}

	template<typename T>
	void list<T>::unique()
	{
		iterator it = begin();
		while (it != end())
		{
			iterator tmpIt = it;
			++tmpIt;
			if (tmpIt != end() && *tmpIt == *it)
			{
				erase(it);
				it = begin();
				continue;
			}
			++it;
		}
	}

	template<typename T>
	template<class BinaryPredicate>
	void list<T>::unique(BinaryPredicate binary_pred)
	{
		iterator it = begin();
		while (it != end())
		{
			iterator tmpIt = it;
			++tmpIt;
			if (tmpIt != end() && binary_pred(*it, *tmpIt))
			{
				erase(tmpIt);
				it = begin();
				continue;
			}
			++it;
		}
	}

	template<typename T>
	void list<T>::merge(list &x)
	{
		for (iterator itX = x.begin(); itX != x.end(); ++itX)
			push_back(*itX);
		sort();
		x.clear();
	}

	template<typename T>
	template<class Compare>
	void list<T>::merge(list &x, Compare comp)
	{
		for (iterator itX = x.begin(); itX != x.end(); ++itX)
			push_back(*itX);
		sort(comp);
		x.clear();
	}

	template<typename T>
	void list<T>::reverse()
	{
		if (m_size == 0)
			return;

		iterator itBegin	= begin();
		iterator itEnd		= end();
		--itEnd;

		iterator tmpBegin;
		iterator tmpEnd;

		while (itBegin != itEnd)
		{
			tmpBegin = itBegin;
			tmpEnd	 = itEnd;
			++itBegin, --itEnd;
			swapNodes(tmpBegin, tmpEnd);
			if (tmpEnd.getNode()->m_next == tmpBegin.getNode())
				break;
		}
	}

	template<typename T>
	void list<T>::swapNodes(list::iterator& leftIt, list::iterator& rightIt)
	{
		Node *left = leftIt.getNode();
		Node *right = rightIt.getNode();

		Node* leftNext = left->m_next;
		Node* leftPrev = left->m_prev;

		left->m_next = right->m_next;
		left->m_next->m_prev = left;
		right->m_next = leftNext;
		leftNext->m_prev = right;

		left->m_prev = right->m_prev;
		left->m_prev->m_next = left;
		right->m_prev = leftPrev;
		leftPrev->m_next = right;

		if (m_head == left)
		{
			m_head = right;
			m_rend.m_next = right;
		}
		if (m_tail == right)
		{
			m_tail = left;
			m_end.m_prev = left;
		}
	}

	template<typename T>
	void list<T>::sort()
	{
		iterator it = begin();
		while (it != end())
		{
			iterator tmpIt = it;
			++tmpIt;
			if (tmpIt != end() && *tmpIt < *it)
			{
				swapNodes(it, tmpIt);
				it = begin();
				continue;
			}
			++it;
		}
	}

	template<typename T>
	template<class Compare>
	void list<T>::sort(Compare comp)
	{
		iterator it = begin();
		while (it != end())
		{
			iterator tmpIt = it;
			++tmpIt;
			if (tmpIt != end() && comp(*tmpIt, *it))
			{
				swapNodes(it, tmpIt);
				it = begin();
				continue;
			}
			++it;
		}
	}
}

template <class T>
void swap (ft::list<T> &x, ft::list<T> &y)
{
	x.swap(y);
}

#endif
