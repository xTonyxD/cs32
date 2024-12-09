#include "Stack.h"
#include <iostream>
using namespace std;

namespace cs32 {

Stack::Stack() {
	topNode = nullptr;
}


Stack::Stack( const Stack& rhs ) {
	topNode = nullptr;
	*this = rhs;
}


Stack::~Stack() {
	makeEmpty();
    delete topNode;
}

bool Stack::isEmpty() const {
	return( (topNode == nullptr) );
}

void Stack::makeEmpty() {
	while (!isEmpty()) {
		pop();
	}
}

void Stack::push( const std::string& data ) {
	StackNode * newNode = new StackNode( data, topNode );
	topNode = newNode;
}

void Stack::pop() {
	if (isEmpty()) {
		throw EmptyStack();
	}
	StackNode *oldTop = topNode;
	topNode = topNode->getNext();
	delete oldTop;
}

std::string Stack::top( ) const {
	if (isEmpty()) {
		throw EmptyStack();
	}
	StackNode node = * topNode;
	return( node.getElement() );
}

std::string Stack::topAndPop( ) {
	std::string o = top();
	pop();
	return( o );
}

// Deep copy of linked Stack
const Stack& Stack::operator =( const Stack& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (!(rhs.isEmpty())) {
			StackNode * rhsTopNode = rhs.topNode;
			StackNode * myTopNode = new StackNode( rhsTopNode->getElement() );
			topNode = myTopNode;

			rhsTopNode = rhsTopNode->getNext();
			while (rhsTopNode != nullptr) {
				myTopNode->setNext( new StackNode( rhsTopNode->getElement() ) );
				myTopNode = myTopNode->getNext();
				rhsTopNode = rhsTopNode->getNext();
			}
		}
	}
	return( *this );
}

std::string Stack::printStack( ) const {
    string s;
    if (isEmpty()) {
		s = "Empty Stack";
	}
	else {
		s = "TOP: ";
		StackNode * node = topNode;
		while (node != nullptr) {
			s += node->getElement();
			s += "\n     ";           /// for visual alignment
			node = node->getNext();
		}
        s += "nullptr";
	}
    return( s );
}

}

