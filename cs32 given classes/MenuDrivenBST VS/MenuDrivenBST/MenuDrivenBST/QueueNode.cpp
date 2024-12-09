#ifndef QUEUENODE_CPP
#define QUEUENODE_CPP

#include "QueueNode.h"

namespace cs32 {

template <typename Type>
QueueNode<Type>::QueueNode( const Type& theElement,
                            QueueNode<Type> * node ) {
	element = theElement;
	next = node;
}

template <typename Type>
const Type& QueueNode<Type>::getElement() const {
	return( element );
}

template <typename Type>
QueueNode<Type>* QueueNode<Type>::getNext() const {
	return( next );
}

template <typename Type>
void QueueNode<Type>::setNext( QueueNode<Type> * node ) {
	next = node;
}

}

#endif
