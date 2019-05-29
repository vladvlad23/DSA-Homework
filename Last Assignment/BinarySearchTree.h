//
// Created by Vlad on 29-May-19.
//

#ifndef LAST_ASSIGNMENT_BINARYSEARCHTREE_H
#define LAST_ASSIGNMENT_BINARYSEARCHTREE_H

template <class TElem>
class BinarySearchTree
{
    struct Node
    {
        TElem value;
        Node *parent;
        Node *right;
        Node *left;
    };
private:
    Node* root;
    int size;
    bool empty;
public:

    BinarySearchTree();
    BinarySearchTree(TElem e);
    ~BinarySearchTree();
    void insertNode(TElem e);
    void removeNode(Node *node);
    TElem getRoot();
    bool isEmpty();
    Node* findNode(TElem elem) const
    {
        Node *node = root;
        while(true)
        {
            if(elem==node->value)
                return node;
            if(elem < node->value)
            {
                if(node->left == nullptr)
                    return nullptr;
                else
                    node = node->left;
            }
            else
            {
                if(node->right == nullptr)
                    return nullptr;
                else
                    node = node->right;
            }
        }
    }

};


#endif //LAST_ASSIGNMENT_BINARYSEARCHTREE_H
