//
// Created by Parfait Kentaurus on 4/15/21.
//

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T						value_type;
		typedef std::size_t 			size_type;
		typedef Container				container_type;

	private:
		Container m_container;
		stack(const stack<T, Container> &other) {};

	public:
		//Constructors
		explicit stack (const container_type &ctnr = container_type());

		//Member functions
		bool				empty	() const;
		size_type			size	() const;
		value_type&			top		();
		const value_type&	top		() const;
		void				push	(const value_type& val);
		void				pop		();

		friend bool operator== (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.m_container == rhs.m_container; }
		friend bool operator!= (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.m_container != rhs.m_container; }
		friend bool operator<  (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.m_container < rhs.m_container; }
		friend bool operator<= (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.m_container <= rhs.m_container; }
		friend bool operator>  (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.m_container > rhs.m_container; }
		friend bool operator>= (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.m_container >= rhs.m_container; }
	};
	//!STACK CLASS END!

	template<class T, class Container>
	stack<T, Container>::stack(const container_type &ctnr) : m_container(ctnr) {}

	template<class T, class Container>
	bool stack<T, Container>::empty() const
	{
		return m_container.empty();
	}

	template<class T, class Container>
	typename stack<T, Container>::size_type stack<T, Container>::size() const
	{
		return m_container.size();
	}

	template<class T, class Container>
	typename stack<T, Container>::value_type &stack<T, Container>::top()
	{
		return m_container.back();
	}

	template<class T, class Container>
	const typename stack<T, Container>::value_type &stack<T, Container>::top() const
	{
		return m_container.back();
	}

	template<class T, class Container>
	void stack<T, Container>::push(const value_type &val)
	{
		m_container.push_back(val);
	}

	template<class T, class Container>
	void stack<T, Container>::pop()
	{
		m_container.pop_back();
	}

}
#endif
