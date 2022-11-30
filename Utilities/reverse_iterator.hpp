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
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type        value_type;
        typedef typename iterator_traits<Iterator>::difference_type   difference_type;
        typedef typename iterator_traits<Iterator>::pointer           pointer;
        typedef typename iterator_traits<Iterator>::reference         reference;

    private:
        iterator_type   iterType;
    
    public:
        reverse_iterator() : iterType() {}
        explicit reverse_iterator (iterator_type it) : iterType(it) {}
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) 
        {   iterType = rev_it.iterType;   }

        iterator_type base() const
        {   return iterType;    }

        // Operators
        reference operator*() const
        {
            iterator_type tmp = iterType;
            return (*--tmp);
        }

        reverse_iterator operator+ (difference_type n) const
        {   return reverse_iterator(iterType - n);  }

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
            --(*this);
            return temp;
        }

        reverse_iterator& operator+= (difference_type n)
        {
            iterType -= n;
            return *this;
        }

        reverse_iterator operator- (difference_type n) const
        {   return reverse_iterator(iterType + n);  }

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
            ++(*this);
            return temp;
        }

        reverse_iterator& operator-= (difference_type n)
        {
            iterType += n;
            return *this;
        }

        pointer operator->() const
        {   return &(operator*());  }

        reference operator[] (difference_type n) const
        {   return iterType[-n-1];  }
    };

    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {   return lhs.base() == rhs.base();  }

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {   return lhs.base() != rhs.base();    }

    template <class Iterator> 
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {   return lhs.base() < rhs.base(); }

    template <class Iterator> 
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {   return lhs.base() <= rhs.base();    }

    template <class Iterator> 
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {   return lhs.base() > rhs.base(); }

    template <class Iterator> 
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {   return lhs.base() >= rhs.base();    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
                                            const reverse_iterator<Iterator>& rev_it)
    {   return rev_it + n;  }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
                                                                    const reverse_iterator<Iterator>& rhs)
    {   return lhs.base() - rhs.base(); }
}

#endif //REVERSE_ITERATOR_HPP
