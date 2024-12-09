#ifndef BSTITERATOR_CPP
#define BSTITERATOR_CPP

#include "BSTIterator.h"

namespace cs32 {

template <typename Type>
BSTIterator<Type>::BSTIterator( const BST<Type> & theTree ) : current( nullptr ), root( theTree.getRoot() ) {
//	all assignments performed above
}

template <typename Type>
BSTIterator<Type>::~BSTIterator() {

}

template <typename Type>
bool BSTIterator<Type>::isValid( ) const {
	return( (current != nullptr) );
}


template <typename Type>
const Type& BSTIterator<Type>::retrieve( ) const {
	if (!(isValid())) throw BadIterator();
	return( current->getElement() );
}

}
#endif
