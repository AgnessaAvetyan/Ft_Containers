#ifndef STACK_HPP
#define STACK_HPP
#include "../vector/vector.hpp"

namespace ft
{
    template <typename T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T                               value_type;
        typedef Container                       container_type;
        typedef value_type&                     reference;
        typedef const value_type&               const_reference;
        typedef typename Container::size_type   size_type;

    private:
        container_type m_c;

    public:
        explicit stack (const container_type& ctnr = container_type()) : m_c(ctnr) {}
        stack(const stack& stk) : m_c(stk.m_c) {}
        stack& operator=(const stack& stk)
        {
            m_c = stk.m_c;
            return *this;
        }

        bool empty() const { return m_c.empty(); }
        size_type size() const { return m_c.size(); }

        value_type& top() { return m_c.back(); }
        const value_type& top() const { return m_c.back(); }

        void push (const value_type& val) { m_c.push_back(val); }
        void pop() { m_c.pop_back(); }

        template <class A, class Cont>
        friend bool operator== (const stack<A, Cont>& lhs, const stack<A, Cont>& rhs)
            { return lhs.m_c == rhs.m_c; }
        template <class A, class Cont>
        friend bool operator!= (const stack<A, Cont>& lhs, const stack<A, Cont>& rhs)
            { return lhs.m_c != rhs.m_c; }
        template <class A, class Cont>
        friend bool operator<  (const stack<A, Cont>& lhs, const stack<A, Cont>& rhs)
            { return lhs.m_c < rhs.m_c; }
        template <class A, class Cont>
        friend bool operator<= (const stack<A, Cont>& lhs, const stack<A, Cont>& rhs)
            { return lhs.m_c <= rhs.m_c; }
        template <class A, class Cont>
        friend bool operator>  (const stack<A, Cont>& lhs, const stack<A, Cont>& rhs)
            { return lhs.m_c > rhs.m_c; }
        template <class A, class Cont>
        friend bool operator>= (const stack<A, Cont>& lhs, const stack<A, Cont>& rhs)
            { return lhs.m_c >= rhs.m_c; }
    }; // class stack

} // namespace ft

#endif 