#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>

namespace ft
{
    template <typename Iterator>
    class iterator_traits
    {
    public:
        typedef typename Iterator::deffierent_type different_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;

    };
    
    template <typename Iterator>
    class iterator_traits<Iterator*>
    {
    public:
        typedef std::ptrdiff_t different_type;
        typedef Iterator value_type;
        typedef Iterator* pointer;
        typedef Iterator& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename Iterator>
    class iterator_traits<const Iterator*>
    {
    public:
        typedef std::ptrdiff_t different_type;
        typedef Iterator value_type;
        typedef const Iterator* pointer;
        typedef const Iterator& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

}


#endif //ITERATOR_TRAITS_HPP