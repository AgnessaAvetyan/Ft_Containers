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

    //Iterators
    iterator begin() 
        { return iterator(rb_tree.get_leaf(LEFT), this); }

    const_iterator begin() const 
        { return const_iterator(rb_tree.get_leaf(LEFT), (void*)this); }

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

    ~map() { this->clear(); }
};
} // namespace ft
#endif // MAP_HPP