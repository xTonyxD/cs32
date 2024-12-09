#ifndef LEVELORDERITERATOR_CPP
#define LEVELORDERITERATOR_CPP

#include <iostream>
#include <cstddef>
#include "BSTIterator.h"
#include "LevelOrderIterator.h"
#include "Queue.h"

namespace cs32 {

template <typename Type>
LevelOrderIterator<Type>::LevelOrderIterator( const BST<Type> & theTree ) : BSTIterator<Type>( theTree ) {
	q.enqueue( this->root );
}

template <typename Type>
LevelOrderIterator<Type>::~LevelOrderIterator() {

}

template <typename Type>
void LevelOrderIterator<Type>::first( ) {
	q.makeEmpty();
	if (this->root != nullptr) {
		q.enqueue( this->root );
		advance();
	}
}


template <typename Type>
void LevelOrderIterator<Type>::advance( ) {
	if (q.isEmpty()) {
		if (this->current == nullptr)
			throw BadIterator();
		this->current = nullptr;
	}
	else {
		this->current = q.dequeue();
		if (this->current->getLeftSide() != nullptr)
			q.enqueue( this->current->getLeftSide() );
		if (this->current->getRightSide() != nullptr) 
			q.enqueue( this->current->getRightSide() );
	}
}

}
#endif
