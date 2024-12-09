#include "QueueNode.h"

namespace cs32 {

QueueNode::QueueNode( const std::string& theElement,
                    QueueNode * node ) {
	element = theElement;
	next = node;
}

const std::string& QueueNode::getElement() const {
	return( element );
}


QueueNode * QueueNode::getNext() const {
	return( next );
}


void QueueNode::setNext( QueueNode * node ) {
	next = node;
}

}


