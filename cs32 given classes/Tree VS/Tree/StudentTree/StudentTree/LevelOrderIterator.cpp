#ifndef LEVELORDERITERATOR_CPP
#define LEVELORDERITERATOR_CPP

#include <iostream>
#include <cstddef>
#include "TreeIterator.h"
#include "LevelOrderIterator.h"
#include "Queue.h"

namespace cs32 {

template <typename Type>
LevelOrderIterator<Type>::LevelOrderIterator( const Tree<Type> & theTree ) : TreeIterator<Type>( theTree ) {
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
		if (this->current->getNextSibling() != nullptr)
			q.enqueue( this->current->getNextSibling() );
		if (this->current->getFirstChild() != nullptr) 
			q.enqueue( this->current->getFirstChild() );
	}
}

}

#endif
