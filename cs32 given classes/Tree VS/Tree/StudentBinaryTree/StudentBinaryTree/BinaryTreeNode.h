#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <iostream>
#include <cstddef>

namespace cs32 {

template <typename Type>
class BinaryTreeNode {
public:
	BinaryTreeNode( const Type& theElement = Type(),
			 	    BinaryTreeNode * theLeftSide = nullptr, 
					BinaryTreeNode * theRightSide = nullptr);
	BinaryTreeNode * duplicate() const;

	static int size( BinaryTreeNode * t );
	static int height( BinaryTreeNode * t );

	// no references to a BinaryTreeNode are returned
	// publicly by either BinaryTree or BinaryTreeIterator
	// these methods are only called by BinaryTree and
	// BinaryTreeIterator
	const Type& getElement() const;
	BinaryTreeNode* getLeftSide() const;
	BinaryTreeNode* getRightSide() const;
	void setLeftSide( BinaryTreeNode* node );
	void setRightSide( BinaryTreeNode* node );

private:
	Type element;
	BinaryTreeNode* rightSide;
	BinaryTreeNode* leftSide;
};

}
#endif
