#ifndef BSTITERATOR_H
#define BSTITERATOR_H
#include <iostream>
#include "BSTNode.h"
#include "BST.h"
#include "BadIterator.h"

namespace cs32 {

template <typename Type>
class BSTIterator {
public:
	BSTIterator( const BST<Type>& theTree );
	virtual ~BSTIterator();

	bool isValid() const;
	virtual void advance() = 0;
	virtual void first() = 0;
	const Type& retrieve() const;
	
protected:
	const BSTNode<Type> * current;
	const BSTNode<Type> * root;

};

}
#endif
