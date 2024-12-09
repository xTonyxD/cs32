#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <cstddef>
#include "BinaryTreeNode.h"
#include "InvalidTreeArgument.h"

namespace cs32 {

template <typename Type>
class BinaryTreeIterator;

template <typename Type>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree( const Type& rootElement );
	BinaryTree( const BinaryTree& rhs );
	~BinaryTree();

	bool isEmpty() const;
	void makeEmpty();
	int size() const;
	int height() const;
	void merge( const Type& rootElement,
				BinaryTree& firstChild,
				BinaryTree& nextSibling );
	void setRightSide( BinaryTree& theRightSide );
	void setLeftSide( BinaryTree& theLeftSide );
	
	const BinaryTree& operator =( const BinaryTree& rhs );

	// this is tremendously bad form but I had to do it
	// to support the menu-based program
	BinaryTreeNode<Type> * getRoot() const;

	void printTree( std::ostream& out ) const;
private:
	typedef BinaryTreeNode<Type>* NodePtr;
	
	NodePtr root;
	void makeEmpty( NodePtr &t );

	void printTree( NodePtr subtree, std::ostream & out ) const;
};

}
#endif
