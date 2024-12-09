#ifndef TREE_CPP 
#define TREE_CPP

#include <iostream>
#include <cstddef>
#include "Tree.h"
#include "TreeNode.h"
#include "InvalidTreeArgument.h"

namespace cs32 {

template <typename Type>
Tree<Type>::Tree() {
	root = nullptr;
}

template <typename Type>
Tree<Type>::Tree( const Tree<Type>& rhs ) {
	root = nullptr;
	*this = rhs;
}

template <typename Type>
Tree<Type>::Tree( const Type& rootElement ) {
	root = new TreeNode<Type>( rootElement );
}

template <typename Type>
Tree<Type>::~Tree() {
	makeEmpty();
}

template <typename Type>
const Type & Tree<Type>::getElement() const {
	return( root->getElement() );
}

template <typename Type>
bool Tree<Type>::isEmpty() const {
	return( root == nullptr );
}

template <typename Type>
void Tree<Type>::makeEmpty() {
	makeEmpty( root );
}

template <typename Type>
TreeNode<Type> * Tree<Type>::getFirstChild( ) const {
	return( root->getFirstChild() );
}

template <typename Type>
TreeNode<Type> * Tree<Type>::getNextSibling( ) const {
	return( root->getNextSibling() );
}

template <typename Type>
TreeNode<Type> * Tree<Type>::getRoot( ) const {
	return( root );
}

template <typename Type>
void Tree<Type>::makeEmpty( NodePtr & node ) {
	if (node != nullptr) {
		NodePtr fc = node->getFirstChild();
		NodePtr ns = node->getNextSibling();

		if (fc != nullptr)
			makeEmpty( fc );
		if (ns != nullptr)
			makeEmpty( ns );
		delete node;
		node = nullptr;
	}
}

template <typename Type>
int Tree<Type>::size() const {
	return( TreeNode<Type>::size( root ) );
}

template <typename Type>
int Tree<Type>::height() const {
	return( TreeNode<Type>::height( root ) );
}

template <typename Type>
void Tree<Type>::setFirstChild( Tree& theFirstChild ) {
	if (theFirstChild.root == nullptr)
		throw( InvalidTreeArgument() );
	TreeNode<Type> *child = new TreeNode<Type>( theFirstChild.root->getElement(),
													theFirstChild.root->getFirstChild(),
													theFirstChild.root->getNextSibling() );
	root->setFirstChild( child );
	if (child != theFirstChild.root)
		theFirstChild.root = nullptr;
}

template <typename Type>
void Tree<Type>::setNextSibling( Tree& theNextSibling ) {
	if (theNextSibling.root == nullptr) 
		throw( InvalidTreeArgument() );
	TreeNode<Type> *child = new TreeNode<Type>( theNextSibling.root->getElement(),
													theNextSibling.root->getFirstChild(),
													theNextSibling.root->getNextSibling() );

	root->setNextSibling( child );
	if (child != theNextSibling.root)
		theNextSibling.root = nullptr;
}

template <typename Type>
void Tree<Type>::merge( const Type& rootElement,
 						  Tree & firstChild,
						  Tree & nextSibling ) {
	if ( firstChild.root == nextSibling.root && firstChild.root != nullptr ) {
		std::cerr << "Cannot merge a tree with itself" << std::endl;
		throw( InvalidTreeArgument() );
	}
	else {
		NodePtr oldRoot = root;
		root = new TreeNode<Type>( rootElement,
									 firstChild.root,
									 nextSibling.root );
		if (this != &firstChild && this != &nextSibling) 
			makeEmpty( oldRoot );
		if (this != &firstChild) 
			firstChild.root = nullptr;
		if (this != &nextSibling)
			nextSibling.root = nullptr;
	}
}

// Deep copy of tree
template <typename Type>
const Tree<Type>& Tree<Type>::operator =( const Tree<Type>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (rhs.root != nullptr) 
			root = rhs.root->duplicate();
	}
	return( *this );
}

template <typename Type>
const Type& Tree<Type>::find( const Type& item ) const  {
	TreeNode<Type>* node = find( item, root );
	if (node == nullptr)
		throw( ValueNotFound() );
	return( node->getElement() );
}

template <typename Type>
TreeNode<Type>* Tree<Type>::find( const Type& item, TreeNode<Type>* node ) const {
	TreeNode<Type>* match = nullptr;
	if (node != nullptr && node->getElement() == item) {
		match = node;
	}
	if (node != nullptr && match == nullptr && node->getFirstChild() != nullptr) {
		match = find( item, node->getFirstChild() );
	}
	if (node != nullptr && match == nullptr && node->getNextSibling() != nullptr) {
		match = find( item, node->getNextSibling() );
	}
	return( match );
}

template <typename Type>
void Tree<Type>::printTree( std::ostream & outs ) const {
	if (isEmpty())
		outs << "Empty Tree";
	else {
		TreeNode<Type> * node = getRoot();
		node->printTreeNode( outs );
	}
	outs << std::endl;
}

}

#endif
