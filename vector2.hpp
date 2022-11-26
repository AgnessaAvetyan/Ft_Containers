vector& operator=(const vector& x)
{
    if (this = &x)
        return *this;
    for (size_type i = 0; i < _s; ++i)
        _a.destroy(_p + 1);
    this->_s = x._s
    if (_c < _s)
    {
        if (_c != 0)
            _a.deallocate(_p, _c);
        _c = _s;
        _p = _a.allocate(_c);
    }
    for (size_type i = 0; i < _s; ++i)
        _a.construct(_p + i, x[i]);
    return *this;
}

iterator begin()
{
    return iterator(_p);
}

const_iterator begin() const
{
    return const_iterator(_p);
}

iterator end()
{
    return iterator(_p + _s);
}

const_iterator end() const
{
    return const_iterator(_p + _s);
}

reverse_iterator rbegin()
{
    return reverse_iterator(_p + _s);
}

const_reverse_iterator rbegin() const
{
    return const_reverse_iterator(_p + _s);
}

reverse_iterator rend()
{
    return reverse_iterator(_p);
}

const_reverse_iterator rend() const
{
    return const_reverse_iterator(_p);
}

const_iterator cbegin() const
{
    return const_iterator(_p);
}

const_iterator cend() const
{
    return const_iterator(_p + _s);
}

const_reverse_iterator crbegin() const
{
    return const_reverse_iterator(_p + _s);
}

const_reverse_iterator crend() const
{
    return const_reverse_iterator(_p);
}


reference at (size_type n)
{
    if (n >= _s)
        throw std::out_of_range("out of range");
    return (*(_p + n));
}

const_reference at (size_type n) const
{
    if (n >= _s)
        throw std::out_of_range("out of range");
    return (*(_p + n));
}

reference operator[] (size_type n)
{
    return at(n);
}

const_reference operator[] (size_type n) const
{
    return at(n);
}

reference front()
{
    return (*_p);
}

const_reference front() const
{
    return (*_p);
}

reference back()
{
    return (*(_p + _s - 1));
}

const_reference back() const
{
    return (*(_p + _s - 1));
}

value_type* data()
{
    return front();
}

const value_type* data() const
{
    return front();
}

allocator_type get_allocator() const
{
    return this->_a;
}

template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (int i = 0 ; i < rhs.size(); ++i)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
    return true;
}
    
template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return (!(lhs == rhs));
}

template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return lhs < rhs ;
}

template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return lhs > rhs;
}

template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return !(lhs < rhs);
}

template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
    x.ft::swap(y);
}

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
    difference_type n1 = std::distance(begin(), first);
    difference_type n2 = std::distance(last, end());

    bool last = 

    _a.destroy();
    for(; first != last; first++)
    {

    }
}

void swap (vector& x)
{
    ft::swap(_a, x._a);
    ft::swap(_p, x._p);
    ft::swap(_s, x._s);
    ft::swap(_c, x._c);
}

void clear()
{

}