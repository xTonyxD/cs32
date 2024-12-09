#include "StackNode.h"

namespace cs32 {

StackNode::StackNode( const std::string& theElement,
                      StackNode * node ) {
	element = theElement;
	next = node;
}


const std::string& StackNode::getElement() const {
	return( element );
}

StackNode * StackNode::getNext() const {
	return( next );
}

void StackNode::setNext( StackNode * node ) {
	next = node;
}

}


