#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "BinaryTree.h"

namespace cs32 {

template <typename Type>
BinaryTree<Type>::BinaryTree() {
	root = nullptr;
}

template <typename Type>
BinaryTreeNode<Type> * BinaryTree<Type>::getRoot() const {
	return( root );
}

template <typename Type>
BinaryTree<Type>::BinaryTree( const BinaryTree<Type>& rhs ) {
	root = nullptr;
	*this = rhs;
}

template <typename Type>
BinaryTree<Type>::BinaryTree( const Type& rootElement ) {
	root = new BinaryTreeNode<Type>( rootElement );
}

template <typename Type>
BinaryTree<Type>::~BinaryTree() {
	makeEmpty();
}

template <typename Type>
bool BinaryTree<Type>::isEmpty() const {
	return( root == nullptr );
}

template <typename Type>
void BinaryTree<Type>::makeEmpty() {
	makeEmpty( root );
}

template <typename Type>
void BinaryTree<Type>::makeEmpty( NodePtr & node ) {
	if (node != nullptr) {
		NodePtr r = node->getRightSide();
		NodePtr l = node->getLeftSide();

		if (r != nullptr)
			makeEmpty( r );
		if (l != nullptr)
			makeEmpty( l );
		delete node;
		node = nullptr;
	}
}

template <typename Type>
int BinaryTree<Type>::size() const {
	return( BinaryTreeNode<Type>::size( root ) );
}

template <typename Type>
int BinaryTree<Type>::height() const {
	return( BinaryTreeNode<Type>::height( root ) );
}

template <typename Type>
void BinaryTree<Type>::setRightSide( BinaryTree& theRightSide ) {
	if (theRightSide.root == nullptr)
		throw( InvalidTreeArgument() );
	BinaryTreeNode<Type> *child = new BinaryTreeNode<Type>( theRightSide.root->getElement(),
        theRightSide.root->getLeftSide(),
        theRightSide.root->getRightSide() );
	root->setRightSide( child );
	if (child != theRightSide.root)
		theRightSide.root = nullptr;
}

template <typename Type>
void BinaryTree<Type>::setLeftSide( BinaryTree& theLeftSide ) {
	if (theLeftSide.root == nullptr) 
		throw( InvalidTreeArgument() );
	BinaryTreeNode<Type> *child = new BinaryTreeNode<Type>( theLeftSide.root->getElement(),
        theLeftSide.root->getLeftSide(),
        theLeftSide.root->getRightSide() );
	root->setLeftSide( child );
	if (child != theLeftSide.root)
		theLeftSide.root = nullptr;
}

template <typename Type>
void BinaryTree<Type>::merge( const Type& rootElement,
 								BinaryTree & left,
								BinaryTree & right ) {
	if ( left.root == right.root && left.root != nullptr ) {
		std::cerr << "Cannot merge a tree with itself" << std::endl;
		throw( InvalidTreeArgument() );
	}
	else {
		NodePtr oldRoot = root;
		root = new BinaryTreeNode<Type>( rootElement,
                                        left.root,
                                        right.root );
		if (this != &left && this != &right) 
			makeEmpty( oldRoot );
		if (this != &left) 
			left.root = nullptr;
		if (this != &right)
			right.root = nullptr;
	}
}

// Deep copy of tree
template <typename Type>
const BinaryTree<Type>& BinaryTree<Type>::operator =( const BinaryTree<Type>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (rhs.root != nullptr) 
			root = rhs.root->duplicate();
	}
	return( *this );
}

template <typename Type>
void BinaryTree<Type>::printTree( std::ostream& out ) const {
	if (root == nullptr) {
		out << "nullptr" << std::endl;
	}
	else {
		printTree( root, out );
		out << std::endl;
	}
}

template <typename Type>
void BinaryTree<Type>::printTree( NodePtr subtree, std::ostream & out ) const {
	if (subtree == nullptr) {
		out << "nullptr";
	}
	else {
		out << subtree->getElement();
		out << " ";
		printTree( subtree->getLeftSide(), out );
		out << " ";
		printTree( subtree->getRightSide(), out );
		out << " ";
	}
}

}
#endif
