#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

namespace cs32 {

template <typename Type>
Queue<Type>::Queue() {
	frontNode = nullptr;
	backNode = nullptr;
}

template <typename Type>
Queue<Type>::Queue( const Queue<Type>& rhs ) {
	frontNode = nullptr;
	backNode = nullptr;
	*this = rhs;
}

template <typename Type>
Queue<Type>::~Queue() {
	makeEmpty();
	// when empty, frontNode and backNode will already be null
}

template <typename Type>
bool Queue<Type>::isEmpty() const {
	return( (frontNode == nullptr) );
}

template <typename Type>
void Queue<Type>::makeEmpty() {
	while (!isEmpty()) {
		dequeue();
	}
}

template <typename Type>
void Queue<Type>::enqueue( const Type& data ) {
	QueueNode<Type>* newNode = new QueueNode<Type>( data );
	if (isEmpty()) {
		frontNode = newNode;
		backNode = newNode;
	}
	else {
		backNode->setNext( newNode );
		backNode = backNode->getNext();
	}
}

template <typename Type>
const Type Queue<Type>::dequeue() {
	Type frontData = getFront();

	QueueNode<Type> * oldFront = frontNode;
	frontNode = frontNode->getNext();
	delete oldFront;
	return( frontData );
}

template <typename Type>
const Type& Queue<Type>::getFront() const {
	if (isEmpty()) {
		throw EmptyQueue();
	}
	return( frontNode->getElement() );
}

// Deep copy of linked Queue
template <typename Type>
const Queue<Type>& Queue<Type>::operator =( const Queue<Type>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		QueueNode<Type> * rhsFrontNode = rhs.frontNode;
		while( rhsFrontNode != nullptr) {
			enqueue( rhsFrontNode->getElement() );
			rhsFrontNode = rhsFrontNode->getNext();
		}
	}
	return( *this );
}

template <typename Type>
std::ostream& Queue<Type>::printQueue( std::ostream& outs ) {
	if (isEmpty()) {
		outs << "Empty Queue";
	}
	else {
		QueueNode<Type> * node = frontNode;
		while( node != nullptr) {
			outs << node->getElement();
			outs << " ";
			node = node->getNext();
		}
	}
	return( outs );
}
	
}
#endif
