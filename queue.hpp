//
// Created by Parfait Kentaurus on 4/15/21.
//

#ifndef FT_CONTAINERS_QUEUE_HPP
#define FT_CONTAINERS_QUEUE_HPP

#include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
	public:
		typedef T						value_type;
		typedef std::size_t 			size_type;
		typedef Container				container_type;

	private:
		Container m_container;
		queue(const queue<T, Container> &other) {};

	public:
		//Constructors
		explicit queue (const container_type &ctnr = container_type());

		//Member functions
		bool				empty	() const;
		size_type			size	() const;
		value_type&			front	();
		const value_type&	front	() const;
		value_type&			back	();
		const value_type&	back	() const;
		void				push	(const value_type& val);
		void				pop		();

		friend bool operator== (const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return lhs.m_container == rhs.m_container; }
		friend bool operator!= (const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return lhs.m_container != rhs.m_container; }
		friend bool operator<  (const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return lhs.m_container < rhs.m_container; }
		friend bool operator<= (const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return lhs.m_container <= rhs.m_container; }
		friend bool operator>  (const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return lhs.m_container > rhs.m_container; }
		friend bool operator>= (const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return lhs.m_container >= rhs.m_container; }
	};
	//!queue CLASS END!

	template<class T, class Container>
	queue<T, Container>::queue(const container_type &ctnr) : m_container(ctnr) {}

	template<class T, class Container>
	bool queue<T, Container>::empty() const
	{
		return m_container.empty();
	}

	template<class T, class Container>
	typename queue<T, Container>::size_type queue<T, Container>::size() const
	{
		return m_container.size();
	}

	template<class T, class Container>
	typename queue<T, Container>::value_type &queue<T, Container>::front()
	{
		return m_container.front();
	}

	template<class T, class Container>
	const typename queue<T, Container>::value_type &queue<T, Container>::front() const
	{
		return m_container.front();
	}

	template<class T, class Container>
	typename queue<T, Container>::value_type &queue<T, Container>::back()
	{
		return m_container.back();
	}

	template<class T, class Container>
	const typename queue<T, Container>::value_type &queue<T, Container>::back() const
	{
		return m_container.back();
	}

	template<class T, class Container>
	void queue<T, Container>::push(const value_type &val)
	{
		m_container.push_back(val);
	}

	template<class T, class Container>
	void queue<T, Container>::pop()
	{
		m_container.pop_front();
	}

}

#endif
