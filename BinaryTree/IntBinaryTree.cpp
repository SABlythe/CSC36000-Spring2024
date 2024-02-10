#include "IntBinaryTree.hpp"

using namespace std;

IntBinaryTreeNode* findHelper(IntBinaryTreeNode *inSubTree, int valToFind)
{
    if (!inSubTree)
        return nullptr;

    if (inSubTree->data() == valToFind)
        return inSubTree;

    if (inSubTree->data() < valToFind)
        return findHelper(inSubTree->right(), valToFind);

    // must be in left subtree (or we would already have returned)
    return findHelper(inSubTree->left(), valToFind);
}

IntBinaryTreeNode*
IntBinaryTree:: find(int valToFind) const
{
    return findHelper(_root, valToFind);
}

// intoSubTree -- the subtree into which we want to insert
// returns : updated version of subtree
IntBinaryTreeNode* insertHelper(IntBinaryTreeNode *intoSubTree, int valToAdd)
{
    if (intoSubTree == nullptr) // empty tree!
    {
        IntBinaryTreeNode *newTree = new IntBinaryTreeNode(valToAdd);
        return newTree;
    }
    if (valToAdd < intoSubTree->data() )
    {
        // want to insert in left subtree
        IntBinaryTreeNode *newSubTree = insertHelper(intoSubTree->left(), valToAdd);
        intoSubTree->left() = newSubTree;
        newSubTree->parent() = intoSubTree;
        return intoSubTree;
    }
    else if (valToAdd > intoSubTree->data() )
    {
        // want to insert into right subtree
        IntBinaryTreeNode *newSubTree = insertHelper(intoSubTree->right(), valToAdd);
        intoSubTree->right() = newSubTree;
        newSubTree->parent() = intoSubTree;
        return intoSubTree;
    }
    else // == ... so already found in subtree!!
    {
        return intoSubTree;
    }

}



void
IntBinaryTree::insert(int newVal)
{
    _root=insertHelper(_root, newVal);
}


IntBinaryTreeNode*
removeHelper(int existingVal, IntBinaryTreeNode *fromSubTree)
{
  // no subtree? no need to remove anything. 
  if (!fromSubTree)
    return nullptr;

  // is node we need to remove in left subtree?
  if (existingVal < fromSubTree->data())
    {
      // recursively remove from left subtree
      fromSubTree->left() = removeHelper(existingVal, fromSubTree->left() );
    }
  else if (existingVal > fromSubTree->data())
    {
      // recursively remove from right subtree
      fromSubTree->right() = removeHelper(existingVal, fromSubTree->right() );
    }
  else // this is the node we want to remove!
    {
      if (fromSubTree->isLeaf())  // 0 children
	{
	  fromSubTree=nullptr;
	}
      else if (fromSubTree->left() && fromSubTree->right() ) // 2 children
	{
          // find the largest node in the left subtree ...
	  IntBinaryTreeNode *toDel = fromSubTree->left();
	  while(toDel->right()!=nullptr)
	    {
	      toDel = toDel->right();
	    }

          // back up largest value in left subtree. 
	  int valueToMove = toDel->data();

          // remove node containing largest value in subtree ...
	  fromSubTree->left()=removeHelper(valueToMove, fromSubTree->left());
          if (fromSubTree->left()) 
            fromSubTree->left()->parent() = fromSubTree;
          // ... but place its value in the node we really want to "remove"
	  fromSubTree->data() = valueToMove;
	}
      else // 1 child
	{
	  if (fromSubTree->left() ) // no right subtree since only 1 child
          {
            fromSubTree->left()->parent() = fromSubTree->parent();
	    fromSubTree = fromSubTree->left();
          }
	  else // only have right child
          {
            fromSubTree->right()->parent() = fromSubTree->parent();
	    fromSubTree = fromSubTree->right();
          }
	}
      
    }

  // no tree left? return NULL
  if (!fromSubTree)
    return nullptr;
  
  return fromSubTree;
}



void
IntBinaryTree::remove(int existingVal)
{
    IntBinaryTreeNode *toDel = find(existingVal);
    if (!toDel)
    {
        cerr << "Sorry, \"" << existingVal << "\" is not in tree!"
            << endl;
        return;
    }
   
    _root = removeHelper(existingVal, _root);
}


void inOrderPrint(IntBinaryTreeNode *currNode, ostream &os)
{
    if (currNode==nullptr)
        return;

    inOrderPrint(currNode->right(), os);

    // indent the node properly to display as tree
    for (int indentCount=0; indentCount<currNode->depth(); indentCount++)
        os << "    ";
    currNode->print(os);
    os << endl;

    inOrderPrint(currNode->left(), os);
}

std::ostream&
IntBinaryTree::print(std::ostream &someStream) const
{
    inOrderPrint(_root, someStream);
    return someStream;
}







