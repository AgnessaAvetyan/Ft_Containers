#ifndef MAP_HPP
#define MAP_HPP
#include "../../Utilities/utilities.hpp"

namespace ft
{

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
class map {
public:
	typedef struct	s_node
	{
		ft::pair<const Key, T>	data;
		bool					color;
		struct s_node*			left;
		struct s_node*			right;
		struct s_node*			parent;

		s_node(ft::pair<const Key, T> data) : data(data) {}
		const Key&	key(void) { return (data.first); }
		T&	val(void) { return (data.second); }
	}							RBTNode;

	template <bool IsConst>
	class mapIterator {
	public:
		typedef	ft::pair<const Key, T>												pair_type;
		typedef typename ft::conditional<IsConst, const pair_type, pair_type>::type	value_type;
		typedef typename ft::conditional<IsConst, const RBTNode, RBTNode>::type		node_type;
		typedef	std::ptrdiff_t														difference_type;
		typedef	std::size_t															size_type;

		// ctor and dtor
		mapIterator() { _ptr = NULL; }
		mapIterator(node_type * const ptr){ _ptr = ptr; }
		mapIterator& operator=(const mapIterator & x)
		{ 
			_ptr = x.get_pointer();
			return (*this);
		}

		template <bool B>
		mapIterator(const mapIterator<B>& x, typename ft::enable_if<!B>::type* = 0){ _ptr = x.get_pointer(); }

		~mapIterator() {}

		template <bool B>
		bool operator==(const mapIterator<B>& x) const { return (_ptr == x.get_pointer()); }
		template <bool B>
		bool operator!=(const mapIterator<B>& x) const { return (_ptr != x.get_pointer()); }

		mapIterator& operator++()
		{ 
			this->next_node();
			return (*this);
		}
		mapIterator& operator--()
		{ 
			this->prev_node();
			return (*this);
		}
		mapIterator	operator++(int)
		{
			mapIterator<IsConst> x(*this);
			this->next_node();
			return (x);
		}
		mapIterator	operator--(int)
		{
			mapIterator<IsConst> x(*this);
			this->prev_node();
			return (x);
		}

		value_type&	operator*() const { return (_ptr->data); }
		value_type*	operator->() const { return (&_ptr->data); }

		node_type* get_pointer() const { return (_ptr); }

	private:
		node_type*	_ptr;

		void next_node()
		{
			if (_ptr->right != _ptr->right->left)
			{
				_ptr = _ptr->right;
				while (_ptr->left != _ptr->left->left)
					_ptr = _ptr->left;
			}
			else
			{
				while (_ptr == _ptr->parent->right && _ptr != _ptr->parent)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
		}

		void prev_node()
		{
			if (_ptr == _ptr->parent)
			{
				while (_ptr->right != _ptr->right->left)
					_ptr = _ptr->right;
			}
			else if (_ptr->left != _ptr->left->left)
			{
				_ptr = _ptr->left;
				while (_ptr->right != _ptr->right->left)
					_ptr = _ptr->right;
			}
			else
			{
				while (_ptr == _ptr->parent->left && _ptr != _ptr->parent)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
		}
	}; // mapIterator

	typedef	Key												key_type;
	typedef	T												mapped_type;
	typedef	ft::pair<const key_type, mapped_type>			value_type;
	typedef	Compare											key_compare;
	typedef	typename Alloc::template rebind<RBTNode>::other	allocator_type;
	typedef	typename allocator_type::reference				reference;
	typedef	typename allocator_type::const_reference		const_reference;
	typedef	typename allocator_type::pointer				pointer;
	typedef	typename allocator_type::const_pointer			const_pointer;
	typedef	mapIterator<false>								iterator;
	typedef	mapIterator<true>								const_iterator;
	typedef	ft::reverse_iterator<iterator>					reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef	typename mapIterator<false>::difference_type	difference_type;
	typedef	typename mapIterator<false>::size_type			size_type;

	class value_compare {
	public:
		friend class		map;
		typedef	bool	 	result_type;
		typedef	value_type 	first_argument_type;
		typedef	value_type 	second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
			{ return (comp(x.first, y.first)); }
	protected:
		value_compare(Compare c) : comp(c) {}
		Compare	comp;
	};

	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{
		m_alloc = alloc;
		m_compare = comp;
		this->create_nil_node();
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_same<InputIterator, int>::value>::type* = 0)
	{
		m_alloc = alloc;
		m_compare = comp;
		this->create_nil_node();

		while (first != last)
			this->insert(*first++);
	}

	map(const map& x)
	{
		this->create_nil_node();
		*this = x;
	}

	~map()
	{
		this->clear();
		m_alloc.destroy(nil_node);
		m_alloc.deallocate(nil_node, 1);
	}

	map& operator=(const map& x)
	{
		if (this == &x)
			return (*this);

		this->clear();
		m_alloc = x.m_alloc;
		m_compare = x.m_compare;

		for (const_iterator it = x.begin(); it != x.end(); it++)
			this->insert(*it);
		return (*this);
	}

	iterator begin() { return (iterator(this->most_left(nil_node->right))); }
	const_iterator begin() const { return (const_iterator(this->most_left(nil_node->right))); }
	iterator end() { return (iterator(nil_node)); }
	const_iterator end() const { return (const_iterator(nil_node)); }

	reverse_iterator rbegin() { return (reverse_iterator(nil_node)); }
	const_reverse_iterator rbegin() const { return (const_reverse_iterator(nil_node)); }
	reverse_iterator rend() { return (reverse_iterator(this->most_left(nil_node->right))); }
	const_reverse_iterator rend() const { return (const_reverse_iterator(this->most_left(nil_node->right))); }

	bool empty() const { return (nil_node == nil_node->right); }

	size_type size() const
	{
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
			n++;
		return (n);
	}

	size_type max_size() const { return (m_alloc.max_size()); }

	mapped_type& operator[] (const key_type& k)
	{
		this->insert(ft::make_pair(k, mapped_type()));
		return (this->find(k)->second);
	}

	ft::pair<iterator,bool> insert(const value_type& val)
	{
		iterator it;

		if (this->count(val.first))
		{
			it = this->find(val.first);
			return (ft::make_pair(it, false));
		}
		else
		{
			it = iterator(this->create_new_node(val));
			return (ft::make_pair(it, true));
		}
	}

	iterator insert(iterator position, const value_type& val)
	{
		(void)position;
		return (this->insert(val).first);
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_same<InputIterator, int>::value>::type* = 0)
	{
		while (first != last)
			this->insert(*first++);
	}

	void erase(iterator position)
	{
		RBTNode* ptr = position.get_pointer();

		if (ptr->left != nil_node && ptr->right != nil_node)
		{
			position--;
			this->swap_nodes(ptr, position.get_pointer());
			this->erase(ptr);
		}
		else
		{
			RBTNode* child = (ptr->left != nil_node) ? ptr->left : ptr->right;

			if (child != nil_node)
				child->parent = ptr->parent;
			if (ptr->parent->left == ptr)
				ptr->parent->left = child;
			else
				ptr->parent->right = child;

			this->delete_node(ptr, child);
		}
	}

	size_type erase(const key_type& k)
	{
		if (this->count(k))
		{
			this->erase(this->find(k));
			return (1);
		}
		return (0);
	}

	void erase(iterator first, iterator last)
	{
		for (iterator it = first++ ; it != last ; it = first++)
			this->erase(it);
	}

	void swap(map& x)
	{
		ft::swap(m_alloc, x.m_alloc);
		ft::swap(m_compare, x.m_compare);
		ft::swap(nil_node, x.nil_node);
	}

	void clear()
	{
		iterator first = this->begin();
		for (iterator it = first++ ; it != this->end() ; it = first++)
			this->erase(it);
	}

	key_compare key_comp() const { return (key_compare()); }
	value_compare value_comp() const { return (value_compare(m_compare)); }

	iterator find(const key_type& k)
	{
		if (this->count(k))
			return (iterator(this->find_node(nil_node->right, k)));
		else
			return (this->end());
	}

	const_iterator find(const key_type& k) const
	{
		if (this->count(k))
			return (const_iterator(this->find_node(nil_node->right, k)));
		else
			return (this->end());
	}

	size_type count(const key_type& k) const
	{
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
		{
			if (this->m_equal(k, it->first))
				n++;
		}
		return (n);
	}

	iterator lower_bound(const key_type& k)
	{
		iterator it = this->begin();
		while (this->m_compare(it->first, k) && it != this->end())
			it++;
		return (it);
	}

	const_iterator lower_bound(const key_type& k) const
	{
		const_iterator it = this->begin();
		while (this->m_compare(it->first, k) && it != this->end())
			it++;
		return (it);
	}

	iterator upper_bound(const key_type& k)
	{
		iterator it = this->begin();
		while (this->m_compare(k, it->first) == false && it != this->end())
			it++;
		return (it);
	}

	const_iterator upper_bound(const key_type& k) const
	{
		const_iterator it = this->begin();
		while (this->m_compare(k, it->first) == false && it != this->end())
			it++;
		return (it);
	}

	ft::pair<iterator,iterator> equal_range(const key_type& k)
		{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

	ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const
		{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

	allocator_type get_allocator (void) const { return (allocator_type()); }

private:
	void create_nil_node()
	{
		nil_node = m_alloc.allocate(1);
		this->map_node_construct(nil_node);
		nil_node->color = BLACK_;
	}

	RBTNode* create_new_node(const value_type& val = value_type())
	{
		RBTNode* new_node = m_alloc.allocate(1);
		this->map_node_construct(new_node, val);

		RBTNode* parent = this->find_parent(nil_node->right, val.first);
		if (parent == nil_node || !this->m_compare(val.first, parent->key()))
			parent->right = new_node;
		else
			parent->left = new_node;
		new_node->parent = parent;

		this->rb_insert(new_node);

		return (new_node);
	}

	void map_node_construct(RBTNode* ptr, const value_type& val = value_type())
	{
		RBTNode tmp(val);
		tmp.left = nil_node;
		tmp.right = nil_node;
		tmp.parent = nil_node;
		tmp.color = RED_;
		m_alloc.construct(ptr, tmp);
	}

	void swap_nodes(RBTNode* a, RBTNode* b)
	{
		if (a->left != b && a->left != nil_node)
			a->left->parent = b;
		if (a->right != b && a->right != nil_node)
			a->right->parent = b;
		if (a->parent != b && a->parent != nil_node)
		{
			if (a->parent->left == a)
				a->parent->left = b;
			else
				a->parent->right = b;
		}

		if (b->left != a && b->left != nil_node)
			b->left->parent = a;
		if (b->right != a && b->right != nil_node)
			b->right->parent = a;
		if (b->parent != a && b->parent != nil_node)
		{
			if (b->parent->left == b)
				b->parent->left = a;
			else
				b->parent->right = a;
		}

		if (a->parent == b)
			a->parent = a;
		if (a->left == b)
			a->left = a;
		if (a->right == b)
			a->right = a;
		if (b->parent == a)
			b->parent = b;
		if (b->left == a)
			b->left = b;
		if (b->right == a)
			b->right = b;

		ft::swap(a->parent, b->parent);
		ft::swap(a->left, b->left);
		ft::swap(a->right, b->right);
		ft::swap(a->color, b->color);

		if (nil_node->right == a)
			nil_node->right = b;
		else if (nil_node->right == b)
			nil_node->right = a;
	}

	void delete_node(RBTNode* ptr, RBTNode* child)
	{
		this->rb_delete(ptr, child);

		m_alloc.destroy(ptr);
		m_alloc.deallocate(ptr, 1);
	}

	RBTNode* find_node(RBTNode* current, const key_type& k) const
	{
		if (current == nil_node || this->m_equal(current->key(), k))
			return (current);
		else if (this->m_compare(k, current->key()))
			return (this->find_node(current->left, k));
		else
			return (this->find_node(current->right, k));
	}

	RBTNode* find_parent(RBTNode* current, const key_type& k) const
	{
		if (!this->m_compare(k, current->key()))
		{
			if (current->right == nil_node)
				return (current);
			else
				return (this->find_parent(current->right, k));
		}
		else
		{
			if (current->left == nil_node)
				return (current);
			else
				return (this->find_parent(current->left, k));
		}
	}

	RBTNode* most_left(RBTNode* root) const
	{
		while (root->left != root->left->left)
			root = root->left;
		return (root);
	}

	bool m_equal(const key_type& lhs, const key_type& rhs) const
		{ return (this->m_compare(lhs, rhs) == false && this->m_compare(rhs, lhs) == false); }

	// Red and Black Tree
	void rb_insert(RBTNode* x)
	{
		RBTNode* parent = x->parent;
		RBTNode* grandparent = parent->parent;
		RBTNode* uncle = (grandparent->right == parent) ? grandparent->left : grandparent->right;

		if (parent == nil_node)
			x->color = BLACK_;
		else if (parent->color == BLACK_)
			return ;
		else if (uncle->color == RED_)
		{
			parent->color = BLACK_;
			uncle->color = BLACK_;
			grandparent->color = RED_;
			this->rb_insert(grandparent);
		}
		else if (uncle->color == BLACK_)
		{
			if (grandparent->left->left == x || grandparent->right->right == x)
			{
				if (grandparent->left->left == x)
					this->left_rotate(grandparent, parent);
				else if (grandparent->right->right == x)
					this->right_rotate(grandparent, parent);
				ft::swap(grandparent->color, parent->color);
			}
			else
			{
				if (grandparent->left->right == x)
					this->left_right_rotate(grandparent, parent, x);
				else if (grandparent->right->left == x)
					this->right_left_rotate(grandparent, parent, x);
				ft::swap(grandparent->color, x->color);
			}
		}
	}

	void rb_delete(RBTNode* v, RBTNode* u)
	{
		if (v->color == RED_ || u->color == RED_)
			u->color = BLACK_;
		else
			this->double_black(u, v->parent);
	}

	void double_black(RBTNode* u, RBTNode* parent)
	{
		RBTNode* sibling = (parent->left != u) ? parent->left : parent->right;

		if (u == nil_node->right)
			return ;
		else if (sibling->color == BLACK_ && (sibling->left->color == RED_ || sibling->right->color == RED_))
		{
			if (sibling == parent->left && sibling->left->color == RED_)
				this->left_rotate(parent, sibling);
			else if (sibling == parent->left && sibling->right->color == RED_)
				this->left_right_rotate(parent, sibling, sibling->right);
			else if (sibling == parent->right && sibling->right->color == RED_)
				this->right_rotate(parent, sibling);
			else if (sibling == parent->right && sibling->left->color == RED_)
				this->right_left_rotate(parent, sibling, sibling->left);

			if (sibling->left->color == RED_)
				sibling->left->color = BLACK_;
			else
				sibling->right->color = BLACK_;
		}
		else if (sibling->color == BLACK_)
		{
			sibling->color = RED_;
			if (parent->color == RED_)
				parent->color = BLACK_;
			else
				this->double_black(parent, parent->parent);
		}
		else if (sibling->color == RED_)
		{
			if (sibling == parent->left)
				this->left_rotate(parent, sibling);
			else
				this->right_rotate(parent, sibling);
			ft::swap(parent->color, sibling->color);
			this->double_black(u, parent);
		}
	}

	void left_rotate(RBTNode* grandparent, RBTNode* parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->right != nil_node)
			parent->right->parent = grandparent;
		grandparent->left = parent->right;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->right = grandparent;
	}

	void right_rotate(RBTNode* grandparent, RBTNode* parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->left != nil_node)
			parent->left->parent = grandparent;
		grandparent->right = parent->left;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->left = grandparent;
	}

	void left_right_rotate(RBTNode* grandparent, RBTNode* parent, RBTNode* x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left != nil_node)
			x->left->parent = parent;
		if (x->right != nil_node)
			x->right->parent = grandparent;
		grandparent->left = x->right;
		parent->right = x->left;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = parent;
		x->right = grandparent;
	}

	void right_left_rotate(RBTNode* grandparent, RBTNode* parent, RBTNode* x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left != nil_node)
			x->left->parent = grandparent;
		if (x->right != nil_node)
			x->right->parent = parent;
		grandparent->right = x->left;
		parent->left = x->right;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = grandparent;
		x->right = parent;
	}

	allocator_type		m_alloc;
	key_compare			m_compare;
	RBTNode*			nil_node;
}; // Map

	template <class Key, class T, class Compare, class Alloc>
	bool operator== (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
		{ return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
		{ return (!(lhs == rhs)); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
		{ return (!(rhs < lhs)); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
		{ return (rhs < lhs); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
		{ return (!(lhs < rhs)); }

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc> & x, map<Key,T,Compare,Alloc> & y)
		{ x.swap(y); }

} // Namespace ft

#endif
