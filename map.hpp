//
// Created by Parfait Kentaurus on 4/20/21.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include <iomanip> ///////////////////////////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
namespace ft
{
	/// RED-BLACK TREE ENUMS
	enum TreeColor
	{
		BLACK,
		RED
	};

	/// MAP CLASS
	template<   class Key,                                   // map::key_type
				class T,                                     // map::mapped_type
				class Compare = std::less<Key>               // map::key_compare
			> class map
	{
	public:
		class Iterator;
		class ReverseIterator;
		class value_comp; /////////////////////////////////////////////////////////////////////////////////////////////////////////////

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef std::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		typedef value_comp								value_compare;
		typedef value_type &							reference;
		typedef const value_type &						const_reference;
		typedef value_type *							pointer;
		typedef const value_type *						const_pointer;
		typedef Iterator								iterator;
		typedef const Iterator							const_iterator;
		typedef ReverseIterator							reverse_iterator;
		typedef const ReverseIterator					const_reverse_iterator;
		typedef std::ptrdiff_t							difference_type;
		typedef std::size_t								size_type;


		/// NODE STRUCT
	private:
		struct Node
		{
			value_type		pair;

			Node*			parent;
			Node*			left;
			Node*			right;

			TreeColor		color; // BLACK = 0, RED = 1

			Node(const std::pair<Key, T> pair_)
					: pair(pair_)
					, parent(nullptr)
					, left(nullptr)
					, right(nullptr)
					, color(RED) {}

			Node() {}

		};

		/// MEMBERS
		size_type			m_size;
		Node*				m_root;
		Node*				m_nil;
//!		Node*				m_end; /!//////////////////////////////////////////////////////////////////////////////////////////////////////!

///DELEEEEEEEEETE!@!!!!@!@!!#$!#!#!$!@! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	public:																	///////////////////////////////////////////////////////////////!
		void 		drawTree		(Node *root, int space, int debug); 	///////////////////////////////////////////////////////////////!
		void		drawNode		(const Node *ptr, int debug);			///////////////////////////////////////////////////////////////!
		Node*		getRoot			() { return m_root; }					///////////////////////////////////////////////////////////////!
///DELEEEEEEEEETE!@!!!!@!@!!#$!#!#!$!@! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	public:
		/// ITERATORS --START--
		class Iterator
		{
		public:
			friend class map<Key, T, Compare>;
			typedef	std::bidirectional_iterator_tag			iterator_category;

			Iterator() {}
			Iterator(map<Key, T, Compare>* parentMap, Node *ptr)
				: m_map(parentMap), m_ptr(ptr) {}
			Iterator(const map<Key, T, Compare>* parentMap, const Node *ptr)
				: m_map(const_cast<map<Key, T, Compare>*> (parentMap)), m_ptr(const_cast<Node *> (ptr)) {}

			reference		operator*  () const 				{ return m_ptr->pair; }
			pointer			operator-> () const 				{ return &m_ptr->pair; }

			Iterator&		operator++ ();
			Iterator		operator++ (int);

			Iterator&		operator-- ();
			Iterator		operator-- (int);

			bool			operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

			Node*			getNode   () 						{ return m_ptr; }////////!////////////////////////////////

		private:
			map<Key, T, Compare>*	m_map;
			Node*					m_ptr;

		};

		class ReverseIterator
		{
		public:
			typedef	std::bidirectional_iterator_tag		iterator_category;

			ReverseIterator() {}
			explicit ReverseIterator(map<Key, T, Compare>* parentMap, Node *ptr)
					: m_map(parentMap), m_ptr(ptr) {}
			explicit ReverseIterator(map<Key, T, Compare>* parentMap, const Node *ptr)
					: m_map(parentMap), m_ptr(const_cast<Node *> (ptr)) {}

			reference				operator*  () const 						{ return m_ptr->pair; }
			pointer					operator-> () const 						{ return &m_ptr->pair; }

			ReverseIterator&		operator++ ();
			ReverseIterator			operator++ (int);

			ReverseIterator&		operator-- ();
			ReverseIterator			operator-- (int);

			bool					operator== (const ReverseIterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool					operator!= (const ReverseIterator &other)	{ return this->m_ptr != other.m_ptr; }

		private:
			map<Key, T, Compare>*	m_map;
			Node*					m_ptr;
		};
		/// ITERATORS --END--

		/// CONSTRUCTORS
		explicit map(const key_compare& comp = key_compare());
		template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare());
		map(const map &x);


		///ITERATORS
		iterator				begin	();
		const_iterator			begin	() const;
		iterator				end		();
		const_iterator			end		() const;

		reverse_iterator		rbegin	();
		const_reverse_iterator	rbegin	() const;
		reverse_iterator		rend	();
		const_reverse_iterator	rend	() const;


		/// DESTRUCTOR
		~map();


		/// ASSIGN OPERATOR OVERLOAD
		map& operator= (const map& x)
		{
			if (this != &x)
			{
				clear();
				insert(x.begin(), x.end());
			}
			return *this;
		}


		/// CAPACITY
		bool			empty	() const;
		size_type		size	() const;
		size_type		max_size() const;


		/// OBSERVERS
		value_compare	value_comp	() const;
		key_compare		key_comp	() const;


		/// ELEMENT ACCESS
		mapped_type&	operator[]	(const key_type& k);


		/// MODIFIERS
		std::pair<iterator, bool>	insert	(const value_type& val);
		iterator					insert	(iterator position, const value_type& val);

		template <class InputIterator>
			void insert (InputIterator first, InputIterator last);


		void			erase		(iterator position);
		size_type		erase		(const key_type& k);
		void			erase		(iterator first, iterator last);
		void			clear		();
		void			swap		(map& x);


		/// OPERATIONS
		iterator									find		(const key_type& k);
		const_iterator								find		(const key_type& k) const;
		size_type									count		(const key_type& k) const;
		iterator									lower_bound (const key_type& k);
		const_iterator								lower_bound (const key_type& k) const;
		iterator									upper_bound (const key_type& k);
		const_iterator								upper_bound (const key_type& k) const;
		std::pair<iterator,iterator>				equal_range (const key_type& k);
		std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;


		/// UTILS MEMBER FUNCTIONS
		void		fillNil				();
		Node*		newNode				(const map::value_type &val);
		Node*		addNode				(const map::value_type &val);
		void		fixInsertion		(Node* ptr);
		void 		leftRotate			(Node* ptr);
		void 		rightRotate			(Node* ptr);
		Node*		transplant			(Node* parent, Node* child);
		Node*		eraseTwoChildren	(Node* nodeToBeDeleted, TreeColor& originalColor);
		void		fixErasure			(Node* ptr);
		Node*		min					(Node* ptr);
		Node*		max					(Node* ptr);

	}; //! End of [Map Class] !//


	/// CONSTRUCTORS
	template<class Key, class T, class Compare>
		map<Key, T, Compare>::map(const key_compare &comp)
			: m_size(0)
	{
		fillNil();
	}

	template<class Key, class T, class Compare>
		template<class InputIterator>
			map<Key, T, Compare>::map(InputIterator first, InputIterator last, const key_compare& comp)
				: m_size(0)
	{
		fillNil();
		for (; first != last ; ++first)
			insert(*first);
	}

	template<class Key, class T, class Compare>
	map<Key, T, Compare>::map(const map &x)
			: m_size(0)
	{
		fillNil();
		insert(x.begin(), x.end());
	}


	/// DESTRUCTOR
	template<class Key, class T, class Compare>
	map<Key, T, Compare>::~map()
	{
		for (iterator it = begin(); it != end() ; ++it)
			erase(it);
		delete m_nil;
	}


	/// ITERATORS
	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Iterator&				map<Key, T, Compare>::Iterator::operator++()
	{
		Node		*ptr = m_ptr;

		if (ptr->right != m_map->m_nil)
		{
			ptr = ptr->right;
			while (ptr->left != m_map->m_nil)
				ptr = ptr->left;
			m_ptr = ptr;
		}
		else
		{
			while (ptr != m_map->m_nil && ptr->parent->right == ptr)
				ptr = ptr->parent;
			if (ptr->parent == m_map->m_nil)
				m_ptr = m_map->m_nil;
			else
				m_ptr = ptr->parent;
		}
		return *this;
	}

	template< class Key, class T, class Compare >
	typename map<Key, T, Compare>::Iterator					map<Key, T, Compare>::Iterator::operator++(int)
	{
		Iterator	it	= *this;
		Node*		ptr	= m_ptr;

		if (ptr->right != m_map->m_nil)
		{
			ptr = ptr->right;
			while (ptr->left != m_map->m_nil)
				ptr = ptr->left;
			m_ptr = ptr;
		}
		else
		{
			while (ptr != m_map->m_nil && ptr->parent->right == ptr)
				ptr = ptr->parent;
			if (ptr->parent == m_map->m_nil)
				m_ptr = m_map->m_nil;
			else
				m_ptr = ptr->parent;
		}
		return it;
	}

	template< class Key, class T, class Compare >
	typename map<Key, T, Compare>::Iterator&				map<Key, T, Compare>::Iterator::operator--()
	{
		Node		*ptr = m_ptr;

		if (ptr == m_map->m_nil)
		{
			m_ptr = m_map->max(m_map->m_root);
			return *this;
		}
		if (ptr->left != m_map->m_nil)
		{
			ptr = ptr->left;
			while (ptr->right != m_map->m_nil)
				ptr = ptr->right;
			m_ptr = ptr;
		}
		else
		{
			while (ptr->parent->left == ptr && ptr != m_map->m_nil)
				ptr = ptr->parent;
			m_ptr = ptr->parent;
		}
		return *this;
	}

	template< class Key, class T, class Compare >
	typename map<Key, T, Compare>::Iterator					map<Key, T, Compare>::Iterator::operator--(int)
	{
		Iterator	it	= *this;
		Node*		ptr = m_ptr;

		if (ptr == m_map->m_nil)
		{
			m_ptr = m_map->max(m_map->m_root);
			return it;
		}
		if (ptr->left != m_map->m_nil)
		{
			ptr = ptr->left;
			while (ptr->right != m_map->m_nil)
				ptr = ptr->right;
			m_ptr = ptr;
		}
		else
		{
			while (ptr->parent->left == ptr && ptr != m_map->m_nil)
				ptr = ptr->parent;
			m_ptr = ptr->parent;
		}
		return it;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::ReverseIterator&			map<Key, T, Compare>::ReverseIterator::operator++()
	{
		Node		*ptr = m_ptr;

		if (ptr->left != m_map->m_nil)
		{
			ptr = ptr->left;
			while (ptr->right != m_map->m_nil)
				ptr = ptr->right;
			m_ptr = ptr;
		}
		else
		{
			while (ptr->parent->left == ptr && ptr != m_map->m_nil)
				ptr = ptr->parent;
			m_ptr = ptr->parent;
		}
		return *this;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::ReverseIterator			map<Key, T, Compare>::ReverseIterator::operator++(int)
	{
		Iterator	it	= *this;
		Node*		ptr = m_ptr;

		if (ptr->left != m_map->m_nil)
		{
			ptr = ptr->left;
			while (ptr->right != m_map->m_nil)
				ptr = ptr->right;
			m_ptr = ptr;
		}
		else
		{
			while (ptr->parent->left == ptr && ptr != m_map->m_nil)
				ptr = ptr->parent;
			m_ptr = ptr->parent;
		}
		return it;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::ReverseIterator&			map<Key, T, Compare>::ReverseIterator::operator--()
	{
		Node		*ptr = m_ptr;

		if (ptr == m_map->m_nil)
		{
			m_ptr = m_map->min(m_map->m_root);
			return *this;
		}
		if (ptr->right != m_map->m_nil)
		{
			ptr = ptr->right;
			while (ptr->left != m_map->m_nil)
				ptr = ptr->left;
			m_ptr = ptr;
		}
		else
		{
			while (ptr != m_map->m_nil && ptr->parent->right == ptr)
				ptr = ptr->parent;
			if (ptr->parent == m_map->m_nil)
				m_ptr = m_map->m_nil;
			else
				m_ptr = ptr->parent;
		}
		return *this;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::ReverseIterator			map<Key, T, Compare>::ReverseIterator::operator--(int)
	{
		Iterator	it	= *this;
		Node*		ptr	= m_ptr;

		if (ptr == m_map->m_nil)
		{
			m_ptr = m_map->max(m_map->m_root);
			return it;
		}
		if (ptr->right != m_map->m_nil)
		{
			ptr = ptr->right;
			while (ptr->left != m_map->m_nil)
				ptr = ptr->left;
			m_ptr = ptr;
		}
		else
		{
			while (ptr != m_map->m_nil && ptr->parent->right == ptr)
				ptr = ptr->parent;
			if (ptr->parent == m_map->m_nil)
				m_ptr = m_map->m_nil;
			else
				m_ptr = ptr->parent;
		}
		return it;
	}


	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator					map<Key, T, Compare>::begin()
	{
		Node *ptr = m_root;

		while (ptr->left != m_nil)
			ptr = ptr->left;

		return Iterator(this, ptr);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator			map<Key, T, Compare>::begin() const
	{
		Node *ptr = m_root;

		while (ptr->left != m_nil)
			ptr = ptr->left;

		return Iterator(this, ptr);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator					map<Key, T, Compare>::end()
	{
		return Iterator(this, m_nil);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator			map<Key, T, Compare>::end() const
	{
		return Iterator(this, m_nil);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::reverse_iterator			map<Key, T, Compare>::rbegin()
	{
		Node *ptr = m_root;

		while (ptr->right != m_nil)
			ptr = ptr->right;

		return ReverseIterator(this, ptr);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_reverse_iterator	map<Key, T, Compare>::rbegin() const
	{
		Node *ptr = m_root;

		while (ptr->right != m_nil)
			ptr = ptr->right;

		return ReverseIterator(this, ptr);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::reverse_iterator			map<Key, T, Compare>::rend()
	{
		return ReverseIterator(this, m_nil);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_reverse_iterator	map<Key, T, Compare>::rend() const
	{
		return ReverseIterator(this, m_nil);
	}


	/// CAPACITY
	template<class Key, class T, class Compare>
		bool map<Key, T, Compare>::empty() const
	{
		if (m_size != 0)
			return false;
		return true;
	}

	template<class Key, class T, class Compare>
		typename map<Key, T, Compare>::size_type			map<Key, T, Compare>::size() const
	{
		return m_size;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type				map<Key, T, Compare>::max_size() const
	{
		return SIZE_T_MAX / sizeof(Node);
	}


	/// OBSERVERS


	/// ELEMENT ACCESS
	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::mapped_type&				map<Key, T, Compare>::operator[](const key_type &k)
	{
		key_type key = k;
		iterator it = find(key);

		if (it.getNode() != m_nil)
			return it.getNode()->pair.second;
		else
		{
			insert(std::pair<Key, T>(key, 0));  ///////////////// try T() if something is wrong //////////////////
			it = find(key);
			return it.getNode()->pair.second;
		}
	}


	/// MODIFIERS
	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::leftRotate(Node *ptr)
	{
		Node* tmp = ptr->right;
		
		ptr->right = tmp->left;
		if (tmp->left != m_nil)
			tmp->left->parent = ptr;
		tmp->parent = ptr->parent;
		if (ptr->parent == m_nil)
			m_root = tmp;
		else if (ptr == ptr->parent->left)
			ptr->parent->left = tmp;
		else
			ptr->parent->right = tmp;
		tmp->left = ptr;
		ptr->parent = tmp;
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::rightRotate(Node *ptr)
	{
		Node* tmp = ptr->left;
		ptr->left = tmp->right;
		if (tmp->right != m_nil)
			tmp->right->parent = ptr;
		tmp->parent = ptr->parent;
		if (ptr->parent == m_nil)
			m_root = tmp;
		else if (ptr == ptr->parent->right)
			ptr->parent->right = tmp;
		else
			ptr->parent->left = tmp;
		tmp->right = ptr;
		ptr->parent = tmp;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Node* map<Key, T, Compare>::newNode(const map::value_type &val)
	{
		Node*	newNode = new Node(val);

		newNode->parent = m_nil;
		newNode->left = m_nil;
		newNode->right = m_nil;
		newNode->color = RED;

		return newNode;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Node* map<Key, T, Compare>::addNode(const map::value_type &val)
	{
		Node		*ptr = m_root;
		key_compare	comp;

		while (ptr != m_nil)
		{
			if (comp(ptr->pair.first, val.first))
			{
				if (ptr->right == m_nil)
				{
					ptr->right = newNode(val);
					ptr->right->parent = ptr;
					++m_size;
					return ptr->right;
				}
				ptr = ptr->right;
			}
			else
			{
				if (ptr->left == m_nil)
				{
					ptr->left = newNode(val);
					ptr->left->parent = ptr;
					++m_size;
					return ptr->left;
				}
				ptr = ptr->left;
			}
		}
		return ptr;
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::fixInsertion(Node * ptr)
	{
		if (ptr == m_root)
		{
			ptr->color = BLACK;
			return;
		}
		while (ptr != m_nil && ptr->parent->color == RED)
		{
			Node * father = ptr->parent;
			if (father == father->parent->left)
			{
				if (father->parent->right->color == RED)
				{
					father->color = BLACK;
					father->parent->right->color = BLACK;
					father->parent->color = RED;
					ptr = father->parent;
				}
				else
				{
					if (ptr == father->right)
					{
						ptr = father;
						leftRotate(ptr);
					}
					ptr->parent->color = BLACK;
					ptr->parent->parent->color = RED;
					rightRotate(ptr->parent->parent);
				}
			}
			else
			{
				if (father->parent->left != m_nil)
				{
					if (father->parent->left->color == RED)
					{
						father->color = BLACK;
						father->parent->left->color = BLACK;
						father->parent->color = RED;
						ptr = father->parent;
					}
					else
					{
						if (ptr == father->left)
						{
							ptr = father;
							rightRotate(ptr);
						}
						ptr->parent->color = BLACK;
						ptr->parent->parent->color = RED;
						leftRotate(ptr->parent->parent);
					}
				}
				else
				{
					if (ptr == father->left)
					{
						ptr = father;
						rightRotate(ptr);
					}
					ptr->parent->color = BLACK;
					ptr->parent->parent->color = RED;
					leftRotate(ptr->parent->parent);
				}
			}
		}
		m_root->color = BLACK;
	}

	template<class Key, class T, class Compare>
		std::pair<typename ft::map<Key, T, Compare>::iterator, bool> map<Key, T, Compare>
		        ::insert(const map::value_type &val)
	{
		if (!m_size)
			m_root = newNode(val);
		else
		{
			Iterator it = find(val.first);
			if (it == end())
			{
				Node *ptr = addNode(val);	// Assign leaf parent as new Node parent
				fixInsertion(ptr);			// Fix tree if needed
				return std::pair<iterator, bool>(Iterator(this, ptr), true);
			}
			else
				return std::pair<iterator, bool>(it, false);
		}
		++m_size;
		fixInsertion(m_root);
		return std::pair<iterator, bool>(Iterator(this, m_root), true);
	}

	template<class Key, class T, class Compare>
	typename ft::map<Key, T, Compare>::iterator
	        map<Key, T, Compare>::insert(map::iterator position, const map::value_type& val)
	{
		position = position;
		return insert(val);
	}

	template<class Key, class T, class Compare>
	template<class InputIterator>
	void map<Key, T, Compare>::insert(InputIterator first, InputIterator last)
	{
		for (; first != last; ++first)
			insert(*first);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Node* map<Key, T, Compare>
	        ::eraseTwoChildren(Node* nodeToBeDeleted, TreeColor& originalColor)
	{
		Node* minNode = min(nodeToBeDeleted->right);
		Node* x = minNode->right;

		originalColor = minNode->color;
		if (minNode->parent == nodeToBeDeleted)
			x->parent = minNode;
		else
		{
			transplant(minNode, minNode->right);
			minNode->right = nodeToBeDeleted->right;
			minNode->right->parent = minNode;
		}
		transplant(nodeToBeDeleted, minNode);
		minNode->left = nodeToBeDeleted->left;
		minNode->left->parent = minNode;
		minNode->color = nodeToBeDeleted->color;
		return x;
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::fixErasure(Node* ptr)
	{
		while (ptr != m_root && ptr->color == BLACK)
		{
			if (ptr == ptr->parent->left)
			{
				Node *w = ptr->parent->right;
				if (w->color == RED)
				{
					w->color = BLACK;
					ptr->parent->color = RED;
					leftRotate(ptr->parent);
					w = ptr->parent->right;
				}
				if (w->left->color == BLACK && w->right->color == BLACK)
				{
					w->color = RED;
					ptr = ptr->parent;
				}
				else
				{
					if (w->right->color == BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						rightRotate(w);
						w = ptr->parent->right;
					}
					w->color = ptr->parent->color;
					ptr->parent->color = BLACK;
					w->right->color = BLACK;
					leftRotate(ptr->parent);
					ptr = m_root;
				}
			}
			else
			{
				Node* w = ptr->parent->left;
				if (w->color == RED)
				{
					w->color = BLACK;
					ptr->parent->color = RED;
					rightRotate(ptr->parent);
					w = ptr->parent->left;
				}
				if (w->right->color == BLACK && w->left->color == BLACK)
				{
					w->color = RED;
					ptr = ptr->parent;
				}
				else
				{
					if (w->left->color == BLACK)
					{
						w->right->color = BLACK;
						w->color = RED;
						leftRotate(w);
						w = ptr->parent->left;
					}
					w->color = ptr->parent->color;
					ptr->parent->color = BLACK;
					w->left->color = BLACK;
					rightRotate(ptr->parent);
					ptr = m_root;
				}
			}
		}
		ptr->color = BLACK;
	}

		template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Node* map<Key, T, Compare>::transplant(Node* parent, Node* child)
	{
		if (parent->parent == m_nil)
			m_root = child;
		else if (parent == parent->parent->left)
			parent->parent->left = child;
		else
			parent->parent->right = child;
		child->parent = parent->parent;

		return child;
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::erase(map::iterator position)
	{
		if (position.getNode() == m_nil)
			return;

		Node*		nodeToBeDeleted = position.getNode();
		TreeColor	savedColor = nodeToBeDeleted->color;

		Node* x;
		if (nodeToBeDeleted->left == m_nil)							// If left child is NIL
			x = transplant(nodeToBeDeleted, nodeToBeDeleted->right);
		else if (nodeToBeDeleted->right == m_nil)					// If right child is NIL
			x = transplant(nodeToBeDeleted, nodeToBeDeleted->left);
		else														// If two children
			x = eraseTwoChildren(nodeToBeDeleted, savedColor);

		if (savedColor == BLACK)
			fixErasure(x);

		delete nodeToBeDeleted;
		--m_size;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::erase(const key_type &k)
	{
		Iterator it = find(k);

		if (it == end())
			return 0;

		erase(it);
		return 1;
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::erase(map::iterator first, map::iterator last)
	{
		iterator tmp;
		while (first != last)
		{
			tmp = first;
			++first;
			erase(tmp);
		}
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::clear()
	{
		erase(begin(), end());
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::swap(map& x)
	{
		map<Key, T, Compare> tmp = *this;

		*this = x;
		x = tmp;
	}


	/// OPERATIONS
	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::find(const key_type &k)
	{
		Node *ptr = m_root;
		key_compare comp;
		while (ptr != m_nil)
		{
			if (ptr->pair.first == k)
				return Iterator(this, ptr);
			else if (comp(ptr->pair.first, k))
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		return Iterator(this, m_nil);
	}


	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::find(const key_type& k) const
	{
		Node *ptr = m_root;
		key_compare comp;
		while (ptr != m_nil)
		{
			if (ptr->pair.first == k)
				return Iterator(this, ptr);
			else if (comp(ptr->pair.first, k))
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		return Iterator(this, m_nil);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::count(const key_type& k) const
	{
		Iterator it = find(k);
		if (it != end())
			return 1;
		return 0;
	}


	/// OBSERVERS
	template<class Key, class T, class Compare>
		typename map<Key, T, Compare>::key_compare		map<Key, T, Compare>::key_comp() const
	{
		return key_compare();
	}

	template<class Key, class T, class Compare>
		typename map<Key, T, Compare>::value_compare	map<Key, T, Compare>::value_comp() const
	{
		return value_compare();
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator				map<Key, T, Compare>::lower_bound(const key_type& k)
	{
		Iterator	it = begin();
		key_compare	comp;

		for (; it != end(); ++it)
		{
			if (k == it.getNode()->pair.first || comp(k, it.getNode()->pair.first))
				return it;
		}
		return it;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator		map<Key, T, Compare>::lower_bound(const key_type& k) const
	{
		Iterator	it = begin();
		key_compare	comp;

		for (; it != end(); ++it)
		{
			if (k == it.getNode()->pair.first || comp(k, it.getNode()->pair.first))
				return it;
		}
		return it;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator				map<Key, T, Compare>::upper_bound(const key_type& k)
	{
		Iterator	it = begin();
		key_compare	comp;

		for (; it != end(); ++it)
		{
			if (comp(k, it.getNode()->pair.first))
				return it;
		}
		return it;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator		map<Key, T, Compare>::upper_bound(const key_type& k) const
	{
		Iterator	it = begin();
		key_compare	comp;

		for (; it != end(); ++it)
		{
			if (comp(k, it.getNode()->pair.first))
				return it;
		}
		return it;
	}

	template<class Key, class T, class Compare>
	std::pair<typename  map<Key, T, Compare>::iterator, typename  map<Key, T, Compare>::iterator>
				map<Key, T, Compare>::equal_range(const key_type& k)
	{
		Iterator it = lower_bound(k);
		return std::pair<iterator, iterator>(it, it);
	}

	template<class Key, class T, class Compare>
	std::pair<typename  map<Key, T, Compare>::const_iterator, typename  map<Key, T, Compare>::const_iterator>
				map<Key, T, Compare>::equal_range(const key_type& k) const
	{
		Iterator it = lower_bound(k);
		return std::pair<iterator, iterator>(it, it);
	}

	/// UTILS
	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::fillNil()
	{
		m_nil = new Node();
		m_nil->parent = m_nil;
		m_nil->left = m_nil;
		m_nil->right = m_nil;
		m_nil->color = BLACK;

		m_root = m_nil;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Node*			map<Key, T, Compare>::min(Node* ptr)
	{
		while (ptr->left != m_nil)
			ptr = ptr->left;
		return ptr;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Node*			map<Key, T, Compare>::max(map::Node* ptr)
	{
		while (ptr->right != m_nil)
			ptr = ptr->right;
		return ptr;
	}

//////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define WHITE	"\033[97m"

#define BRED	"\033[41m"
#define BBLACK	"\033[40m"

#define BOLD	"\033[1m"
#define CLR		"\033[0m"


	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::drawNode(const Node *ptr, int debug)
	{
		std::string color = BBLACK;
		if (ptr->color == RED)
			color = BRED;
		std::cout << BOLD WHITE << color << "[" << std::setw(5) << ptr->pair.first << "]" CLR << std::endl;
		if (debug)
		{
			std::cout << "_____________________\n";
			if (ptr->parent != m_nil)
				std::cout << "Parent: " << ptr->parent->pair.first << "\n";
			else
				std::cout << "Parent: NULL" << "\n";
			std::cout << "Value: " << ptr->pair.first << "\n";
			if (ptr->right != m_nil)
				std::cout << "Right: " << ptr->right->pair.first << "\n";
			else
				std::cout << "Right: NULL" << "\n";
			if (ptr->left != m_nil)
				std::cout << "Left: " << ptr->left->pair.first << "\n";
			else
				std::cout << "Left: NULL" << "\n";
			std::cout << "_____________________\n";
		}
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::drawTree(Node *root, int space, int debug)
	{
		// Base case
		if (root == m_nil)
			return;

		// Increase distance between levels
		space += 7;

		// Process right child first
//		std::cout << std::endl;
		drawTree(root->right, space, debug);

		// Print current node after space
		// count
		for (int i = 10; i < space; i++)
			std::cout << " ";
		drawNode(root, debug);

		// Process left child
		drawTree(root->left, space, debug);
	}

//////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}


#endif
