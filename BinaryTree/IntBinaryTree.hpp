#ifndef _INT_BINARY_TREE_HPP_
#define _INT_BINARY_TREE_HPP_

#include "IntBinaryTreeNode.hpp"

#include <iostream>

class IntBinaryTree
{
private:
    IntBinaryTreeNode *_root;
public:
    IntBinaryTree() : _root(nullptr) {}

    IntBinaryTreeNode* find(int valToFind) const;

    void insert(int newVal);
    void remove(int existingVal);

    std::ostream& print(std::ostream &os) const;
};

#endif
