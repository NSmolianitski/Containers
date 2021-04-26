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
		class value_comp;/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
		struct Node
		{
			value_type		pair;

			Node *			parent;
			Node *			left;
			Node *			right;

			bool 			color; //BLACK = 0, RED = 1

			Node(const std::pair<Key, T> pair_)
					: pair(pair_)
					, parent(nullptr)
					, left(nullptr)
					, right(nullptr)
					, color(RED) {}

		private:
			Node() {}
		};

	private:
		/// MEMBERS
		size_type		m_size;
		Node *			m_root;
		Node *			m_end;

		/// UTILS MEMBER FUNCTIONS
		Node *		addNode			(const map::value_type &val);
		void		fixInsertion	(Node * ptr);
		void 		leftRotate		(Node * ptr);
		void 		rightRotate		(Node * ptr);

///DELEEEEEEEEETE!@!!!!@!@!!#$!#!#!$!@! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	public:																	///////////////////////////////////////////////////////////////!
		void 		drawTree		(Node *root, int space, int debug); 	///////////////////////////////////////////////////////////////!
		void		drawNode		(const Node *ptr, int debug);			///////////////////////////////////////////////////////////////!
		Node *		getRoot			() { return m_root; }					///////////////////////////////////////////////////////////////!
///DELEEEEEEEEETE!@!!!!@!@!!#$!#!#!$!@! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	public:
		/// ITERATORS
		class Iterator
		{
		public:
			friend class map<Key, T, Compare>;
			typedef	std::bidirectional_iterator_tag			iterator_category;

			Iterator() {}
			Iterator(map<Key, T, Compare>* parentMap, Node *ptr)
				: m_map(parentMap), m_ptr(ptr) {}
			Iterator(map<Key, T, Compare>* parentMap, const Node *ptr)
				: m_map(parentMap), m_ptr(const_cast<Node *> (ptr)) {}

			reference		operator*  () const 				{ return m_ptr->pair; }
			pointer			operator-> () const 				{ return &m_ptr->pair; }

			Iterator&		operator++ ();
			Iterator		operator++ (int);

			Iterator&		operator-- ();
			Iterator		operator-- (int);

			bool			operator== (const Iterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool			operator!= (const Iterator &other)	{ return this->m_ptr != other.m_ptr; }

			Node *			getNode   () 						{ return m_ptr; }

		private:
			map<Key, T, Compare> *	m_map;
			Node *					m_ptr;

		};
		class ReverseIterator
		{
		public:
			typedef	std::bidirectional_iterator_tag		iterator_category;

			ReverseIterator() {}
			explicit ReverseIterator(Node *ptr) : m_ptr(ptr) {}
			explicit ReverseIterator(const Node *ptr) : m_ptr(const_cast<Node *> (ptr)) {}

			reference				operator*  () const 						{ return m_ptr->pair; }
			pointer					operator-> () const 						{ return &m_ptr->pair; }

			ReverseIterator&		operator++ ();
			ReverseIterator			operator++ (int);

			ReverseIterator&		operator-- ();
			ReverseIterator			operator-- (int);

			bool					operator== (const ReverseIterator &other)	{ return this->m_ptr == other.m_ptr; }
			bool					operator!= (const ReverseIterator &other)	{ return this->m_ptr != other.m_ptr; }

		private:
			Node *	m_ptr;
		};

		/// CONSTRUCTORS
		explicit map(const key_compare &comp = key_compare());

		template<class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare());

		map(const map &x);

		///ITERATORS
		iterator		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;

		/// DESTRUCTOR

		/// CAPACITY
		bool		empty	() const;
		size_type	size	() const;
		size_type	max_size() const;

		/// OBSERVERS
		value_compare	value_com	() const;
		key_compare		key_comp	() const;

		/// ELEMENT ACCESS
		mapped_type& operator[] (const key_type& k);

		/// MODIFIERS
		std::pair<iterator, bool>	insert	(const value_type& val);
		iterator					insert	(iterator position, const value_type& val);

		template <class InputIterator>
			void insert (InputIterator first, InputIterator last);


		void						erase	(iterator position);
		size_type					erase	(const key_type& k);
		void						erase	(iterator first, iterator last);
		void						clear	();

		/// OPERATIONS
		iterator		find	(const key_type& k);
		const_iterator	find	(const key_type& k) const;


	};

	/// CONSTRUCTORS
	template<class Key, class T, class Compare>
		map<Key, T, Compare>::map(const key_compare &comp) : m_size(0) {}

	template<class Key, class T, class Compare>
		template<class InputIterator>
			map<Key, T, Compare>::map(InputIterator first, InputIterator last, const key_compare &comp)
	{
		// Fill here
	}

//	template<class Key, class T, class Compare>
//		map<Key, T, Compare>::map(const map &x) : m_size(x.m_size), m_root(&new Node (x.m_root))
//	{
//		// Fill here
//	}

	/// ITERATORS
	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Iterator& map<Key, T, Compare>::Iterator::operator++()
	{
		Node		*ptr = m_ptr;

		if (ptr->right)
		{
			ptr = ptr->right;
			while (ptr->left)
				ptr = ptr->left;
			m_ptr = ptr;
		}
		else
		{
			while (ptr->parent && ptr->parent->right == ptr)
				ptr = ptr->parent;
			if (!ptr->parent)
				m_ptr = m_map->m_end;
			else
				m_ptr = ptr->parent;
		}
		return *this;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::begin()
	{
		Node *ptr = m_root;

		while (ptr->left)
			ptr = ptr->left;

		return Iterator(this, ptr);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::begin() const
	{
		return Iterator(this, m_root);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::end()
	{
		return Iterator(this, m_end);
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::end() const
	{
		return Iterator(this, m_end);
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
		typename map<Key, T, Compare>::size_type map<Key, T, Compare>::size() const
	{
		return m_size;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::max_size() const
	{
		return SIZE_T_MAX / sizeof(Node);
	}

	/// OBSERVERS

	/// ELEMENT ACCESS
	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::mapped_type &map<Key, T, Compare>::operator[](const key_type &k)
	{
		key_type key = k;
		iterator it = find(key);

		if (it.getNode() != m_end)
			return it.getNode()->pair.second;
		else
		{
			insert(std::pair<Key, T>(key, 0));  ///////////////// try T() if something is wrong
			it = find(key);
			return it.getNode()->pair.second;
		}
	}

	/// MODIFIERS
	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::leftRotate(Node *ptr)
	{
		Node *tmp = ptr->right;
		if (tmp->left)
			ptr->right = tmp->left;
		else
			ptr->right = nullptr;
		if (ptr->parent == nullptr)
		{
			m_root = tmp;
			m_root->parent = nullptr;
		}
		else if (ptr->parent->left == ptr)
			ptr->parent->left = tmp;
		else
			ptr->parent->right = tmp;
		tmp->left = ptr;
		tmp->parent = ptr->parent;
		ptr->parent = tmp;
	}

	template<class Key, class T, class Compare>
	void map<Key, T, Compare>::rightRotate(Node *ptr)
	{
		Node *tmp = ptr->left;
		if (tmp->right)
		{
			tmp->right->parent = ptr->left->parent;
			ptr->left = tmp->right;
		}
		else
			ptr->left = nullptr;
		if (ptr->parent == nullptr)
		{
			m_root = tmp;
			m_root->parent = nullptr;
		}
		else if (ptr->parent->right == ptr)
			ptr->parent->right = tmp;
		else
			ptr->parent->left = tmp;
		tmp->right = ptr;
		tmp->parent = ptr->parent;
		ptr->parent = tmp;
	}

	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::Node * map<Key, T, Compare>::addNode(const map::value_type &val)
	{
		Node		*ptr = m_root;
		key_compare	comp;

		while (ptr)
		{
			if (comp(ptr->pair.first, val.first))
			{
				if (!ptr->right)
				{
					ptr->right = new Node(val);
					ptr->right->parent = ptr;
					++m_size;
					return ptr->right;
				}
				ptr = ptr->right;
			}
			else
			{
				if (!ptr->left)
				{
					ptr->left = new Node(val);
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
		while (ptr->parent && ptr->parent->color == RED)
		{
			Node * father = ptr->parent;
			if (father == father->parent->left)
			{
				if (father->parent->right && father->parent->right->color == RED)
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
				if (father->parent->left)
				{
					if (father->parent->left && father->parent->left->color == RED)
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
			m_root = new Node(val);
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
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::erase(const key_type &k)
	{
		Iterator it = find(k);

		if (it == end())
			return 0;

		Node * nodeToBeDeleted = it.getNode();
		bool savedColor = nodeToBeDeleted->color;

		Node ** parentPointer = nullptr;
		if (nodeToBeDeleted != m_root)
		{
			if (nodeToBeDeleted->parent->left == nodeToBeDeleted)
				parentPointer = &nodeToBeDeleted->parent->left;
			else
				parentPointer = &nodeToBeDeleted->parent->right;
		}

		if (!nodeToBeDeleted->left && !nodeToBeDeleted->right)		// If no children
		{
			if (nodeToBeDeleted == m_root)
				m_root = nullptr;
			else
				*parentPointer = nullptr;
		}
		else if (nodeToBeDeleted->left && nodeToBeDeleted->right)	// If two children
		{
			Node * ptr = nodeToBeDeleted->right;
			while (ptr->left)
				ptr = ptr->left;
			ptr->parent = nullptr;
			if (nodeToBeDeleted == m_root)
				m_root = ptr;
			else
				*parentPointer = ptr;
			ptr->left = nodeToBeDeleted->left;
			nodeToBeDeleted->left->parent = ptr;
		}
		else														// If one child
		{
			if (nodeToBeDeleted->left)
			{
				if (nodeToBeDeleted == m_root)
					m_root = nodeToBeDeleted->left;
				else
				{
					*parentPointer = nodeToBeDeleted->left;
					nodeToBeDeleted->left->parent = nodeToBeDeleted->parent;
				}
			}
			else
			{
				if (nodeToBeDeleted == m_root)
					m_root = nodeToBeDeleted->right;
				else
				{
					*parentPointer = nodeToBeDeleted->right;
					nodeToBeDeleted->right->parent = nodeToBeDeleted->parent;
				}
			}
		}
		if (m_root)
			m_root->parent = nullptr;
		delete nodeToBeDeleted;
		--m_size;
		return 1;
	}

	/// OPERATIONS
	template<class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::find(const key_type &k)
	{
		Node *ptr = m_root;
		key_compare comp;
		while (ptr)
		{
			if (ptr->pair.first == k)
				return Iterator(this, ptr);
			else if (comp(ptr->pair.first, k))
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		return Iterator(this, m_end);
	}

	/// OBSERVERS
	template<class Key, class T, class Compare>
		typename map<Key, T, Compare>::key_compare map<Key, T, Compare>::key_comp() const
	{
		return key_compare();
	}


	template<class Key, class T, class Compare>
		typename map<Key, T, Compare>::value_compare map<Key, T, Compare>::value_com() const
	{
		return value_compare();
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
			if (ptr->parent)
				std::cout << "Parent: " << ptr->parent->pair.first << "\n";
			else
				std::cout << "Parent: NULL" << "\n";
			std::cout << "Value: " << ptr->pair.first << "\n";
			if (ptr->right)
				std::cout << "Right: " << ptr->right->pair.first << "\n";
			else
				std::cout << "Right: NULL" << "\n";
			if (ptr->left)
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
		if (root == NULL)
			return;

		// Increase distance between levels
		space += 10;

		// Process right child first
		drawTree(root->right, space, debug);

		// Print current node after space
		// count
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		drawNode(root, debug);

		// Process left child
		drawTree(root->left, space, debug);
	}


//////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}


#endif
