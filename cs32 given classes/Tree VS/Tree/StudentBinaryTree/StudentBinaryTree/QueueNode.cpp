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

template <typename Type>
std::ostream& operator <<( std::ostream& outs, const QueueNode<Type> * node ) {
	if (node == nullptr) {
		outs << "Empty Queue";
	}
	else {
		QueueNode<Type> current = *node;
		// yucky loop, but I did not want to build a
		// constructor, destructor and equal operator
		// for a QueueNode
		while( true ) {
			Type o = current.element;
			outs << o << " ";
			if (current.next == nullptr)
				break;
			else
				current = *(current.next);
		}
	}
	outs << std::endl;
	return( outs );
}

}

#endif
