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
            // parent is black
            if (parent->get_color() == BLACK)
                break ;
            // parent is root
            if (grandparent == NULL)
            {
                parent->set_color(BLACK);
                break ;
            }
            // uncle is BLACK or NULL and parent is RED
            if (uncle == NULL || uncle->get_color() == BLACK)
            {
                // parent is RIGHT(LEFT) child of grandparent and node is RIGHT(LEFT) child of parent
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
            // uncle is RED and parent is RED
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
    
    void distant_nephew_rebalance(RBTNode* parent, RBTNode* sibling, RBTNode* distant_nephew, bool pos)
    {
        rotate_subtree(parent, pos);
        parent->set_color(BLACK);
        distant_nephew->set_color(BLACK);
        sibling->set_color(parent->get_color());
    }

    void close_nephew_rebalance(RBTNode* parent, RBTNode* sibling, RBTNode* close_nephew, RBTNode* distant_nephew, bool pos)
    {
        rotate_subtree(sibling, 1 - pos);
        close_nephew->set_color(BLACK);
        sibling->set_color(RED);
        distant_nephew = sibling;
        sibling = close_nephew;
        distant_nephew_rebalance(parent, sibling, distant_nephew, pos);
    }

    void sibling_rebalance(RBTNode* parent, RBTNode* sibling, RBTNode* close_nephew, RBTNode* distant_nephew, bool pos)
    {
        rotate_subtree(parent, pos);
        parent->set_color(RED);
        sibling->set_color(BLACK);
        sibling = close_nephew;

        distant_nephew = sibling->get_child(1 - pos);
        if (distant_nephew && distant_nephew->get_color() == RED)
        {
            distant_nephew_rebalance(parent, sibling, distant_nephew, pos);
            return ;
        }
        close_nephew = sibling->get_child(pos);
        if (close_nephew && close_nephew->get_color() == RED)
        {
            close_nephew_rebalance(parent, sibling, close_nephew, distant_nephew, pos);
            return ;
        }
        parent->set_color(BLACK);
        sibling->set_color(RED);
    }

    void delete_black_leaf(RBTNode* node, RBTNode* parent)
    {
        bool        pos = node->get_position();
        RBTNode*    sibling = parent->get_child(1 - pos);
        RBTNode*    close_nephew = sibling->get_child(pos);
        RBTNode*    distant_nephew = sibling->get_child(1 - pos);

        parent->set_child(pos, NULL);
        do
        {
            if (sibling->get_color() == RED)
            {
                this->sibling_rebalance(parent, sibling, close_nephew, distant_nephew, pos);
                return ;
            }
            if (distant_nephew && distant_nephew->get_color() == RED)
            {
                distant_nephew_rebalance(parent, sibling, distant_nephew, pos);
                return ;
            }
            if (close_nephew && close_nephew->get_color() == RED)
            {
                close_nephew_rebalance(parent, sibling, close_nephew, distant_nephew, pos);
                return ;
            }
            if (parent->get_color() == RED)
            {
                parent->set_color(BLACK);
                sibling->set_color(RED);
                return ;
            }
            sibling->set_color(RED);
            node = parent;
            parent = node->get_parent();
            if (!parent)
                pos = node->get_position();
        } while (parent);
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
        // tree is empty
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


        // node has two children // swap the parent, children pointers and the color with next node
        if (node->get_child(RIGHT) != NULL && node->get_child(LEFT) != NULL)
        {
            next = node->get_next(RIGHT);
            node->nodes_swap(next, &m_root);
        }
        // node has 0 or 1 child
        parent = node->get_parent();
        if (node->get_color() == RED)
        { // node is RED, and has either 0 or 2 children
            if (parent == NULL)
                m_root = NULL;
            else
                parent->set_child(node->get_position(), NULL);
            return ;
        }
        // node is black and has 1 child
        child = node->get_child(LEFT);
        if (!child)
            child = node->get_child(RIGHT);
        if (child)
        {
            child->set_color(BLACK);
            child->set_parent(parent);
            if (!parent)
                m_root = child;
            else
                parent->set_child(node->get_position(), child);
            return ;
        }
        // node is black and doesn't have any children
        if (!parent)
        {
            m_root = NULL;
            return ;
        }
        this->delete_black_leaf(node, parent);
    }
    ~RBTree();
};


#endif // RBTREE_HPP