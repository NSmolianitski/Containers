//
// Created by Parfait Kentaurus on 5/3/21.
//

#ifndef FT_CONTAINERS_UTILS_HPP
#define FT_CONTAINERS_UTILS_HPP

namespace ft
{
	template<typename Iterator1, typename Iterator2>
	bool lexicographical_compare(Iterator1 first1, Iterator1 last1,
								 Iterator2 first2, Iterator2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template< class T1, class T2 >
	struct	pair
	{
		T1	first;
		T2	second;

		pair() : first(), second() {}
		pair (const T1& t1, const T2& t2) : first(t1), second(t2) {}

		template<class U, class V>
		pair (const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

		pair&	operator= (const pair& other)
		{
			first = other.first;
			second = other.second;
			return *this;
		}

		friend bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
		{
			return (lhs.first == rhs.first && lhs.second == rhs.second);
		}

		friend bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
		{
			return !(lhs == rhs);
		}

		friend bool operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
		{
			return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
		}

		friend bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
		{
			return !(rhs < lhs);
		}

		friend bool operator> (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
		{
			return rhs < lhs;
		}

		friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return !(lhs < rhs);
		}
	};
}

#endif
