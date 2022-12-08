#ifndef RBTNODE_HPP
#define RBTNODE_HPP
#define RED 1
#define BLACK 0
#define LEFT 0
#define RIGHT 1
#include <cstddef>

class RBTNode
{
private:
    void*       m_value;
    RBTNode*    m_parent;
    RBTNode*    m_child[2];
    bool        m_color;
    RBTNode();

public:
    RBTNode(void *value)
        : m_value(value), m_parent(NULL), m_color(RED)
    {
        m_child[LEFT] = NULL;
        m_child[RIGHT] = NULL;
    }
    // setters
    void    set_parent(RBTNode *parent)
        { m_parent = parent; }
    void    set_child(bool position, RBTNode *child)
        { m_child[position] = child; }
    void    set_color(bool color)
        { m_color = color; }

    // getters
    void*   get_value() const
        { return m_value; }
    RBTNode* get_parent() const
        { return m_parent; }
    RBTNode* get_child(bool position) const
        { return m_child[position]; }
    bool   get_color() const
        { return m_color; }
    bool    get_position() const
        { return this->m_child[RIGHT] ? RIGHT : LEFT; }
    RBTNode* get_grandparent() const
        { return m_parent == NULL ? NULL : m_parent->m_parent; }
    RBTNode* get_uncle() const
        { return m_parent == NULL ? NULL : m_parent->get_sibling(); }
    RBTNode* get_sibling() const
        { return m_parent == NULL ? NULL : m_parent->m_child[1 - get_position()]; }

    RBTNode* get_next(bool pos) const
    {
        RBTNode* next_node = m_child[pos];
        if (m_child[pos] != NULL)
        {
            while (next_node->m_child[1 - pos] != NULL)
                next_node = next_node->m_child[1 - pos];
        }
        else
            next_node = this->get_next_parent(pos);
        return next_node;
    }

    RBTNode* get_next_parent(bool pos) const
    {
        RBTNode* next_parent;
        if (m_parent == NULL)
            return NULL;
        else if (this->get_position() == 1 - pos)
            next_parent = m_parent;
        else
            next_parent = m_parent->get_next_parent(pos);
        return next_parent;
    }

    void    nodes_swap(RBTNode* node, RBTNode** root)
    {
        RBTNode** self_node;
        RBTNode* self_parent;
        RBTNode* self_left_child;
        RBTNode* self_right_child;

        RBTNode** other_node;
        RBTNode* other_parent;
        RBTNode* other_left_child;
        RBTNode* other_right_child;
        bool color;

        self_parent = node->m_parent;
        self_left_child = node->m_child[LEFT];
        self_right_child = node->m_child[RIGHT];

        other_parent = m_parent;
        other_left_child = m_child[LEFT];
        other_right_child = m_child[RIGHT];

        if(node->m_parent != NULL)
        {
            if(node->m_parent->get_position() == LEFT)
                self_node = &node->m_parent->m_child[LEFT];
            else
                self_node = &node->m_parent->m_child[RIGHT];
        }
        else
            self_node = root;

        if(m_parent != NULL)
        {
            if(m_parent->get_position() == LEFT)
                other_node = &m_parent->m_child[LEFT];
            else
                other_node = &m_parent->m_child[RIGHT];
        }
        else
            other_node = root;

        if(node->m_parent == this)
        {
            self_parent = node;
            self_node = NULL;
            if(m_child[LEFT] == node)
                other_left_child = this;
            else
                other_right_child = this;
        }
        else if (m_parent == node)
        {
            other_parent = this;
            other_node = NULL;
            if(node->m_child[LEFT] == this)
                self_left_child = node;
            else
                self_right_child = node;
        }

        m_parent = self_parent;
        m_child[LEFT] = self_left_child;

        if (m_child[LEFT])
            m_child[LEFT]->m_parent = this;
        m_child[RIGHT] = self_right_child;
        if (m_child[RIGHT])
            m_child[RIGHT]->m_parent = this;
        if (self_node)
            *self_node = this;

        node->m_parent = other_parent;
        node->m_child[LEFT] =  other_left_child;

        if (node->m_child[LEFT])
            node->m_child[LEFT]->m_parent = node;
        node->m_child[RIGHT] = self_right_child;
        if (node->m_child[RIGHT])
            node->m_child[RIGHT]->m_parent = node;
        if (other_node)
            *other_node = node;

        color = node->m_color;
        node->m_color = m_color;
        m_color = color;
    }
};

#endif // RBTNODE_HPP