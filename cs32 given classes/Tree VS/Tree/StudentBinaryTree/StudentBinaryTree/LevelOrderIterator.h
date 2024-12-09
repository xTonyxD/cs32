#ifndef LEVELORDERITERATOR_H
#define LEVELORDERITERATOR_H
#include <iostream>
#include <cstddef>
#include "BinaryTree.h"
#include "BinaryTreeIterator.h"
#include "Queue.h"

namespace cs32 {

template <typename Type>
class LevelOrderIterator : public BinaryTreeIterator<Type> {
public:
	LevelOrderIterator( const BinaryTree<Type>& theTree );
	virtual ~LevelOrderIterator();

	void advance();
	void first();
	
protected:
	Queue<const BinaryTreeNode<Type> *> q;
};

}
#endif
