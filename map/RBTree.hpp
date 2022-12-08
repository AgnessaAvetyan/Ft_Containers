#ifndef RBTREE_HPP
#define RBTREE_HPP
#include "RBTNode.hpp"

class RBTree
{
private:
    RBTNode*    m_root;
    
    void   rotate_subtree(RBTNode *parent, bool position)
    {
        RBTNode* grandparent = parent->get_parent();
        RBTNode* sibling = parent->get_child(1 - position);
        if (!sibling)
            return ;
        RBTNode* sb_child = sibling->get_child(position);
        parent->set_child(1 - position, sb_child);
        if (sb_child)
            sb_child->set_parent(parent);
        sibling->set_child(position, parent);
        parent->set_parent(sibling);
        sibling->set_parent(grandparent);
        if (grandparent)
        {
            if (parent == grandparent->get_child(RIGHT))
                grandparent->set_child(RIGHT, sibling);
            else
                grandparent->set_child(LEFT, sibling);
        }
        else
            m_root = sibling;
    }

    void balance_after_insert(RBTNode* node, RBTNode* parent)
    {
        RBTNode* grandparent = parent->get_parent();
        RBTNode* uncle = parent->get_sibling();
        bool pos = parent->get_position();
        do
        {
            if (parent->get_color() == BLACK)
                break ;
            if (grandparent == NULL)
            {
                parent->set_color(BLACK);
                break ;
            }
            if (uncle == NULL || uncle->get_color() == BLACK)
            {
                if (node == parent->get_child(1 - pos))
                {
                    rotate_subtree(parent, pos);
                    parent = grandparent->get_child(pos);
                }
                rotate_subtree(grandparent, 1 - pos);
                grandparent->set_color(RED);
                parent->set_color(BLACK);
                break ;
            }
            if (parent->get_color() == RED || uncle->get_color() == RED)
            {
                parent->set_color(BLACK);
                uncle->set_color(BLACK);
                if (grandparent != m_root)
                    grandparent->set_color(RED);
                node = grandparent;
                parent = node->get_parent();
            }
        } while (parent != NULL);   
    }

public:
    RBTree() : m_root(NULL) {}
    RBTNode*    get_root() const { return m_root; }
    void        set_root(RBTNode* root) { m_root = root; }
    void        insertion(RBTNode* node, RBTNode *parent, bool pos)
    {
        node->set_color(RED);
        node->set_child(RIGHT, NULL);
        node->set_child(LEFT, NULL);
        node->set_parent(parent);
        if (parent == NULL)
        {
            m_root = node;
            return ;
        }
        parent->set_child(pos, node);
        balance_after_insert(node, parent);
    }
    
    void        deletion(RBTNode* node)
    {
        RBTNode* next;
        RBTNode* parent;
        RBTNode* child;

        if (node->get_child(RIGHT) != NULL && node->get_child(LEFT) != NULL)
        {
            next = node->get_next(RIGHT);
            node->nodes_swap(next, &m_root);
        }
        parent = node->get_parent();
        if (node->get_color() == RED)
        {
            
        }
    }
    ~RBTree();
};


#endif // RBTREE_HPP