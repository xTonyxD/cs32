#ifndef TREEITERATOR_H
#define TREEITERATOR_H
#include <iostream>
#include "TreeNode.h"
#include "Tree.h"
#include "BadIterator.h"

namespace cs32 {

template <typename Type>
class TreeIterator {
public:
	TreeIterator( const Tree<Type>& theTree );
	virtual ~TreeIterator();

	bool isValid() const;
	virtual void advance() = 0;
	virtual void first() = 0;
	const Type& retrieve() const;
	
protected:
	const TreeNode<Type> * current;
	const TreeNode<Type> * root;

};

}
#endif
