#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "RBTree.hpp"

namespace ft
{
    template <typename T, bool constness = false>
    class map_iterator
    {
    public:
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef std::size_t                         size_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef typename is_const<T, constness>     value_type;
        typedef typename is_const<T, constness>*    pointer;
        typedef typename is_const<T, constness>&    reference;

    private:
        RBTNode*    m_node;
        RBTNode*    m_last_node;
        void*       m_map;
    public:
        map_iterator() : m_node(NULL), m_last_node(NULL), m_map(NULL){}
        map_iterator(RBTNode* node_p, void* map_p)
            : m_node(NULL), m_last_node(NULL), m_map(map_p){}
        map_iterator(const map_iterator& map_it)
            { *this = map_it; }
        template <typename I>
        map_iterator(const map_iterator<I, false>& map_it)
            { *this = map_it; }
        map_iterator<I, constness> operator=(const map_iterator& map_it)
        {
            if (this == &map_it)
                return *this;
            m_node = map_it.m_node;
            m_last_node = map_it.m_last_node;
            m_map = map_it.m_map;
            return *this;
        }
        map_iterator<I, constness> operator=(const map_iterator<I, false>& map_it)
        {
            m_node = map_it.get_node();
            m_last_node = map_it.get_last_node();
            m_map = map_it.get_map();
            return *this;
        }
        RBTNode*    get_node() const { return m_node; }
        RBTNode*    get_last_node() const { return m_last_node; }
        void*       get_map() const { return m_map; }
        void        set_node(RBTNode* node, void* map)
        {
            m_node = node;
            m_map = map;
        }
        reference operator*() const { return *static_cast<T*>(m_node->get_value()); }
        pointer operator->() const { return &(operator*()); }

        map_iterator& operator--()
        {
            if (!m_node)
                m_node = m_last_node;
            else
                m_node = m_node->get_next(LEFT);
            return *this;
        }
        map_iterator operator--(int)
        {
            map_iterator it = *this;
            it.operator--();
            return it;
        }
        map_iterator& operator++()
        {
            if (!m_node)
                m_node = m_last_node;
            else
                m_node = m_node->get_next(RIGHT);
            return *this;
        }
        map_iterator operator++(int)
        {
            map_iterator it = *this;
            it.operator++();
            return it;
        }
        bool operator==(const map_iterator& map_it) const
            { return m_node == map_it.m_node; }
        bool operator==(const map_iterator<T, false>& map_it)
            { return m_node == map_it.get_node(); }
        bool operator==(const map_iterator<T, true>& map_it)
            { return m_node == map_it.get_node(); }
        bool operator!=(const map_iterator& map_it) const
            { return m_node != map_it.m_node; }
        bool operator!=(const map_iterator<T, false>& map_it)
            { return m_node != map_it.get_node(); }
        bool operator!=(const map_iterator<T, true>& map_it)
            { return m_node != map_it.get_node(); }
        ~map_iterator(){}
        
    }; // map_iterator
} // namespace ft


#endif