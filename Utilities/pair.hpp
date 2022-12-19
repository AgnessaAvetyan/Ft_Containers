#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    template <typename T>
    void swap(T& a, T& b)
    {
        T c(a);
        a = b;
        b = c;
    }
    template <class T1, class T2>
    class pair
    {
    private:
        typedef T1 first_type;
        typedef T2 second_type;

    public:
        first_type first;
        second_type second;

        pair() : first(first_type()), second(second_type()) {}
        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
        pair(const pair &pr) : first(pr.first), second(pr.second) {}
        pair(const first_type &a, const second_type &b) : first(a), second(b) {}
        pair &operator=(const pair &pr)
        {
            if (this == &pr)
                return *this;
            this->first = pr.first;
            this->second = pr.second;
            return *this;
        }
        void swap(pair &pr)
        {
            ft::swap(first, pr.first);
            ft::swap(second, pr.second);
        }
    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return lhs.first == rhs.first && lhs.second == rhs.second; }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return !(lhs == rhs); }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return lhs.first < rhs.first
                || (!(rhs.first < lhs.first) && (lhs.second < rhs.second)); }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return !(rhs < lhs); }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return rhs < lhs; }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return !(lhs < rhs); }

    template <class T1, class T2>
    void swap(pair<T1, T2> &x, pair<T1, T2> &y)
    {
        ft::swap(x.first, y.first);
        ft::swap(x.second, y.second); 
    }
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    { return pair<T1, T2>(x, y); }
} // namespace ft

#endif // PAIR_HPP