#ifndef MAP_HPP
#define MAP_HPP
#include "../Utilities/utilities.hpp"
#include "map_iterator.hpp"

namespace ft
{
template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
class map
{
public:
    typedef Key                                         key_type;
    typedef T                                           mapped_type;
    typedef ft::pair<const key_type, mapped_type>       value_type;
    typedef std::size_t                                 size_type;
    typedef std::ptrdiff_t                              difference_type;
    typedef Compare                                     key_compare;
    typedef Allocator                                   allocator_type;
    typedef value_type&                                 reference;
    typedef const value_type&                           const_reference;
    typedef typename allocator_type::pointer&           pointer;
    typedef typename allocator_type::const_pointer&     const_pointer;
    typedef map_iterator<value_type>                    iterator;
    typedef map_iterator<const value_type>              const_iterator;
    typedef reverse_iterator<const_iterator>            const_reverse_iterator;
    typedef reverse_iterator<iterator>                  reverse_iterator;
    class   value_compare : std::binary_function<value_type,value_type, bool>
    {
        public:
            typedef bool        result_type;
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;
        private:
            key_compare m_comp;
        public:
            value_compare (key_compare c) : m_comp(c) {}
            bool operator() (const value_type& x, const value_type& y) const
                { return comp(x.first, y.first); }
    };
private:
    size_type       m_size;
    RBTree          rb_tree;
    key_compare     m_compare;
    allocator_type  m_alloc;
    typedef typename allocator_type::template rebind<RBTNode>::other allocate_rbtnode_type;
    allocate_rbtnode_type allocate_node;
private:
    //  helper functions
    pair<iterator, bool> search_insert(RBTNode* node, value_type* pair)
    {

    }

    iterator insert_iterator(iterator pos, RBTNode* node, value_type* pair)
    {

    }

    size_type serach_erase(const key_type& key)
    {

    }

    void delete_one_node(RBTNode* node)
    {

    }

    void deep_clear(RBTNode* node)
    {
        
    }

public:
    // ctors and dtor
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : m_size(0), m_compare(comp), m_alloc(alloc){}
    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : m_compare(comp), m_alloc(alloc)
    {
        size_type s = 0;
        for (InputIterator it = first; it != last; it++)
        {
            this->insert(*first);
            s++;
        }
        m_size = s;
    }
    map (const map& x) : m_size(x.m_size), m_alloc(x.m_alloc) { *this = x; }
    map& operator= (const map& x)
    {
        if (this == &x)
            return *this;
        if (m_size > 0)
            this->clear();
        m_compare = x.m_compare;
        for (const_iterator it = x.begin(); it != x.end(); it++)
            this->insert(*it);
        m_size = x.m_size;
    }
    ~map() { this->clear(); }

    // Capacity
    bool empty() const {return m_size == 0 ? true : false; }
    size_type size() const { return m_size; }
    size_type max_size() const { m_alloc.max_size(); }

    //Iterators
    iterator begin()  { return iterator(rb_tree.get_leaf(LEFT), this); }

    const_iterator begin() const  { return const_iterator(rb_tree.get_leaf(LEFT), (void*)this); }

    reverse_iterator rbegin() 
    {
        iterator it = this->end();
        reverse_iterator rev_it(it);

        return (rev_it);
    }

    const_reverse_iterator rbegin() const 
    {
        const_iterator const_it = this->end();
        const_reverse_iterator rev_const_it(const_it);

        return (rev_const_it);
    }

    iterator end() 
    {
        iterator it(rb_tree.get_leaf(RIGHT), this);

        if(it)
            ++it;
        return (it);
    }

    const_iterator end() const 
    {
        const_iterator it(rb_tree.get_leaf(RIGHT), this);

        if(it)
            ++it;
        return (it);
    }

    reverse_iterator rend() 
    {
        iterator it = this->begin();
        reverse_iterator rev_it(it);

        return (rev_it);
    }

    const_reverse_iterator rend() const
    {
        const_iterator const_it = this->begin();
        const_reverse_iterator rev_const_it(const_it);

        return (rev_const_it);
    }

    //Modifiers
    pair<iterator,bool> insert (const value_type& val)
    {
        RBTNode*    node;
        value_type  pair;

        pair = m_alloc.allocate(1);
        m_alloc.construct(pair, val);
        node = allocate_node.allocate(1);
        allocate_node.construct(node, pair);

        return (this->search_insert(node, pair));
    }

    iterator insert (iterator position, const value_type& val)
    {
        RBTNode*    node;
        value_type  pair;

        pair = m_alloc.allocate(1);
        m_alloc.construct(pair, val);
        node = allocate_node.allocate(1);
        allocate_node.construct(node, pair);

        return (this->insert_iterator(position, node, pair));
    }

    template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        for(; first != last; first++)
            this->insert(*first);
    }

    void erase (iterator position)
    {
        RBTNode*    node;

        node = position.get_node();
        rb_tree.deletion(node);
        m_size--;

        return (delete_one_node(node));
    }

    size_type erase (const key_type& key)
    {
        return (this->serach_erase(key));
    }

    void erase (iterator first, iterator last)
    {
        iterator it;

        while (first != last)
        {
            it = first;
            ++first;
            this->erase(it);
        }
    }

    void clear(void)
    {
        RBTNode* node;

        node = rb_tree.get_root();
        if (node)
            this->deep_clear(node);
        rb_tree.set_root_Null();
        m_size = 0;
    }

    void swap (map& x)
    {
        size_type       size;
        RBTree          rbtree;
        key_compare     compare;

        size = x.m_size;
        x.m_size = m_size;
        m_size = size;

        rbtree = x.rb_tree;
        x.rb_tree = rb_tree;
        rb_tree = rbtree;

        compare = x.m_compare;
        x.m_compare = m_compare;
        m_compare = compare;
    }

    // Element access
    mapped_type& operator[] (const key_type& k)
    {
        RBTNode*    cur_node = rb_tree.get_root();
        RBTNode*    child;
        value_type* cur_pair;

        while (cur_node)
        {
            cur_pair = cur_node->get_value();
            if (m_compare(k, cur_pair->first))
                child = cur_node->get_child(LEFT);
            else if (m_compare(cur_pair->first, k))
                child = cur_node->get_child(RIGHT);
            else
                return cur_pair->second;
            cur_node = child;
        }
        pair<iterator, bool> new_node = this->insert(ft::make_pair(k, mapped_type()));
        return new_node.first->second;
    }
    mapped_type& at (const key_type& k)
    {
        RBTNode*    cur_node = rb_tree.get_root();
        RBTNode*    child;
        value_type* cur_pair;

        while (cur_node)
        {
            cur_pair = cur_node->get_value();
            if (m_compare(k, cur_pair->first))
                child = cur_node->get_child(LEFT);
            else if (m_compare(cur_pair->first, k))
                child = cur_node->get_child(RIGHT);
            else
                return cur_pair->second;
            cur_node = child;
        }
        throw std::out_of_range("map: at()");
    }
    const mapped_type& at (const key_type& k) const
    {
        RBTNode*    cur_node = rb_tree.get_root();
        RBTNode*    child;
        value_type* cur_pair;

        while (cur_node)
        {
            cur_pair = cur_node->get_value();
            if (m_compare(k, cur_pair->first))
                child = cur_node->get_child(LEFT);
            else if (m_compare(cur_pair->first, k))
                child = cur_node->get_child(RIGHT);
            else
                return cur_pair->second;
            cur_node = child;
        }
        throw std::out_of_range("map: at()");
    }
    //  Observers
    key_compare key_comp() const { return m_compare; }
    value_compare value_comp() const
    {
        value_compare val_comp(m_compare);
        return val_comp;
    }

    //  Operations
    iterator find (const key_type& k)
    {
        RBTNode*    cur_node = rb_tree.get_root();
        value_type* cur_pair;

        while (cur_node)
        {
            cur_pair = cur_node->get_value();
            if (m_compare(k, cur_pair->first))
                cur_node = cur_node->get_child(LEFT);
            else if (m_compare(cur_pair->first, k))
                cur_node = cur_node->get_child(RIGHT);
            else
            {
                iterator it(cur_node, this);
                return it;
            }
        }
        return this->end();
    }

    const_iterator find (const key_type& k) const
    {
        RBTNode*    cur_node = rb_tree.get_root();
        value_type* cur_pair;

        while (cur_node)
        {
            cur_pair = cur_node->get_value();
            if (m_compare(k, cur_pair->first))
                cur_node = cur_node->get_child(LEFT);
            else if (m_compare(cur_pair->first, k))
                cur_node = cur_node->get_child(RIGHT);
            else
            {
                const_iterator it(cur_node, this);
                return it;
            }
        }
        return this->end();
    }

    size_type count (const key_type& k) const
    {
        RBTNode*    cur_node = rb_tree.get_root();
        value_type* cur_pair;

        while (cur_node)
        {
            cur_pair = cur_node->get_value();
            if (m_compare(k, cur_pair->first))
                cur_node = cur_node->get_child(LEFT);
            else if (m_compare(cur_pair->first, k))
                cur_node = cur_node->get_child(RIGHT);
            else
                return 1;
        }
        return 0;
    }

    //  Allocator
    allocator_type get_allocator() const { return m_alloc; }
};
} // namespace ft
#endif // MAP_HPP