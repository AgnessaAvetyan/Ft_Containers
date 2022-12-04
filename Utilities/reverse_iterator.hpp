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
        iterator_type get_IT() const
        { return iterType; }
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) 
        {   iterType = rev_it.get_IT();   }

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
            ++(*this);
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
            --(*this);
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
    
    template <class IT1, class IT2>
    bool operator== (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs)
    {   return lhs.base() == rhs.base();  }

    template <class IT1, class IT2>
    bool operator!= (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() != rhs.base();  }

    template <class IT1, class IT2> 
    bool operator<  (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() < rhs.base(); }

    template <class IT1, class IT2> 
    bool operator<= (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() <= rhs.base(); }

    template <class IT1, class IT2> 
    bool operator>  (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() > rhs.base(); }

    template <class IT1, class IT2> 
    bool operator>= (const reverse_iterator<IT1>& lhs, const reverse_iterator<IT2>& rhs) 
    {   return lhs.base() >= rhs.base();    }

    template <class IT>
    reverse_iterator<IT> operator+ (typename reverse_iterator<IT>::difference_type n,
                                            const reverse_iterator<IT>& rev_it)
    {   return rev_it + n;  }

    template <class IT1, class IT2> 
    typename reverse_iterator<IT1>::difference_type operator- (const reverse_iterator<IT1>& lhs,
                                                                    const reverse_iterator<IT2>& rhs)
    {   return rhs.base() - lhs.base(); }

}

#endif //REVERSE_ITERATOR_HPP
