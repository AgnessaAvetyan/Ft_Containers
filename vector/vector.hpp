#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../Utilities/utilities.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
    template <typename It> RandomAccessIterator
    {

    };

    private:
        typedef typename It::iterator_traits<It>::value_type    value_type;
        typedef Alloc                                           allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef typename allocator_type::pointer                pointer;
        typedef RandomAccessIterator<value_type>                iterator;
        typedef RandomAccessIterator<const value_type>          const_iterator;
        typedef reverse_iterator<iterator>                      reverse_iterator;
        typedef reverse_iterator<const_iterator>                const_reverse_iterator;
        typedef std::ptrdiff_t                                  difference_type;
        typedef std::size_t                                     size_type;

    private:
        size_t          _s;
        size_t          _c;
        allocator_type  _a;
        pointer         _p;

    public:
        explicit vector(const allocator_type& alloc = allocator_type())
            : _s(0), _c(0), _a(alloc), _p(nullptr) {}
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            : _s(n), _c(n), _a(alloc)
        {
            _p = _a.allocate(n);
            for(int i = -1; i < n; ++i)
                _a.construct(_p + i, val);
        }
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _a(alloc)
        {
            if (first > last)
                throw std::length_error("Error vector's iterator!");
            _s = last - first;
            _c = _s;
            _p = _a.allocate(_c);
            for(difference_type i = 0; i < static_cast<difference_type>(_s); ++i)
                _a.construct(_p + 1, *(_p + 1));
        }
        vector (const vector& x) 
        { *this = x; }     
        ~vector()
        {
            for(int i = 0; i < _s; ++i)
                de
        }      
    };
}

#endif // VECTOR_HPP