#ifndef BINARYTREENODE_CPP
#define BINARYTREENODE_CPP

#include "BinaryTreeNode.h"

namespace cs32 {

template <typename Type>
BinaryTreeNode<Type>::BinaryTreeNode( const Type& theElement,
                                        BinaryTreeNode<Type> * theLeftSide,
                                        BinaryTreeNode<Type> * theRightSide ) {
	element = theElement;
	rightSide = theRightSide;
	leftSide = theLeftSide;
}

template <typename Type>
int BinaryTreeNode<Type>::size( BinaryTreeNode<Type> * node ) {
	if (node == nullptr ) 
		return( 0 );
	else
		return( 1 + size( node->rightSide ) + size( node->leftSide ) );
}

template <typename Type>
int BinaryTreeNode<Type>::height( BinaryTreeNode<Type> * node ) {
	if (node == nullptr ) 
		return( -1 );
	else
		return( 1 + std::max( height( node->leftSide ), height( node->rightSide ) ) );
}

template <typename Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type>::duplicate( ) const {
	BinaryTreeNode<Type> * newNode = new BinaryTreeNode<Type>( element );
	if (rightSide != nullptr) {
		newNode->rightSide = rightSide->duplicate();
	}
	if (leftSide != nullptr) {
		newNode->leftSide = leftSide->duplicate();
	}
	return( newNode );
}

template <typename Type>
const Type& BinaryTreeNode<Type>::getElement() const {
	return( element );
}

template <typename Type>
BinaryTreeNode<Type>* BinaryTreeNode<Type>::getLeftSide() const {
	return( leftSide );
}

template <typename Type>
BinaryTreeNode<Type>* BinaryTreeNode<Type>::getRightSide() const {
	return( rightSide );
}

template <typename Type>
void BinaryTreeNode<Type>::setLeftSide( BinaryTreeNode<Type>* node ) {
	leftSide = node;
}

template <typename Type>
void BinaryTreeNode<Type>::setRightSide( BinaryTreeNode<Type>* node ) {
	rightSide = node;
}

}
#endif
