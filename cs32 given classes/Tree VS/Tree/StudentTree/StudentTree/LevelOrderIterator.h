#ifndef LEVELORDERITERATOR_H
#define LEVELORDERITERATOR_H
#include <iostream>
#include "Tree.h"
#include "TreeIterator.h"
#include "Queue.h"

namespace cs32 {

template <typename Type>
class LevelOrderIterator : public TreeIterator<Type> {
public:
	LevelOrderIterator( const Tree<Type>& theTree );
	virtual ~LevelOrderIterator();

	void advance();
	void first();
	
protected:
	Queue<const TreeNode<Type> *> q;
};

}

#endif
