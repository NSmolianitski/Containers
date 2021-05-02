//
// Created by Parfait Kentaurus on 4/8/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <sstream>

namespace ft
{
	template <bool, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <typename T>
	struct IsIterator
	{
		typedef char yes[1];
		typedef char no[2];

		template <typename Iterator>
			static yes& test(typename Iterator::iterator_category *) {};

		template <typename>
			static no& test(...) {};

		static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
	};

	template<typename T>
	class vector
	{
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

		/// CONSTRUCTORS, DESTRUCTOR
		vector();
		explicit vector (size_type n, const value_type& val = value_type());
		template <class InputIterator>
			vector (InputIterator first, typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last);
		vector (const vector& x);

		~vector();

		/// OPERATOR OVERLOAD
		vector&			operator=	(const vector& x);

		/// CAPACITY
		bool			empty		() const;
		size_type		size		() const;
		size_type		max_size	() const;
		void			resize		(size_type n, value_type val = value_type());
		size_type		capacity	() const;
		void			reserve		(size_type n);

		/// ELEMENT ACCESS
		reference		operator[]	(size_type n);
		const_reference	operator[]	(size_type n) const;
		reference		at			(size_type n);
		const_reference	at			(size_type n) const;
		reference		front		();
		const_reference	front		() const;
		reference		back		();
		const_reference	back		() const;

		/// MODIFIERS
		template <typename InputIterator>
			typename enable_if<IsIterator<InputIterator>::value, void>::type assign(InputIterator first, InputIterator last);

		void					assign		(size_type n, const value_type& val);
		void					push_back	(const value_type& val);
		void					pop_back	();
		void					clear		();
		void					swap		(vector& x);

		template <class InputIterator>
			typename enable_if<IsIterator<InputIterator>::value, void>::type insert
				(iterator position, InputIterator first, InputIterator last);

		iterator				insert		(iterator position, const value_type& val);
		void					insert		(iterator position, size_type n, const value_type& val);
		iterator				erase		(iterator position);
		iterator				erase		(iterator first, iterator last);


		/// ITERATORS
		iterator				begin		();
		const_iterator			begin		() const;
		iterator				end			();
		const_iterator			end			() const;
		reverse_iterator		rbegin		();
		const_reverse_iterator	rbegin		() const;
		reverse_iterator		rend		();
		const_reverse_iterator	rend		() const;

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
			explicit Iterator(pointer ptr) : m_ptr(ptr) {}

			reference		operator*  () const 				{ return *m_ptr; }
			pointer			operator-> () const 				{ return m_ptr; }
			reference		operator[] (int num) const 			{ return *(m_ptr + num); }

			size_type 		operator+  (const Iterator &other)	{ return (this->m_ptr + other.m_ptr); }
			Iterator		operator+  (int a)					{ Iterator it; it.m_ptr = m_ptr + a; return it; }
			Iterator&		operator+= (int a)					{ m_ptr += a; return *this; }
			Iterator&		operator++ ()						{ ++m_ptr; return *this; }
			Iterator		operator++ (int)					{ Iterator tmp = *this; ++(*this); return tmp; }

			size_type		operator-  (const Iterator &other)	{ return (this->m_ptr - other.m_ptr); }
			Iterator		operator-  (int a)					{ Iterator it; it.m_ptr = m_ptr - a; return it; }
			Iterator&		operator-= (int a)					{ m_ptr -= a; return *this; }
			Iterator&		operator-- ()						{ --m_ptr; return *this; }
			Iterator		operator-- (int)					{ Iterator tmp = *this; --(*this); return tmp; }

			bool			operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

			bool			operator>  (const Iterator &other)	{ return this->m_ptr > other.m_ptr; }
			bool			operator<  (const Iterator &other)	{ return this->m_ptr < other.m_ptr; }
			bool			operator>= (const Iterator &other)	{ return this->m_ptr >= other.m_ptr; }
			bool			operator<= (const Iterator &other)	{ return this->m_ptr <= other.m_ptr; }

		private:
			pointer	m_ptr;
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
			reference				operator[] (int num) const 					{ return *(m_ptr - num); }

			size_type 				operator+  (const ReverseIterator &other)	{ return (this->m_ptr - other.m_ptr); }
			ReverseIterator			operator+  (int a)							{ ReverseIterator it; it.m_ptr = m_ptr - a; return it; }
			ReverseIterator&		operator+= (int a)							{ m_ptr -= a; return *this; }
			ReverseIterator&		operator++ ()								{ --m_ptr; return *this; }
			ReverseIterator			operator++ (int)							{ ReverseIterator tmp = *this; --(*this); return tmp; }

			size_type				operator-  (const ReverseIterator &other)	{ return (this->m_ptr + other.m_ptr); }
			ReverseIterator			operator-  (int a)							{ ReverseIterator it; it.m_ptr = m_ptr + a; return it; }
			ReverseIterator&		operator-= (int a)							{ m_ptr += a; return *this; }
			ReverseIterator&		operator-- ()								{ ++m_ptr; return *this; }
			ReverseIterator			operator-- (int)							{ ReverseIterator tmp = *this; ++(*this); return tmp; }

			bool			operator== (const ReverseIterator &other)			{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const ReverseIterator &other)			{ return this->m_ptr != other.m_ptr; }

			bool			operator>  (const ReverseIterator &other)			{ return this->m_ptr > other.m_ptr; }
			bool			operator<  (const ReverseIterator &other)			{ return this->m_ptr < other.m_ptr; }
			bool			operator>= (const ReverseIterator &other)			{ return this->m_ptr >= other.m_ptr; }
			bool			operator<= (const ReverseIterator &other)			{ return this->m_ptr <= other.m_ptr; }

		private:
			pointer	m_ptr;
		};

		value_type				*m_array;
		size_type				m_size;
		size_type				m_capacity;

		/// UTILS
		size_type		getNearestPowerOfTwo(size_type x);
		/// COMPARISON
		friend bool operator== (const vector<T>& lhs, const vector<T>& rhs)
		{
			if (lhs.size() != rhs.size())
				return false;

			typename ft::vector<T>::iterator lhsIt = lhs.begin();
			typename ft::vector<T>::iterator rhsIt = rhs.begin();
			typename ft::vector<T>::iterator lhsItEnd = const_cast< vector<T> & >(lhs).end();
			typename ft::vector<T>::iterator rhsItEnd = const_cast< vector<T> & >(rhs).end();

			for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
			{
				if (*lhsIt != *rhsIt)
					return false;
			}
			return true;
		}

		friend bool operator!= (const vector<T>& lhs, const vector<T>& rhs)
		{
			if (lhs.size() != rhs.size())
				return true;

			typename ft::vector<T>::iterator lhsIt = lhs.begin();
			typename ft::vector<T>::iterator rhsIt = rhs.begin();
			typename ft::vector<T>::iterator lhsItEnd = const_cast< vector<T> & >(lhs).end();
			typename ft::vector<T>::iterator rhsItEnd = const_cast< vector<T> & >(rhs).end();

			for (; lhsIt != lhsItEnd && rhsIt != rhsItEnd; ++lhsIt, ++rhsIt)
			{
				if (*lhsIt != *rhsIt)
					return true;
			}
			return false;
		}

		friend bool operator<  (const vector<T>& lhs, const vector<T>& rhs)
		{
			typename ft::vector<T>::iterator lhsIt = lhs.begin();
			typename ft::vector<T>::iterator rhsIt = rhs.begin();
			typename ft::vector<T>::iterator lhsItEnd = const_cast< vector<T> & >(lhs).end();
			typename ft::vector<T>::iterator rhsItEnd = const_cast< vector<T> & >(rhs).end();

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

		friend bool operator<= (const vector<T>& lhs, const vector<T>& rhs)
		{
			typename ft::vector<T>::iterator lhsIt = lhs.begin();
			typename ft::vector<T>::iterator rhsIt = rhs.begin();
			typename ft::vector<T>::iterator lhsItEnd = const_cast< vector<T> & >(lhs).end();
			typename ft::vector<T>::iterator rhsItEnd = const_cast< vector<T> & >(rhs).end();

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

		friend bool operator>  (const vector<T>& lhs, const vector<T>& rhs)
		{
			typename ft::vector<T>::iterator lhsIt = lhs.begin();
			typename ft::vector<T>::iterator rhsIt = rhs.begin();
			typename ft::vector<T>::iterator lhsItEnd = const_cast< vector<T> & >(lhs).end();
			typename ft::vector<T>::iterator rhsItEnd = const_cast< vector<T> & >(rhs).end();

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

		friend bool operator>= (const vector<T>& lhs, const vector<T>& rhs)
		{
			typename ft::vector<T>::iterator lhsIt = lhs.begin();
			typename ft::vector<T>::iterator rhsIt = rhs.begin();
			typename ft::vector<T>::iterator lhsItEnd = const_cast< vector<T> & >(lhs).end();
			typename ft::vector<T>::iterator rhsItEnd = const_cast< vector<T> & >(rhs).end();

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
	};

	/// CONSTRUCTORS			************************************************************
	template<typename T>
	vector<T>::vector() : m_array(nullptr), m_size(0), m_capacity(0) {}

	template<typename T>
	vector<T>::vector(vector::size_type n, const value_type &val) : m_size(n), m_capacity(n)
	{
		m_array = new value_type [n];
		for (int i = 0; i < n; ++i)
			m_array[i] = val;
	}

	template<typename T>
	template<class InputIterator>
	vector<T>::vector (InputIterator first, typename enable_if<IsIterator<InputIterator>::value, InputIterator>::type last) : m_size(last - first), m_capacity(last - first)
	{
		m_array = new value_type [m_capacity];
		for (int i = 0; first != last; ++i)
		{
			m_array[i] = *first;
			++first;
		}
	}

	template<typename T>
	vector<T>::vector(const vector &x) : m_size(x.m_size), m_capacity(x.m_capacity)
	{
		m_array = new value_type [x.m_capacity];

		for (int i = 0; i < x.m_size; ++i)
			m_array[i] = x[i];
	}

	template<typename T>
	vector<T>::~vector()
	{
		delete [] m_array;
	}

	/// OPERATOR OVERLOAD	************************************************************
	template<typename T>
	vector<T> & vector<T>::operator=(const vector &x)
	{
		if (this != &x)
		{
			delete [] m_array;
			m_array = new value_type [x.m_size];
			m_size = x.m_size;
			m_capacity = x.m_capacity;

			for (int i = 0; i < x.m_size; ++i)
				m_array[i] = x[i];
		}
		return *this;
	}

	/// CAPACITY		************************************************************
	template<typename T>
	bool vector<T>::empty() const
	{
		if (m_size == 0)
			return true;
		return false;
	}

	template<typename T>
	typename vector<T>::size_type vector<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	typename vector<T>::size_type vector<T>::max_size() const
	{
		if (sizeof(T) == 1)
			return ULLONG_MAX / 2;
		return ULLONG_MAX / sizeof(T);
	}

	template<typename T>
	void vector<T>::resize(vector::size_type n, value_type val)
	{
		if (n < 0)
			throw std::length_error("vector");
		if (n > m_size)
		{
			if (n > m_capacity)
			{
				m_capacity = getNearestPowerOfTwo(n);
				if (n > 9)
					m_capacity = n;
				value_type *newArr = new value_type [m_capacity];
				for (int i = 0; i < m_size; ++i)
					newArr[i] = m_array[i];
				for (int i = m_size; i < n; ++i)
					newArr[i] = val;
				delete [] m_array;
				m_array = newArr;
			}
			else
			{
				for (int i = m_size; i < n; ++i)
					m_array[i] = val;
			}
			m_size = n;
		}
		else if (n < m_size)
		{
			for (int i = m_size - 1; i >= n; --i)
				m_array[i].~T();
			m_size = n;
		}
	}

	template<typename T>
	typename vector<T>::size_type vector<T>::capacity() const
	{
		return m_capacity;
	}

	/// ELEMENT ACCESS		************************************************************
	template<typename T>
	typename vector<T>::reference		vector<T>::operator[](vector::size_type n)
	{
		return m_array[n];
	}

	template<typename T>
	typename vector<T>::const_reference	vector<T>::operator[](vector::size_type n) const
	{
		return m_array[n];
	}

	template<typename T>
	typename vector<T>::reference		vector<T>::at(vector::size_type n)
	{
		std::ostringstream o;

		o << n;
		if (n < 0 || n >= m_size)
			throw std::out_of_range(o.str());
		return m_array[n];
	}

	template<typename T>
	typename vector<T>::const_reference	vector<T>::at(vector::size_type n) const
	{
		std::ostringstream o;

		o << n;
		if (n < 0 || n >= m_size)
			throw std::out_of_range(o.str());
		return m_array[n];
	}

	template<typename T>
	typename vector<T>::reference		vector<T>::front()
	{
		return m_array[0];
	}

	template<typename T>
	typename vector<T>::const_reference	vector<T>::front() const
	{
		return m_array[0];
	}

	template<typename T>
	typename vector<T>::reference		vector<T>::back()
	{
		return m_array[m_size - 1];
	}

	template<typename T>
	typename vector<T>::const_reference	vector<T>::back() const
	{
		return m_array[m_size - 1];
	}

	/// MODIFIERS		************************************************************
	template<typename T>
	void vector<T>::push_back (const value_type &val)
	{
		if (m_capacity == 0)
		{
			m_array = new value_type[1];
			m_array[0] = val;
			m_size = 1;
			m_capacity = 1;
		}
		else if (m_size + 1 > m_capacity)
		{
			m_capacity = getNearestPowerOfTwo(m_size + 1);
			value_type *newArr = new value_type [m_capacity];
			for (int i = 0; i < m_size; ++i)
				newArr[i] = m_array[i];
			delete [] m_array;
			m_array = newArr;
			m_array[m_size] = val;
			++m_size;
		}
		else
		{
			m_array[m_size] = val;
			++m_size;
		}
	}

	template<typename T>
	template<typename InputIterator>
		typename enable_if<IsIterator<InputIterator>::value, void>::type vector<T>::assign(InputIterator first, InputIterator last)
	{
		if ((last - first) > m_capacity)
		{
			delete [] m_array;
			m_capacity = last - first;
			m_size = m_capacity;
			m_array = new value_type[m_capacity];
		}
		for (int i = 0; first != last; ++i)
		{
			m_array[i] = *first;
			++first;
		}
	}

	template<typename T>
	void vector<T>::assign(vector::size_type n, const value_type &val)
	{
		if (n < 0)
			throw std::length_error("vector");
		if (n > m_capacity)
		{
			delete [] m_array;
			m_capacity = n;
			m_array = new value_type [m_capacity];
		}
		for (int i = 0; i < n; ++i)
			m_array[i] = val;
		m_size = n;
	}

	template<typename T>
	void vector<T>::pop_back()
	{
		m_array[m_size - 1].~T();
		--m_size;
	}

	/// UTILS		************************************************************
	template<typename T>
	typename vector<T>::size_type vector<T>::getNearestPowerOfTwo(size_type x)
	{
		--x;
		for (int p = 1; p < 32; p <<= 1)
			x |= (x >> p);
		return ++x;
	}

	template<typename T>
	void vector<T>::reserve(vector::size_type n)
	{
		if (n > m_capacity)
		{
			m_capacity = n;
			value_type *newArr = new value_type [m_capacity];
			for (int i = 0; i < m_size; ++i)
				newArr[i] = m_array[i];
			delete [] m_array;
			m_array = newArr;
		}
	}

	/// ITERATORS		************************************************************
	template<typename T>
	typename vector<T>::iterator vector<T>::begin()
	{
		return Iterator(&m_array[0]);
	}

	template<typename T>
	typename vector<T>::const_iterator vector<T>::begin() const
	{
		return Iterator(&m_array[0]);
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::end()
	{
		return Iterator(&m_array[m_size]);
	}

	template<typename T>
	typename vector<T>::const_iterator vector<T>::end() const
	{
		return Iterator(&m_array[m_size]);
	}

	template<typename T>
	typename vector<T>::reverse_iterator vector<T>::rbegin()
	{
		return ReverseIterator(&m_array[m_size - 1]);
	}

	template<typename T>
	typename vector<T>::const_reverse_iterator vector<T>::rbegin() const
	{
		return ReverseIterator(&m_array[m_size - 1]);
	}

	template<typename T>
	typename vector<T>::reverse_iterator vector<T>::rend()
	{
		return ReverseIterator(&m_array[-1]);
	}

	template<typename T>
	typename vector<T>::const_reverse_iterator vector<T>::rend() const
	{
		return ReverseIterator(&m_array[-1]);
	}

	template<typename T>
	void vector<T>::clear()
	{
		for (int i = 0; i < m_size; ++i)
			m_array[i].~T();
		m_size = 0;
	}

	template<typename T>
	void vector<T>::swap(vector &x)
	{
		value_type	*tmp_array   = x.m_array;
		size_type	tmp_size	 = x.m_size;
		size_type	tmp_capacity = x.m_capacity;

		x.m_array	 =	m_array;
		x.m_size	 =	m_size;
		x.m_capacity =	m_capacity;

		m_array		 = tmp_array;
		m_size		 = tmp_size;
		m_capacity	 = tmp_capacity;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::insert(vector::iterator position, const value_type &val)
	{
		if (m_size == m_capacity)
		{
			m_capacity = getNearestPowerOfTwo(m_size + 1);
			value_type *newArr = new value_type [m_capacity];
			int i = m_size;
			for (; i > (position - begin()); --i)
				newArr[i] = m_array[i - 1];
			newArr[i] = val;
			for (--i; i >= 0; --i)
				newArr[i] = m_array[i];
			delete [] m_array;
			m_array = newArr;
		}
		else
		{
			iterator it = end();
			for (; it >= position; --it)
				*it = *(it - 1);
			*position = val;
		}
		++m_size;
		return position;
	}

	template<typename T>
	void vector<T>::insert(vector::iterator position, vector::size_type n, const value_type &val)
	{
		if (m_size + n >= m_capacity)
		{
			m_capacity = getNearestPowerOfTwo(m_size + n + 1);
			value_type *newArr = new value_type [m_capacity];
			int i = m_size + n - 1;
			for (; i >= (position - begin() + n); --i)
				newArr[i] = m_array[i - n];
			for (int j = 0; j < n; ++j)
			{
				newArr[i] = val;
				--i;
			}
			for (; i >= 0; --i)
				newArr[i] = m_array[i];
			delete [] m_array;
			m_array = newArr;
		}
		else
		{
			iterator it = end() + n - 1;
			for (; it >= position + n; --it)
				*it = *(it - n);
			for (int i = 0; i < n; ++i)
			{
				*position = val;
				++position;
			}
		}
		m_size += n;
	}

	template<typename T>
	template<class InputIterator>
		typename enable_if<IsIterator<InputIterator>::value, void>::type vector<T>::insert
			(vector::iterator position, InputIterator first, InputIterator last)
	{
		if (first > last)
			return;
		size_type n = last - first;
		value_type tmpArr[n];
		for (int i = 0; i < n; ++i)
		{
			tmpArr[i] = *first;
			++first;
		}
		if (m_size + n >= m_capacity)
		{
			m_capacity = getNearestPowerOfTwo(m_size + n + 1);
			value_type *newArr = new value_type [m_capacity];
			int i = m_size + n - 1;
			for (; i >= (position - begin() + n); --i)
				newArr[i] = m_array[i - n];
			for (int j = static_cast<int>(n) - 1; j >= 0; --j)
			{
				newArr[i] = tmpArr[j];
				--i;
			}
			for (; i >= 0; --i)
				newArr[i] = m_array[i];
			delete [] m_array;
			m_array = newArr;
		}
		else
		{
			iterator it = end() + n - 1;
			for (; it >= position + n; --it)
				*it = *(it - n);
			for (int i = 0; i < n; ++i)
			{
				*position = tmpArr[i];
				++position;
			}
		}
		m_size += n;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::erase(vector::iterator position)
	{
		vector::iterator tmpPosition = position;
		(*position).~T();
		for (; position < end() - 1; ++position)
			*position = *(position + 1);
		--m_size;
		return tmpPosition;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::erase(vector::iterator first, vector::iterator last)
	{
		if (last < first)
			return first;
		vector::iterator tmpPosition = first;
		for (int i = 0; i < (last - first); ++i)
			(*(first + i)).~T();
		int i = 0;
		for (; first < last + 1; ++first)
		{
			*first = *(last + i);
			++i;
		}
		m_size -= last - tmpPosition;
		return tmpPosition;
	}
}

template <class T>
void swap (ft::vector<T> &x, ft::vector<T> &y)
{
	x.swap(y);
}

#endif

