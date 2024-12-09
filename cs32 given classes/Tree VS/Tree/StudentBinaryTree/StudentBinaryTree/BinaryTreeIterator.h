#ifndef BINARYTREEITERATOR_H
#define BINARYTREEITERATOR_H
#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include "BadIterator.h"

namespace cs32 {

template <typename Type>
class BinaryTreeIterator {
public:
	BinaryTreeIterator( const BinaryTree<Type>& theTree );
	virtual ~BinaryTreeIterator();

	bool isValid() const;
	virtual void advance() = 0;
	virtual void first() = 0;
	const Type& retrieve() const;
	
//protected:
	const BinaryTreeNode<Type> * current;
	const BinaryTreeNode<Type> * root;

};

}
#endif
