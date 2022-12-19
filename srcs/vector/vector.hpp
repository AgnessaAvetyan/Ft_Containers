#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../../Utilities/utilities.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        template <bool is_const>
        class RandomAccessIterator
        {
        public:
            typedef std::ptrdiff_t  difference_type;
            typedef typename ft::conditional<is_const, const T, T>::type       value_type;
            typedef std::size_t size_type;
        private:
            value_type* m_p;

        public:
            RandomAccessIterator() : m_p(NULL) {}
            RandomAccessIterator(value_type* const p) : m_p(p) {}
            template <bool B>
            RandomAccessIterator(const RandomAccessIterator<B>& p, typename ft::enable_if<!B>::type* = 0) { m_p = p.get_pointer(); }
            RandomAccessIterator& operator=(RandomAccessIterator<is_const> const& p)
            {
                m_p = p.get_pointer();
                return *this;
            }
            RandomAccessIterator& operator++()
            {
                m_p++;
                return *this;
            }
            RandomAccessIterator& operator--()
            {
                m_p--;
                return *this;
            }
            RandomAccessIterator operator++(int)
            {
                RandomAccessIterator<is_const> temp(*this);
                m_p++;
                return temp;
            }
            RandomAccessIterator operator--(int)
            {
                RandomAccessIterator<is_const> temp(*this);
                m_p--;
                return temp;
            }

            RandomAccessIterator    operator+(int it) const { return m_p + it; }
            RandomAccessIterator    operator-(int it) const { return m_p - it; }
            difference_type         operator-(const RandomAccessIterator& it) const { return m_p - it.get_pointer(); }

            RandomAccessIterator& operator+=(const difference_type& it)
            {
                m_p += it;
                return *this;
            }
            RandomAccessIterator& operator-=(const difference_type& it)
            {
                m_p -= it;
                return *this;
            }

            value_type* operator->() const { return m_p; }
            value_type& operator*() const { return *m_p; }
            value_type& operator[](size_type n) const { return *(m_p + n); }

            value_type* get_pointer() const { return m_p; }

            template <bool B>
            bool operator==(const RandomAccessIterator<B>& it) const { return m_p == it.get_pointer(); }
            template <bool B>
            bool operator!=(const RandomAccessIterator<B>& it) const { return m_p != it.get_pointer(); }
            template <bool B>
            bool operator<(const RandomAccessIterator<B>& it) const { return m_p < it.get_pointer(); }
            template <bool B>
            bool operator>(const RandomAccessIterator<B>& it) const { return m_p > it.get_pointer(); }
            template <bool B>
            bool operator>=(const RandomAccessIterator<B>& it) const { return m_p >= it.get_pointer(); }
            template <bool B>
            bool operator<=(const RandomAccessIterator<B>& it) const { return m_p <= it.get_pointer(); }

            friend RandomAccessIterator operator+(int it, const RandomAccessIterator& x)
                { return x.get_pointer() + it; }
        }; // RandomAccessIterator

    public:
        typedef T                                                       value_type;
        typedef Alloc                                                   allocator_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef RandomAccessIterator<false>                             iterator;
        typedef RandomAccessIterator<true>                              const_iterator;
        typedef reverse_iterator<const_iterator>                        const_reverse_iterator;
        typedef reverse_iterator<iterator>                              reverse_iterator;
        typedef typename RandomAccessIterator<false>::difference_type   difference_type;
        typedef typename RandomAccessIterator<false>::size_type         size_type;

    private:
        size_type       m_s;
        size_type       m_c;
        allocator_type  m_a;
        pointer         m_p;

    public:
        explicit vector(const allocator_type& alloc = allocator_type()) : m_s(0), m_c(0), m_a(alloc), m_p(nullptr) {}
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            : m_s(n), m_c(n), m_a(alloc)
        {
            m_p = m_a.allocate(n);
            for(size_type i = 0; i < n; ++i)
                m_a.construct(m_p + i, val);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename enable_if<!is_same<InputIterator, int>::value>::type* = 0) : m_c(0), m_a(alloc)
        {
            for (InputIterator i = first; i != last; i++)
                m_c++;
            m_s = m_c;
            m_p = m_a.allocate(m_c);
            for(difference_type i = 0; i < static_cast<difference_type>(m_s); i++)
                m_a.construct(m_p + i, *first++);
        }

        vector(const vector& x) : m_s(0), m_c(0) { *this = x; }

        vector& operator=(const vector& x)
        {
            if (this == &x)
                return *this;
            for (size_type i = 0; i < m_s; i++)
                m_a.destroy(m_p + i);
            this->m_s = x.m_s;
            if (m_c < x.m_s)
            {
                if (m_c != 0)
                    m_a.deallocate(m_p, m_c);
                m_c = m_s;
                m_p = m_a.allocate(m_c);
            }
            for (size_type i = 0; i < m_s; i++)
                m_a.construct(m_p + i, x[i]);
            return *this;
        }

        ~vector()
        {
            for(size_type i = 0; i < m_s; ++i)
                m_a.destroy(m_p + i);
            if (m_c)
                m_a.deallocate(m_p, m_c);
        }

        size_type size() const { return m_s; }
        size_type max_size() const { return m_a.max_size(); }
        size_type capacity() const { return m_c; }
        bool empty() const { return m_s == 0; }

        iterator begin() { return iterator(m_p); }
        iterator end() { return iterator(m_p + m_s); }
        const_iterator begin() const { return const_iterator(m_p); }
        const_iterator end() const { return const_iterator(m_p + m_s); }

        reverse_iterator rbegin() { return reverse_iterator(end()); }
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        const_iterator cbegin() const { return const_iterator(m_p); }
        const_iterator cend() const { return const_iterator(m_p + m_s); }
        const_reverse_iterator crbegin() const { return const_reverse_iterator(m_p + m_s); }
        const_reverse_iterator crend() const { return const_reverse_iterator(m_p); }

        reference at(size_type n)
        {
            if (n >= m_s)
                throw std::out_of_range("vector");
            return (*(m_p + n));
        }

        const_reference at(size_type n) const 
        {
            if (n >= m_s)
                throw std::out_of_range("vector");
            return (*(m_p + n));
        }

        reference operator[](size_type n) { return this->at(n); }
        const_reference operator[](size_type n) const { return this->at(n); }
        reference front() { return (*m_p); }
        const_reference front() const { return (*m_p); }
        reference back() { return (*(m_p + m_s - 1)); }
        const_reference back() const { return (*(m_p + m_s - 1)); }
        value_type* data() { return front(); }
        const value_type* data() const { return front(); }
        allocator_type get_allocator() const { return this->m_a; }


        iterator erase(iterator position)
        {
            size_type n = position - this->begin();

            for (size_type i = n; i < m_s - 1; ++i)
            {
                m_a.destroy(m_p + i);
                m_a.construct(m_p + i, *(m_p + i + 1));
            }
            m_s--;
            m_a.destroy(m_p + m_s - 1);
            return iterator(m_p + n);
        }
        
        iterator erase(iterator first, iterator last)
        {
            size_type d1 = first - this->begin();
            size_type d2 = this->end() - last;

            for (; first != last; first++)
                m_a.destroy(&(*first));
                
            size_type i = d1;
            while(last < end())
            {
                if (this->m_p + d1)
                    m_a.destroy(m_p + i);
                m_a.construct(m_p + i, *last);
                i++;
                last++;
            }
            for (size_type i = d1 + d2; i < m_s; i++)
                m_a.destroy(m_p + i);
            m_s = d1 + d2;
            return (last == end()) ? end() : iterator(m_p + d1);
        }

        void swap(vector& x)
        {
            ft::swap(m_p, x.m_p);
            ft::swap(m_s, x.m_s);
            ft::swap(m_c, x.m_c);
            ft::swap(m_a, x.m_a);
        }

        void clear()
        {
            for (size_type i = 0; i < m_s; i++)
                m_a.destroy(m_p + i);
            m_s = 0;
        }

        void resize(size_type n, value_type val = value_type())
        {
            this->reserve(n);
            if (n < this->m_s)
            {
                for (size_type i = n; i < m_s; i++)
                    m_a.destroy(m_p + i);
            }
            else if (n > this->m_s)
            {
                for (size_type i = m_s; i < n; i++)
                    m_a.construct(m_p + i, val);
            }
            m_s = n;
        }
        
        void reserve(size_type n)
        {
            if (n > max_size())
                throw std::length_error("vector");

            else if (n < this->capacity())
                return ;

            pointer vec = m_a.allocate(n);
            for (size_type i = 0; i < m_s; i++)
                m_a.construct(vec + i, *(m_p + i));
            for (size_type i = 0; i < m_s; i++)
                m_a.destroy(m_p + i);
            if (m_c)
                m_a.deallocate(m_p, m_c);
            m_c = n;
            m_p = vec;
        }

        template <typename InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
        {
            clear();
            difference_type len = 0;

            for (InputIterator i = first; i != last; i++)
                len++;
            if (len > static_cast<difference_type>(capacity()))
            {
                m_a.deallocate(m_p, m_c);
                m_p = m_a.allocate(len);
                m_c = len;
            }
            iterator it = begin();
            while (first != last)
            {
                m_a.construct(&(*it), *first);
                it++;
                first++;
            }
            m_s = len;
        }
	
        void assign(size_type n, const value_type& val)
        {
            clear();
            if (n > m_c)
            {
                m_a.deallocate(m_p, m_c);
                m_p = m_a.allocate(n);
                m_c = n;
            }
            for (size_type i = 0; i < n; i++)
                m_a.construct(m_p + i, val);
            m_s = n;
        }
     
        void push_back(const value_type& val)
        {
            if (m_s == m_c)
                reserve(m_c == 0 ? 1 : m_c * 2);
            m_a.construct(m_p + m_s, val);
            ++m_s;
        }

        void pop_back()
        {
            if (m_s == 0)
                return ;
            m_a.destroy(m_p + m_s - 1);
            m_s--;
        }
  
        iterator insert(iterator position, const value_type& val)
        {
            if (position < this->begin() || position > this->end()) 
                throw std::logic_error("vector");

            difference_type	n = position - this->begin();
			this->reserve(m_s + 1);
			position = this->begin() + n;
			m_s++;
			if ( position == this->end() - 1 )
				m_a.construct( m_p + m_s - 1, val );
			else
			{
				m_a.construct( m_p + m_s - 1, m_p[m_s - 2] );
				for (iterator it = this->end() - 3; it >= position ; it-- )
					*(it + 1) = *it;
				*position = val;
			}
			return position;
        }

        void insert(iterator position, size_type n, const value_type& val)
        {
            if (position < this->begin() || position > this->end()) 
                throw std::logic_error("vector");

            if (n == 0)
                return ;
            else if (max_size() - m_s < n)
                throw std::length_error("vector");

            difference_type	len = position - this->begin();
			this->reserve(m_s + n);
			position = this->begin() + len;
			pointer	ptr = m_p + m_s;
			for (size_type i = 0; i < n; i++)
			{
				m_a.construct(ptr, *(ptr - n));
				ptr++;
			}
			m_s += n;
			for (iterator it = this->end() - n - 2; it >= position ; it--)
				*(it + n) = *it;
			for (size_type i = 0; i < n; i++)
			{
				*position = val;
				position++;
            }
        }

        template <typename InputIterator>
        void insert(iterator position, typename enable_if<!is_integral<InputIterator>::value,
                        InputIterator>::type first, InputIterator last)
        {
            if (position < begin() || position > end())
                throw std::logic_error("vector");

            size_type count = 0;
            for (InputIterator it = first; it != last; it++)
                count++;

            difference_type	n = position - this->begin();
            this->reserve(m_s + count);
            position = this->begin() + n;
            pointer	ptr = m_p + m_s;
            for (size_type i = 0; i < count; i++)
            {
                m_a.construct( ptr, *(ptr - count) );
                ptr++;
            }
            m_s += count;
            for (iterator it = this->end() - count - 2; it >= position ; it--)
                *(it + count) = *it;
            for (size_type i = 0; i < count; i++)
            {
                *position = *first++;
                position++;
            }
        }
    }; //vector

    template <class X, class A>
    bool operator==(const vector<X,A>& lhs, const vector<X,A>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class X, class A>
    bool operator!=(const vector<X,A>& lhs, const vector<X,A>& rhs)
    { return (!(lhs == rhs)); }

    template <class X, class A>
    bool operator<(const vector<X,A>& lhs, const vector<X,A>& rhs)
    { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

    template <class X, class A>
    bool operator<=(const vector<X,A>& lhs, const vector<X,A>& rhs)
    { return !(rhs < lhs); }

    template <class X, class A>
    bool operator>(const vector<X,A>& lhs, const vector<X,A>& rhs)
    { return rhs < lhs; } 

    template <class X, class A>
    bool operator>=(const vector<X,A>& lhs, const vector<X,A>& rhs)
    { return !(lhs < rhs); }
    
    template <class T, class Alloc>
    void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }

} // namespace ft

#endif // VECTOR_HPP