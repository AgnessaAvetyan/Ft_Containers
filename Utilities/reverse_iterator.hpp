#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft
{
    template <typename It>
    class reverse_iterator
    {
    private:
        iterator_type iType;
    public:
        typedef It                                                  iterator_type;
        typedef typename It::iterator_traits<It>::iterator_category iterator_category;
        typedef typename It::iterator_traits<It>::value_type value_type;
        typedef typename It::iterator_traits<It>::different_type    different_type;
        typedef typename It::iterator_traits<It>::pointer           pointer;
        typedef typename It::iterator_traits<It>::reference         reference;


                    
    public:
        reverse_iterator(/* args */);
        ~reverse_iterator();
    };
}

#endif

