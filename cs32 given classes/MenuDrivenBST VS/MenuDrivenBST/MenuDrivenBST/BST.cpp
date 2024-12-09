#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

#include <iostream>

namespace cs32 {

template <typename Type>
BST<Type>::BST() {
	root = nullptr;
}

template <typename Type>
BST<Type>::BST( const BST<Type>& rhs ) {
	root = nullptr;
	*this = rhs;
}

template <typename Type>
BST<Type>::BST( const Type& rootElement ) {
	root = new BSTNode<Type>( rootElement );
}

template <typename Type>
BST<Type>::~BST() {
	makeEmpty();
}

template <typename Type>
bool BST<Type>::isEmpty() const {
	return( root == nullptr );
}

template <typename Type>
void BST<Type>::makeEmpty() {
	makeEmpty( root );
}

template <typename Type>
void BST<Type>::makeEmpty( BSTNode<Type> * & node ) {
	if (node != nullptr) {
		BSTNode< Type > * l = node->getLeftSide();
        BSTNode< Type > * r = node->getRightSide();
		makeEmpty( l );
		makeEmpty( r );
		delete node;
		node = nullptr;
	}
}

template <typename Type>
int BST<Type>::size() const {
	return( BSTNode<Type>::size( root ) );
}

template <typename Type>
int BST<Type>::height() const {
	return( BSTNode<Type>::height( root ) );
}

template <typename Type>
const Type& BST<Type>::findMin() const  {
	if (root == nullptr)
		throw InvalidTreeArgument();
	return( findMin( root ) );
}

template <typename Type>
const Type& BST<Type>::findMax() const  {
	if (root == nullptr)
		throw InvalidTreeArgument();
	return( findMax( root ) );
}

template <typename Type>
const Type& BST<Type>::findMin( BSTNode<Type> * node ) const {
	while( node->getLeftSide() != nullptr ) {
		node = node->getLeftSide();
	}
	return( node->getElement() );
}

template <typename Type>
const Type& BST<Type>::findMax( BSTNode<Type> * node ) const {
	while( node->getRightSide() != nullptr ) {
		node = node->getRightSide();
	}
	return( node->getElement() );
}

template <typename Type>
const Type& BST<Type>::find( const Type& x ) const  {
	return( find( x, root ) );
}

template <typename Type>
const Type& BST<Type>::find( const Type& x, BSTNode<Type> * node ) const  {
	if (node == nullptr)
		throw InvalidTreeArgument();
	if (node->getElement() < x) {
 		return( find( x, node->getRightSide() ) );
	}
	if (node->getElement() > x) {
 		return( find( x, node->getLeftSide() ) );
	}
	return( node->getElement() );
}

template <typename Type>
void BST<Type>::insert( const Type& x )  {
	insert( x, root );
}

template <typename Type>
void BST<Type>::insert( const Type& x, BSTNode<Type> * & node )  {
    using namespace std;


	if (node == nullptr) {
		node = new BSTNode<Type>( x, nullptr, nullptr );
	}
	else if (x < node->getElement()) {
        BSTNode< Type > * other = node->getLeftSide();
		insert( x, other );
        node->setLeftSide( other );
	}
	else if (x > node->getElement()) {
        BSTNode< Type > * other = node->getRightSide();
		insert( x, other );
        node->setRightSide( other );
	}
	else
		throw InvalidTreeArgument();
}

template <typename Type>
void BST<Type>::removeMin()  {
	removeMin( root );
}

template <typename Type>
void BST<Type>::removeMin( BSTNode<Type> * & node )  {
	if (node == nullptr) {
		throw InvalidTreeArgument();
	}
	else if (node->getLeftSide() != nullptr) {
        BSTNode< Type > * other = node->getLeftSide();
		removeMin( other );
        node->setLeftSide( other );
	}
	else {
        BSTNode< Type > * temp = node;
		node = node->getRightSide();
		delete temp;
	}
}

template <typename Type>
void BST<Type>::removeMax() {
	removeMax(root);
}

template <typename Type>
void BST<Type>::removeMax(BSTNode<Type>*& node) {
	if (node == nullptr) {
		throw InvalidTreeArgument();
	}
	else if (node->getRightSide() != nullptr) {
		removeMax( node->rightSide );
	}
	else {
		BSTNode< Type >* temp = node;
		node = node->getLeftSide();
		delete temp;
	}
}
template <typename Type>
void BST<Type>::remove( const Type& x )  {
	remove( x, root ); 
}

template <typename Type>
void BST<Type>::remove( const Type& x, BSTNode<Type> * & node )  {
	if (node == nullptr) 
		throw InvalidTreeArgument();
	else if (x < node->getElement())
    {
        BSTNode< Type > * other = node->getLeftSide();
        remove( x, other );
        node->setLeftSide( other );
    }
	else if (x > node->getElement())
    {
        BSTNode< Type > * other = node->getRightSide();
        remove( x, other );
        node->setRightSide( other );
    }
	// on the matching node
	else if (node->getLeftSide() != nullptr && node->getRightSide() != nullptr)
    {
		// 2 children
		node->setElement( findMax( node->getLeftSide() ) );
		removeMax(node->leftSide);
	}
	else {
		// one or no children
        BSTNode< Type > * temp = node;
		if (node->getLeftSide() != nullptr) {
			node = node->getLeftSide();
		}
		else {
			node = node->getRightSide();
		}
		delete temp;
	}
}

// Deep copy of tree
template <typename Type>
const BST<Type>& BST<Type>::operator =( const BST<Type>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (rhs.root != nullptr) 
			root = rhs.root->duplicate();
	}
	return( *this );
}
	
template <typename Type>
std::ostream& BST<Type>::printBST( std::ostream& outs ) const {
	if (isEmpty()) 
		outs << "Empty BST";
	else
		root->printBSTNode( outs );
	outs << std::endl;
	return( outs );
}

template <typename Type>
BSTNode<Type>* BST<Type>::getRoot() const {
	return( root );
}

}
#endif
