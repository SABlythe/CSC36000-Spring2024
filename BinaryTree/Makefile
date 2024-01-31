OPTS = -g -ansi -pedantic -Wall -std=c++20
CC = g++ -c $(OPTS)
LN = g++
OBJS = IntBinaryTree.o IntBinaryTreeNode.o test.o

bt: $(OBJS)
	$(LN) -o bt $(OBJS)

test.o: test.cpp IntBinaryTree.hpp IntBinaryTreeNode.hpp
	$(CC) test.cpp

IntBinaryTree.o: IntBinaryTree.cpp IntBinaryTree.hpp IntBinaryTreeNode.hpp
	$(CC) IntBinaryTree.cpp

IntBinaryTreeNode.o: IntBinaryTreeNode.cpp IntBinaryTreeNode.hpp
	$(CC) IntBinaryTreeNode.cpp

clean:
	/bin/rm -f $(OBJS) bt

