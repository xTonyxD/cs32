#ifndef HASHTABLENODE_CPP
#define HASHTABLENODE_CPP
#include <iostream>
#include <string>
#include "HashtableNode.h"
#include "InvalidNodeState.h"

namespace cs32 {

template <typename Type>
HashtableNode<Type>::HashtableNode( const Type& v,
							  NodeState s ) {
	value = v;
	state = s;
}

template <typename Type>
bool HashtableNode<Type>::isActive() const {
	return( state == ACTIVE );
}

template <typename Type>
bool HashtableNode<Type>::isEmpty() const {
	return( state == EMPTY );
}

template <typename Type>
bool HashtableNode<Type>::isDeleted() const {
	return( state == DELETED );
}

template <typename Type>
bool HashtableNode<Type>::isEmptyOrDeleted() const {
	return( state == EMPTY || state == DELETED );
}

template <typename Type>
bool HashtableNode<Type>::isActiveOrDeleted() const {
	return( state == ACTIVE || state == DELETED );
}

template <typename Type>
void HashtableNode<Type>::deleteNode() {
	if (isActive()) {
		state = DELETED;
	}
	else {
		throw InvalidNodeState();
	}
}

template <typename Type>
void HashtableNode<Type>::setValue( const Type& v ) {
	if (isEmpty() || isDeleted()) {
		value = v;
		state = ACTIVE;
	}
}

template <typename Type>
Type HashtableNode<Type>::getValue() {
	Type result;
	if (isActive()) {
		result = value;
	}
	else {
		throw InvalidNodeState();
	}	
	return( result );
}

template <typename Type>
void HashtableNode<Type>::printHashTableNode( std::ostream& outs ) {
	if (isEmpty()) {
		outs << " empty ";
	}
	else if (isDeleted()) {
		outs << " deleted ";
	}
	else {
		outs << " " << value << " ";
	}
}

}

#endif
