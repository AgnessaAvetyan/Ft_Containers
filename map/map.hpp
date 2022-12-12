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
    typedef reverse_iterator<iterator>                  reverse_iterator;
    typedef reverse_iterator<const_iterator>            const_reverse_iterator;

private:
    size_type       m_size;
    RBTree          rb_tree;
    key_compare     m_compare;
    allocator_type  m_alloc;

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
        
    }
    const mapped_type& at (const key_type& k) const;






};
} // namespace ft
#endif // MAP_HPP