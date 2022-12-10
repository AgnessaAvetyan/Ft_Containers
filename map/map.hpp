#ifndef MAP_HPP
#define MAP_HPP
#include "../Utilities/utilities.hpp"
#include "map_iterator.hpp"

namespace ft
{
template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>> >
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
    typedef typename value_type&                        reference;
    typedef typename const value_type&                  const_reference;
    typedef typename allocator_type::pointer&           pointer;
    typedef typename const allocator_type::pointer&     const_pointer;
    typedef map_iterator<value_type>                    iterator;
    typedef map_iterator<const value_type>              const_iterator;
    typedef ft::reverse_iteratorc<iterator>             reverse_iterator;
    typedef ft::reverse_iteratorc<const_iterator>       const_reverse_iterator;
private:
    size_type       m_size;
    RBTree          rb_tree;
    key_compare     m_compare;
    allocator_type  m_alloc;

};
} // namespace ft
#endif // MAP_HPP