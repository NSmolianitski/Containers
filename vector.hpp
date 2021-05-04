//
// Created by Parfait Kentaurus on 4/8/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "utils.hpp"

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
	struct IsIteratorOrPointer
	{
		typedef char yes[1];
		typedef char yesPtr[1];
		typedef char no[2];

		template <typename Iterator>
			static yes& test(typename Iterator::iterator_category *) {};
		template <typename Pointer>
			static yesPtr& test(Pointer) {};

		template <typename>
			static no& test(...) {};

		static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
	};

	template<typename T>
	class vector
	{
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
		typedef	std::ptrdiff_t			difference_type;
		typedef	T*						pointer;
		typedef	const T*				const_pointer;

		/// CONSTRUCTORS, DESTRUCTOR
		vector();
		explicit vector (size_type n, const value_type& val = value_type());
		template <class InputIterator>
			vector (InputIterator first, typename enable_if<IsIteratorOrPointer<InputIterator>::value, InputIterator>::type last);
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
			typename enable_if<IsIteratorOrPointer<InputIterator>::value, void>::type
										assign(InputIterator first, InputIterator last);

		void					assign		(size_type n, const value_type& val);
		void					push_back	(const value_type& val);
		void					pop_back	();
		void					clear		();
		void					swap		(vector& x);

		template <class InputIterator>
			typename enable_if<IsIteratorOrPointer<InputIterator>::value, void>::type insert
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

			Iterator() : m_ptr(0) {}
			Iterator(pointer ptr) : m_ptr(ptr) {}
			Iterator(const Iterator& it) : m_ptr(it.m_ptr) {}

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

			bool	operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool	operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

			bool	operator>  (const Iterator &other)	{ return this->m_ptr > other.m_ptr; }
			bool	operator<  (const Iterator &other)	{ return this->m_ptr < other.m_ptr; }
			bool	operator>= (const Iterator &other)	{ return this->m_ptr >= other.m_ptr; }
			bool	operator<= (const Iterator &other)	{ return this->m_ptr <= other.m_ptr; }

			pointer			getPointer() const { return m_ptr; }

		private:
			pointer	m_ptr;
		};

		class ConstIterator
		{
		public:
			typedef	std::random_access_iterator_tag	iterator_category;

			ConstIterator() : m_ptr(0) {}
			ConstIterator(pointer ptr) : m_ptr(ptr) {}
			ConstIterator(const Iterator& it) : m_ptr(it.getPointer()) {}

			const_reference	operator*  () const 				{ return *m_ptr; }
			const_pointer	operator-> () const 				{ return m_ptr; }
			const_reference	operator[] (int num) const 			{ return *(m_ptr + num); }

			size_type 		operator+  (const Iterator &other)	{ return (this->m_ptr + other.m_ptr); }
			ConstIterator	operator+  (int a)					{ ConstIterator it; it.m_ptr = m_ptr + a; return it; }
			ConstIterator&	operator+= (int a)					{ m_ptr += a; return *this; }
			ConstIterator&	operator++ ()						{ ++m_ptr; return *this; }
			ConstIterator	operator++ (int)					{ ConstIterator tmp = *this; ++(*this); return tmp; }

			size_type		operator-  (const Iterator &other)	{ return (this->m_ptr - other.m_ptr); }
			ConstIterator	operator-  (int a)					{ ConstIterator it; it.m_ptr = m_ptr - a; return it; }
			ConstIterator&	operator-= (int a)					{ m_ptr -= a; return *this; }
			ConstIterator&	operator-- ()						{ --m_ptr; return *this; }
			ConstIterator	operator-- (int)					{ ConstIterator tmp = *this; --(*this); return tmp; }

			bool	operator== (const ConstIterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool	operator!= (const ConstIterator &other)	{ return this->m_ptr != other.m_ptr; }

			bool	operator>  (const ConstIterator &other)	{ return this->m_ptr > other.m_ptr; }
			bool	operator<  (const ConstIterator &other)	{ return this->m_ptr < other.m_ptr; }
			bool	operator>= (const ConstIterator &other)	{ return this->m_ptr >= other.m_ptr; }
			bool	operator<= (const ConstIterator &other)	{ return this->m_ptr <= other.m_ptr; }

		private:
			pointer	m_ptr;
		};

		class ReverseIterator
		{
		public:
			typedef	std::random_access_iterator_tag	iterator_category;

			ReverseIterator() : m_ptr(0) {}
			ReverseIterator(pointer ptr) : m_ptr(ptr) {}
			ReverseIterator(const ReverseIterator& it) : m_ptr(it.m_ptr) {}

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

			bool	operator== (const ReverseIterator &other)			{ return this->m_ptr == other.m_ptr; }
			bool	operator!= (const ReverseIterator &other)			{ return this->m_ptr != other.m_ptr; }

			bool	operator>  (const ReverseIterator &other)			{ return this->m_ptr > other.m_ptr; }
			bool	operator<  (const ReverseIterator &other)			{ return this->m_ptr < other.m_ptr; }
			bool	operator>= (const ReverseIterator &other)			{ return this->m_ptr >= other.m_ptr; }
			bool	operator<= (const ReverseIterator &other)			{ return this->m_ptr <= other.m_ptr; }

			pointer	getPointer() const { return m_ptr; }

		private:
			pointer	m_ptr;
		};

		class ConstReverseIterator
		{
		public:
			typedef	std::random_access_iterator_tag	iterator_category;

			ConstReverseIterator() : m_ptr(0) {}
			ConstReverseIterator(pointer ptr) : m_ptr(ptr) {}
			ConstReverseIterator(const ReverseIterator& it) : m_ptr(it.getPointer()) {}

			const_reference	operator*  () const 		{ return *m_ptr; }
			const_pointer	operator-> () const 		{ return m_ptr; }
			const_reference	operator[] (int num) const 	{ return *(m_ptr - num); }

			size_type 				operator+  (const ReverseIterator &other)		{ return (this->m_ptr - other.m_ptr); }
			ConstReverseIterator	operator+  (int a)								{ ConstReverseIterator it; it.m_ptr = m_ptr - a; return it; }
			ConstReverseIterator&	operator+= (int a)								{ m_ptr -= a; return *this; }
			ConstReverseIterator&	operator++ ()									{ --m_ptr; return *this; }
			ConstReverseIterator	operator++ (int)								{ ConstReverseIterator tmp = *this; --(*this); return tmp; }

			size_type				operator-  (const ConstReverseIterator &other)	{ return (this->m_ptr + other.m_ptr); }
			ConstReverseIterator	operator-  (int a)								{ ConstReverseIterator it; it.m_ptr = m_ptr + a; return it; }
			ConstReverseIterator&	operator-= (int a)								{ m_ptr += a; return *this; }
			ConstReverseIterator&	operator-- ()									{ ++m_ptr; return *this; }
			ConstReverseIterator	operator-- (int)								{ ConstReverseIterator tmp = *this; ++(*this); return tmp; }

			bool	operator== (const ConstReverseIterator &other)			{ return this->m_ptr == other.m_ptr; }
			bool	operator!= (const ConstReverseIterator &other)			{ return this->m_ptr != other.m_ptr; }

			bool	operator>  (const ConstReverseIterator &other)			{ return this->m_ptr > other.m_ptr; }
			bool	operator<  (const ConstReverseIterator &other)			{ return this->m_ptr < other.m_ptr; }
			bool	operator>= (const ConstReverseIterator &other)			{ return this->m_ptr >= other.m_ptr; }
			bool	operator<= (const ConstReverseIterator &other)			{ return this->m_ptr <= other.m_ptr; }

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
		friend bool operator!= (const vector<T>& lhs, const vector<T>& rhs)
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
		friend bool operator<  (const vector<T>& lhs, const vector<T>& rhs)
		{
			return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		friend bool operator<= (const vector<T>& lhs, const vector<T>& rhs)	{ return !(rhs < lhs); }
		friend bool operator>  (const vector<T>& lhs, const vector<T>& rhs)	{ return rhs < lhs; }
		friend bool operator>= (const vector<T>& lhs, const vector<T>& rhs)	{ return !(lhs < rhs); }
	};

	/// CONSTRUCTORS			************************************************************
	template<typename T>
	vector<T>::vector() : m_array(nullptr), m_size(0), m_capacity(0)	{}

	template<typename T>
	vector<T>::vector(vector::size_type n, const value_type &val) : m_size(n), m_capacity(n)
	{
		m_array = new value_type [n];
		for (long i = 0; i < static_cast<long>(n); ++i)
			m_array[i] = val;
	}

	template<typename T>
	template<class InputIterator>
	vector<T>::vector (InputIterator first
					, typename enable_if<IsIteratorOrPointer<InputIterator>::value
					, InputIterator>::type last)
							: m_size(last - first), m_capacity(last - first)
	{
		m_array = new value_type [m_capacity];
		for (int i = 0; first != last; ++i)
		{
			m_array[i] = *first;
			++first;
		}
	}

	template<typename T>
	vector<T>::vector(const vector &x)
	{
		*this = x;
	}

	template<typename T>
	vector<T>::~vector()
	{
		clear();
		delete [] m_array;
	}

	/// OPERATOR OVERLOAD	************************************************************
	template<typename T>
	vector<T> & vector<T>::operator=(const vector &x)
	{
		if (this != &x)
		{
			clear();
			if (x.m_size == 0)
				return *this;
			m_array = new value_type [x.m_size];
			m_size = x.m_size;
			m_capacity = x.m_capacity;

			for (long i = 0; i < static_cast<long>(x.m_size); ++i)
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
				for (long i = 0; i < static_cast<long>(m_size); ++i)
					newArr[i] = m_array[i];
				for (long i = m_size; i < static_cast<long>(n); ++i)
					newArr[i] = val;
				delete [] m_array;
				m_array = newArr;
			}
			else
			{
				for (long i = m_size; i < static_cast<long>(n); ++i)
					m_array[i] = val;
			}
			m_size = n;
		}
		else if (n < m_size)
		{
			while (m_size > n)
				pop_back();
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
			for (long i = 0; i < static_cast<long>(m_size); ++i)
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
		typename enable_if<IsIteratorOrPointer<InputIterator>::value, void>::type
		        vector<T>::assign(InputIterator first, InputIterator last)
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
		for (long i = 0; i < static_cast<long>(n); ++i)
			m_array[i] = val;
		m_size = n;
	}

	template<typename T>
	void vector<T>::pop_back()
	{
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
		if (n > max_size())
			throw std::runtime_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
		if (n > m_capacity)
		{
			m_capacity = n;
			value_type *newArr = new value_type [m_capacity];
			for (long i = 0; i < static_cast<long>(m_size); ++i)
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
		return ConstIterator(&m_array[0]);
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::end()
	{
		return Iterator(&m_array[m_size]);
	}

	template<typename T>
	typename vector<T>::const_iterator vector<T>::end() const
	{
		return ConstIterator(&m_array[m_size]);
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
			long i = m_size;
			for (; i > static_cast<long>(position - begin()); --i)
				newArr[i] = m_array[i - 1];
			newArr[i] = val;
			long newElementIndex = i;
			for (--i; i >= 0; --i)
				newArr[i] = m_array[i];
			delete [] m_array;
			m_array = newArr;
			position = begin() + newElementIndex + 1;
		}
		else
		{
			iterator it = end();
			for (; it >= position; --it)
				*it = *(it - 1);
			*position = val;
		}
		++m_size;
		return position - 1;
	}

	template<typename T>
	void vector<T>::insert(vector::iterator position, vector::size_type n, const value_type &val)
	{
		if (m_size + n >= m_capacity)
		{
			m_capacity = getNearestPowerOfTwo(m_size + n + 1);
			value_type *newArr = new value_type [m_capacity];
			long i = m_size + n - 1;
			for (; i >= static_cast<long>(position - begin() + n); --i)
				newArr[i] = m_array[i - n];
			for (long j = 0; j < static_cast<long>(n); ++j)
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
			for (long i = 0; i < static_cast<long>(n); ++i)
			{
				*position = val;
				++position;
			}
		}
		m_size += n;
	}

	template<typename T>
	template<class InputIterator>
		typename enable_if<IsIteratorOrPointer<InputIterator>::value, void>::type vector<T>::insert
			(vector::iterator position, InputIterator first, InputIterator last)
	{
		if (first > last)
			return;
		size_type n = last - first;
		value_type tmpArr[n];
		for (long i = 0; i < static_cast<long>(n); ++i)
		{
			tmpArr[i] = *first;
			++first;
		}
		if (m_size + n >= m_capacity)
		{
			m_capacity = getNearestPowerOfTwo(m_size + n + 1);
			value_type *newArr = new value_type [m_capacity];
			long i = m_size + n - 1;
			for (; i >= static_cast<long>(position - begin() + n); --i)
				newArr[i] = m_array[i - n];
			for (long j = static_cast<long>(n) - 1; j >= 0; --j)
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
			for (long i = 0; i < static_cast<long>(n); ++i)
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
		for (; position < end(); ++position)
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
		for (int i = 0; first < end(); ++first, ++i)
		{
			if (last + i >= end())
				*first = T();
			else
				*first = *(last + i);
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

