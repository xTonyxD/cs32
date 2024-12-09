#ifndef TREEITERATOR_CPP
#define TREEITERATOR_CPP

#include <iostream>
#include <cstddef>
#include "TreeIterator.h"

namespace cs32 {

template <typename Type>
TreeIterator<Type>::TreeIterator( const Tree<Type> & theTree ) : current( nullptr ), root( theTree.getRoot() ) {
//	all assignments performed above
}

template <typename Type>
TreeIterator<Type>::~TreeIterator() {

}

template <typename Type>
bool TreeIterator<Type>::isValid( ) const {
	return( (current != nullptr) );
}


template <typename Type>
const Type& TreeIterator<Type>::retrieve( ) const {
	if (!(isValid())) throw BadIterator();
	return( current->getElement() );
}

}

#endif
