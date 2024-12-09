#ifndef TREENODE_CPP
#define TREENODE_CPP

#include <iostream>
#include <cstddef>
#include "TreeNode.h"

namespace cs32 {

template <typename Type>
TreeNode<Type>::TreeNode( const Type& theElement,
								    TreeNode<Type> * theFirstChild,
									TreeNode<Type> * theNextSibling ) {
	element = theElement;
	firstChild = theFirstChild;
	nextSibling = theNextSibling;
}

template <typename Type>
int TreeNode<Type>::size( TreeNode<Type> * node ) {
	if (node == nullptr ) 
		return( 0 );
	else
		return( 1 + size( node->firstChild ) + size( node->nextSibling ) );
}

template <typename Type>
int TreeNode<Type>::height( TreeNode<Type> * node ) {
	if (node == nullptr ) 
		return( -1 );
	else
		return( std::max( height( node->firstChild ) + 1, height( node->nextSibling ) ) );
}

template <typename Type>
TreeNode<Type> * TreeNode<Type>::duplicate( ) const {
	TreeNode<Type> * newNode = new TreeNode<Type>( element );
	if (firstChild != nullptr) {
		newNode->firstChild = firstChild->duplicate();
	}
	if (nextSibling != nullptr) {
		newNode->nextSibling = nextSibling->duplicate();
	}
	return( newNode );
}

template <typename Type>
void TreeNode<Type>::printTreeNode( std::ostream & outs ) const {
	Type o = element;
	outs << o << " ";
	if (firstChild != nullptr) 
		firstChild->printTreeNode( outs );
	else
		outs << "FCnullptr ";
	if (nextSibling != nullptr)
		nextSibling->printTreeNode( outs );
	else
		outs << "NSnullptr ";
	outs << std::endl;
}

template <typename Type>
const Type& TreeNode<Type>::getElement() const {
	return( element );
}

template <typename Type>
TreeNode<Type>* TreeNode<Type>::getFirstChild() const {
	return( firstChild );
}

template <typename Type>
TreeNode<Type>* TreeNode<Type>::getNextSibling() const {
	return( nextSibling );
}

template <typename Type>
void TreeNode<Type>::setFirstChild( TreeNode<Type>* node ) {
	firstChild = node;
}

template <typename Type>
void TreeNode<Type>::setNextSibling( TreeNode<Type>* node ) {
	nextSibling = node;
}

}
#endif
