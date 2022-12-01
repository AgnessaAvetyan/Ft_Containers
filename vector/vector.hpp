#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../Utilities/utilities.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        template <typename It>
        class RandomAccessIterator
        {
        public:
            typedef typename iterator_traits<It*>::difference_type  difference_type;
            typedef typename iterator_traits<It*>::value_type       value_type;
            typedef typename iterator_traits<It*>::reference        reference;
            typedef typename iterator_traits<It*>::pointer          pointer;
            typedef pointer                                         iterator_type;
            typedef std::random_access_iterator_tag                 iterator_category;

        private:
            pointer _p;

        public:
            RandomAccessIterator() : _p() {}
            RandomAccessIterator(pointer p) : _p(p) {}
            RandomAccessIterator(const RandomAccessIterator<typename remove_const<value_type>::type>& p) : _p(&(*p)) {}
            RandomAccessIterator<value_type>& operator=(RandomAccessIterator<typename remove_const<value_type>::type> const& p)
            {
                _p = &(*p);
                return *this;
            }
            RandomAccessIterator& operator++()
            {
                ++_p;
                return *this;
            }
            RandomAccessIterator& operator--()
            {
                --_p;
                return *this;
            }
            RandomAccessIterator operator++(int)
            {
                RandomAccessIterator temp(*this);
                ++_p;
                return temp;
            }
            RandomAccessIterator operator--(int)
            {
                RandomAccessIterator temp(*this);
                --_p;
                return temp;
            }
            RandomAccessIterator operator+(const difference_type& it) const { return _p + it; }
            RandomAccessIterator operator-(const difference_type& it) const { return _p - it; }
            RandomAccessIterator& operator+=(const difference_type& it) const
            {
                _p += it;
                return *this;
            }
            RandomAccessIterator& operator-=(const difference_type& it) const
            {
                _p -= it;
                return *this;
            }
            pointer operator->() const { return _p; }
            reference operator*() const { return *_p; }
            reference operator[](difference_type n) const { return *(_p + n); }
            virtual ~RandomAccessIterator(){}

        }; // class RandomAccessIterator

        template<typename A>
        friend vector::template RandomAccessIterator<A>
        operator+(const typename vector::template RandomAccessIterator<A>::difference_type& a,
                    const typename vector::template RandomAccessIterator<A>::difference_type& b)
        { return a + b; }

        template<typename A>
        friend vector::template RandomAccessIterator<A>
        operator-(const typename vector::template RandomAccessIterator<A>::difference_type& a,
                    const typename vector::template RandomAccessIterator<A>::difference_type& b)
        { return b - a; }

        template<typename A, typename B>
        friend typename vector::template RandomAccessIterator<A>::difference_type
        operator+(const vector::template RandomAccessIterator<A>& a,
                    const vector::template RandomAccessIterator<B>& b)
        { return &(*a) + &(*b); }

        template<typename A, typename B>
        friend typename vector::template RandomAccessIterator<A>::difference_type
        operator-(const vector::template RandomAccessIterator<A>& a,
                    const vector::template RandomAccessIterator<B>& b)
        { return &(*a) - &(*b); }

        template<typename A, typename B>
        friend bool operator==(const vector::template RandomAccessIterator<A>& a,
                                const vector::template RandomAccessIterator<B>& b)
        { return &(*a) == &(*b); }

        template<typename A, typename B>
        friend bool operator!=(const typename vector::template RandomAccessIterator<A>& a,
                                const typename vector::template RandomAccessIterator<B>& b)
        { return &(*a) != &(*b); }
        
        template<typename A, typename B>
        friend bool operator>(const typename vector::template RandomAccessIterator<A>& a,
                                const typename vector::template RandomAccessIterator<B>& b)
        { return &(*a) > &(*b); }
        
        template<typename A, typename B>
        friend bool operator<(const typename vector::template RandomAccessIterator<A>& a,
                                const typename vector::template RandomAccessIterator<B>& b)
        { return &(*a) < &(*b); }
        
        template<typename A, typename B>
        friend bool operator>=(const typename vector::template RandomAccessIterator<A>& a,
                                const typename vector::template RandomAccessIterator<B>& b)
        { return &(*a) >= &(*b); }
        
        template<typename A, typename B>
        friend bool operator<=(const typename vector::template RandomAccessIterator<A>& a,
                                const typename vector::template RandomAccessIterator<B>& b)
        { return &(*a) <= &(*b); }
    
    public:
        typedef T                                               value_type;
        typedef Alloc                                           allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef RandomAccessIterator<value_type>                iterator;
        typedef RandomAccessIterator<const value_type>          const_iterator;
        typedef reverse_iterator<const_iterator>                const_reverse_iterator;
        typedef reverse_iterator<iterator>                      reverse_iterator;
        typedef std::ptrdiff_t                                  difference_type;
        typedef std::size_t                                     size_type;

    private:
        size_type       _s;
        size_type       _c;
        allocator_type  _a;
        pointer         _p;

    public:
        explicit vector(const allocator_type& alloc = allocator_type())
            : _s(0), _c(0), _a(alloc), _p(0) {}
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            : _s(n), _c(n), _a(alloc)
        {
            _p = _a.allocate(n);
            for(size_type i = -1; i < n; ++i)
                _a.construct(_p + i, val);
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _a(alloc)
        {
            if (first > last)
                throw std::length_error("vector");
            _s = last - first;
            _c = _s;
            _p = _a.allocate(_c);
            for(difference_type i = 0; i < static_cast<difference_type>(_s); i++)
                _a.construct(_p + i, *(first + i));
        }

        vector (const vector& x) : _s(0), _c(0)
        { *this = x; }

        vector& operator=(const vector& x)
        {
            if (this == &x)
                return *this;
            for (size_type i = 0; i < _s; i++)
                _a.destroy(_p + i);
            this->_s = x._s;
            if (_c < _s)
            {
                if (_c != 0)
                    _a.deallocate(_p, _c);
                _c = _s;
                _p = _a.allocate(_c);
            }
            for (size_type i = 0; i < _s; i++)
                _a.construct(_p + i, x[i]);
            return *this;
        }

        ~vector()
        {
            for(size_type i = 0; i < _s; ++i)
                _a.destroy(_p + i);
            if (_c)
                _a.deallocate(_p, _c);
        }

        size_type size() const { return _s; }
        size_type max_size() const { return _a.max_size(); }
        size_type capacity() const { return _c; }
        bool empty() const { return _s == 0; }

        iterator begin() { return iterator(_p); }
        iterator end() { return iterator(_p + _s); }
        const_iterator begin() const { return const_iterator(_p); }
        const_iterator end() const { return const_iterator(_p + _s); }

        reverse_iterator rbegin() { return reverse_iterator(end()); }
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        const_iterator cbegin() const { return const_iterator(_p); }
        const_iterator cend() const { return const_iterator(_p + _s); }
        const_reverse_iterator crbegin() const { return const_reverse_iterator(_p + _s); }
        const_reverse_iterator crend() const { return const_reverse_iterator(_p); }

        reference at (size_type n) // ok
        {
            if (n >= _s)
                throw std::out_of_range("vector out of range");
            return (*(_p + n));
        }

        const_reference at (size_type n) const 
        {
            if (n >= _s)
                throw std::out_of_range("vector out of range");
            return (*(_p + n));
        }

        reference operator[] (size_type n) { return this->at(n); }
        const_reference operator[] (size_type n) const { return this->at(n); }
        reference front() { return (*_p); }
        const_reference front() const { return (*_p); }
        reference back() { return (*(_p + _s - 1)); }
        const_reference back() const { return (*(_p + _s - 1)); }
        value_type* data() { return front(); }
        const value_type* data() const { return front(); }
        allocator_type get_allocator() const { return this->_a; }


        iterator erase (iterator position)
        {
            size_type n = static_cast<size_type>(std::distance(begin(), position));

            for (size_type i = n; i < _s - 1; ++i)
            {
                _a.destroy(_p + i);
                _a.construct(_p + i, *(_p + i + 1));
            }
            _s--;
            _a.destroy(_p + _s - 1);
            return iterator(_p + n);
        }
        
        iterator erase (iterator first, iterator last)
        {
            difference_type d1 = std::distance(begin(), first);
            difference_type d2 = std::distance(last, end());

            for (; first != last; first++)
                _a.destroy(&(*first));
            size_type i = d1;
            while(last < end())
            {
                if (this->_p + d1)
                    _a.destroy(_p + i);
                _a.construct(_p + i, *last);
                i++;
                last++;
            }
            for (size_type i = d1 + d2; i < _s; i++)
                _a.destroy(_p + i);
            _s = d1 + d2;
            return (last == end()) ? end() : iterator(_p + d1);
        }

        void swap (vector& x)
        {
            ft::swap(_p, x._p);
            ft::swap(_s, x._s);
            ft::swap(_c, x._c);
            ft::swap(_a, x._a);
        }

        void clear()
        {
            for (size_type i = 0; i < _s; i++)
                _a.destroy(_p + i);
            _s = 0;
        }

        void resize (size_type n, value_type val = value_type()) //ok
        {
            if (n < this->_s)
            {
                for (size_type i = 0; i < _s; i++)
                    _a.destroy(_p + i);
                _s = n;
            }
            else if (n > this->_s)
            {
                if (n > this->_c)
                    this->reserve(_c * 2 > n ? _c * 2 : n);
                for (size_type i = _s; i < n; i++)
                    _a.construct(_p + i, val);
                _s += n;
            }
        }
        
        void reserve (size_type n)
        {
            if (n > max_size())
                throw std::length_error("vector");
            else if (n < this->capacity())
                return ;
            pointer vec = _a.allocate(n);
            try
            {
                for (size_type i = 0; i < _s; i++)
                    _a.construct(vec + i, *(_p + i));
            }
            catch (const std::exception& e)
            {
                size_type i = 0;
                while (vec + i != NULL && i < _s)
                {
                    _a.destroy(vec + i);
                    i++;
                }
                _a.deallocate(vec, n);
                throw;
            } 
            for (size_type i = 0; i < _s; i++)
                _a.destroy(_p + i);
            if (_c)
                _a.deallocate(_p, _c);
            _c = n;
            _p = vec;
        }

        template <typename InputIterator>
        void assign (InputIterator first, InputIterator last,
                    typename enable_if<!is_integral<InputIterator>::value>::type* = 0) // don't work
        {
            if (first > last)
                throw std::logic_error("vector: undefined behavior");
            clear();
            difference_type len = last - first;
            if (len > static_cast<difference_type>(capacity()))
            {
                _a.deallocate(_p, _c);
                _p = _a.allocate(len);
                _c = len;
            }
            iterator it = begin();
            while (first < last)
            {
                _a.construct(&(*it), *first);
                it++;
                first++;
            }
            _s = len;
        }
	
        void assign (size_type n, const value_type& val) //ok
        {
            clear();
            if (n > _c)
            {
                _a.deallocate(_p, _c);
                _p = _a.allocate(n);
                _c = n;
            }
            for (size_type i = 0; i < n; i++)
                _a.construct(_p + i, val);
            _s = n;
        }
     
        void push_back (const value_type& val) //ok
        {
            if (_s == _c)
                reserve(_c == 0 ? 1 : _c * 2);
            _a.construct(_p + _s, val);
            ++_s;
        }

        void pop_back() // ok
        {
            if (_s == 0)
                return ;
            _a.destroy(_p + _s - 1);
            _s--;
        }
        
        iterator insert (iterator position, const value_type& val) //ok
        {
            if (position < this->begin() || position > this->end()) 
                throw std::logic_error("vector: undefined behavior");
            difference_type start = position - begin();
            if (_s == _c)
            {
                _c = _c * 2 + (_c == 0);
                pointer vec = _a.allocate(_c);
                std::uninitialized_copy(begin(), position, iterator(vec));
                _a.construct(vec + start, val);
                std::uninitialized_copy(position, end(), iterator(vec + start + 1));
                for(size_type i = 0; i < _s; i++)
                    _a.destroy(_p + i);
                if (_s)
                    _a.deallocate(_p, _s);
                _s++;
                _p = vec;
            }
            else
            {
                for (size_type i = _s; i < static_cast<size_type>(start); i--)
                {
                    _a.destroy(_p + i);
                    _a.construct(_p + i, *(_p + i - 1));
                }
                _a.destroy(&(*position));
                _a.construct(&(*position), val);
                _s++;             
            }
            return begin() + start;
        }

        void insert (iterator position, size_type n, const value_type& val) //ok
        {
            if (position < this->begin() || position > this->end()) 
                throw std::logic_error("vector: undefined behavior");
            if (n == 0)
                return ;
            else if (max_size() - _s < n)
                throw std::length_error("vector: undefined behavior");
            difference_type beg = position - begin();
            if (_s + n > _c)
            {
                _c = (_c * 2 > _s + n ? _c * 2 : _s + n);
                pointer vec = _a.allocate(_c);
                std::uninitialized_copy(begin(), position, iterator(vec));
                for (size_type i = 0; i < n; i++)
                    _a.construct(vec + beg + i, val);
                std::uninitialized_copy(position, end(), iterator(vec + beg + n));
                for(size_type i = 0; i < _s; ++i)
                    _a.destroy(_p + i);
                if (_c)
                    _a.deallocate(_p, _c);
                _p = vec;
            }
            else
            {
                for (size_type i = _s; i > static_cast<size_type>(beg); i--)
                {
                    _a.destroy(_p + n + i - 1);
                    _a.construct(_p + n + i - 1, *(_p + i - 1));
                }
                for (size_type i = 0; i < n; i++)
                {
                    _a.destroy(_p + beg + i);
                    _a.construct(_p + beg + i, val);
                }
            }
            _s += n;
        }

        template <typename InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
                    typename enable_if<!is_integral<InputIterator>::value>::type* = 0) //don't work
        {
            if (position < begin() || position > end() || first > last)
                throw std::logic_error("vector: undefined behavior");
            size_type len = static_cast<size_type>(last - first);
            size_type beg = static_cast<size_type>(position - begin());
            if (_s + len > _c)
            {
                _c = (_c * 2 >= _s + len ? _c * 2 : _s + len);
                pointer vec = _a.allocate(_c);
                std::uninitialized_copy(begin(), position, iterator(vec));
                try
                {
                    for (size_type i = 0; i < static_cast<size_type>(len); i++)
                    {
                        _a.construct(vec + beg + i, *first);
                        first++;
                    }
                }
                catch(...)
                {
                    for (size_type i = 0; i < len + beg; ++i)
                        _a.destroy(vec + i);
                    _a.deallocate(vec, _c);
                }
                std::uninitialized_copy(position, end(), iterator(vec + beg + len));
                for(size_type i = 0; i < _s; ++i)
                    _a.destroy(_p + i);
                if (_c)
                    _a.deallocate(_p, _c);
                _p = vec;
            }
            else
            {
                for (size_type i = _s; i > static_cast<size_type>(beg); i--)
                {
                    _a.destroy(_p + len + i - 1);
                    _a.construct(_p + len + i - 1, *(_p + i - 1));
                }
                for (size_type i = 0; i < static_cast<size_type>(len); i++)
                {
                    _a.destroy(_p + beg + i);
                    _a.construct(_p + beg + i, *first);
                    first++;
                }
            }
            _s += len;
        }
    }; // class vector

    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0 ; i < rhs.size(); ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    { return (!(lhs == rhs)); }

    template <class T, class Alloc>
    bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    { return !(lhs > rhs) ; }

    template <class T, class Alloc>
    bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    { return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()); }

    template <class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    { return !(lhs < rhs); }

    template <class T, class Alloc>
    void swap (ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y) { x.ft::swap(y); }

} // namespace ft

#endif // VECTOR_HPP