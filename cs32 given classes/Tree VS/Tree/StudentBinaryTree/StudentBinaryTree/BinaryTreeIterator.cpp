#ifndef BINARYTREEITERATOR_CPP
#define BINARYTREEITERATOR_CPP

#include "BinaryTreeIterator.h"

namespace cs32 {

template <typename Type>
BinaryTreeIterator<Type>::BinaryTreeIterator( const BinaryTree<Type> & theTree ) : current( nullptr ), root( theTree.getRoot() )  {
//	all assignments performed thru code above
}

template <typename Type>
BinaryTreeIterator<Type>::~BinaryTreeIterator() {

}

template <typename Type>
bool BinaryTreeIterator<Type>::isValid( ) const {
	return( (current != nullptr) );
}


template <typename Type>
const Type& BinaryTreeIterator<Type>::retrieve( ) const {
	if (!(isValid())) throw BadIterator();
	return( current->getElement() );
}

}

#endif
