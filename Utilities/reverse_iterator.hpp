#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator                                              iterator_type;
        // typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type        value_type;
        typedef typename iterator_traits<Iterator>::difference_type   difference_type;
        // typedef typename iterator_traits<Iterator>::pointer           pointer;
        // typedef typename iterator_traits<Iterator>::reference         reference;

    private:
        iterator_type   iterType;

    public:
        reverse_iterator() : iterType() {}
        reverse_iterator(typename Iterator::value_type* it) { iterType = Iterator(it); }
        reverse_iterator(const Iterator& it)
        {
            iterType = it;
            --iterType;
        }

        // template< class U > 
        reverse_iterator& operator=( const reverse_iterator& other )
        {
            iterType = other.get_IT();
            return *this;
        }

        iterator_type get_IT() const
        { return iterType; }

        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) 
        {   iterType = rev_it.get_IT();   }

        iterator_type base() const
        {   return ++Iterator(iterType);    }

        // Operators
        typename iterator_type::value_type& operator*()
        {
            // iterator_type tmp = iterType;
            return (*iterType);
        }

        reverse_iterator operator+ (difference_type n) const
        {   return reverse_iterator(iterType - n + 1);  }

        // The pre-increment version
        reverse_iterator& operator++()
        {
            --iterType;
            return *this;
        }
        
        // The post-increment version
        reverse_iterator  operator++(int)
        {
            reverse_iterator temp = *this;
            ++(*this);
            return temp;
        }

        reverse_iterator& operator+= (int n)
        {
            iterType -= n;
            return *this;
        }

        reverse_iterator operator- (int n) const
        {   return reverse_iterator(iterType + n + 1);  }

        std::ptrdiff_t operator-(const reverse_iterator& it) const 
        {   return it.get_IT() - iterType; }
        // The pre-decrement version
        reverse_iterator& operator--()
        {
            ++iterType;
            return *this;
        }

        // The post-decrement version
        reverse_iterator  operator--(int)
        {
            reverse_iterator temp = *this;
            --(*this);
            return temp;
        }

        reverse_iterator& operator-= (int n)
        {
            iterType += n;
            return *this;
        }

        typename Iterator::value_type* operator->() const
        {   return &(*iterType);  }

        typename Iterator::value_type& operator[] (size_t n) const
        {   return *(iterType - n);  }

    };
    
    template <class IT1, class IT2>
    bool operator== (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs)
    {   return lhs.base() == rhs.base();  }

    template <class IT1, class IT2>
    bool operator!= (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() != rhs.base();  }

    template <class IT1, class IT2> 
    bool operator<  (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() > rhs.base(); }

    template <class IT1, class IT2> 
    bool operator<= (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() >= rhs.base(); }

    template <class IT1, class IT2> 
    bool operator>  (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() < rhs.base(); }

    template <class IT1, class IT2> 
    bool operator>= (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() <= rhs.base();    }

    template <class IT>
    reverse_iterator<IT> operator+ (typename reverse_iterator<IT>::difference_type n,
                                            const reverse_iterator<IT>& rev_it)
    {   return rev_it + n;  }

    // template <class IT1, class IT2> 
    // typename reverse_iterator<IT1>::difference_type operator- (const reverse_iterator<IT1>& lhs,
    //                                                                 const reverse_iterator<IT2>& rhs)
    // {   return rhs.base() - lhs.base(); }

}

#endif //REVERSE_ITERATOR_HPP
