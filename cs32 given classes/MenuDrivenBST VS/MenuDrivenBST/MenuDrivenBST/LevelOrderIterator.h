#ifndef LEVELORDERITERATOR_H
#define LEVELORDERITERATOR_H
#include <iostream>
#include "BST.h"
#include "BSTIterator.h"
#include "Queue.h"

namespace cs32 {

template <typename Type>
class LevelOrderIterator : public BSTIterator<Type> {
public:
	LevelOrderIterator( const BST<Type>& theTree );
	virtual ~LevelOrderIterator();

	void advance();
	void first();
	
protected:
	Queue<const BSTNode< Type > *> q;
};

}
#endif
