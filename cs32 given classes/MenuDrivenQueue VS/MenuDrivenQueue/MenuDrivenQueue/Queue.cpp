#include "Queue.h"

namespace cs32 {


Queue::Queue() {
	frontNode = nullptr;
	backNode = nullptr;
}


Queue::Queue( const Queue& rhs ) {
	frontNode = nullptr;
	backNode = nullptr;
	*this = rhs;
}


Queue::~Queue() {
	makeEmpty();
	// when empty, frontNode and backNode will already be null
}


bool Queue::isEmpty() const {
	return( (frontNode == nullptr) );
}


void Queue::makeEmpty() {
	while (!isEmpty()) {
		dequeue();
	}
}


void Queue::enqueue( const std::string& data ) {
	QueueNode * newNode = new QueueNode( data );
	if (isEmpty()) {
		frontNode = newNode;
		backNode = newNode;
	}
	else {
		backNode->setNext( newNode );
		backNode = backNode->getNext();
	}
}


std::string Queue::dequeue() {
	std::string frontData = getFront();

	QueueNode * oldFront = frontNode;
	frontNode = frontNode->getNext();
	delete oldFront;
	return( frontData );
}


std::string Queue::getFront() const {
	if (isEmpty()) {
		throw EmptyQueue();
	}
	return( frontNode->getElement() );
}

// Deep copy of a Queue
const Queue& Queue::operator =( const Queue& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		QueueNode * rhsFrontNode = rhs.frontNode;
		while( rhsFrontNode != nullptr) {
			enqueue( rhsFrontNode->getElement() );
			rhsFrontNode = rhsFrontNode->getNext();
		}
	}
	return( *this );
}

std::string Queue::printQueue( ) {
    std::string s;
	if (isEmpty()) {
		s = "Empty Queue";
	}
	else {
		s = "FRONT: ";
		QueueNode * node = frontNode;
		while( node != nullptr) {
			s += node->getElement();
			s += " ";
			node = node->getNext();
		}
		s += ":BACK";
	}
	return( s );
}
	
}

