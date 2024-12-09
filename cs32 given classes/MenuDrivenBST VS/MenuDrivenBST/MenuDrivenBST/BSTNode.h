#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

namespace cs32 {

template <typename Type>
class BST;

template <typename Type>
class BSTNode {
public:
	BSTNode( const Type& theElement = Type(),
			 BSTNode * theLeftSide = nullptr,
			 BSTNode * theRightSide = nullptr,
			 int theSize = 1);
	BSTNode * duplicate() const;

	static int size( BSTNode * t );
	static int height( BSTNode * t );

	// no references to a BSTNode are returned
	// publicly by either BST or BSTIterators
	// these methods are only called by BST and
	// BSTIterators
	const Type& getElement() const;
    void setElement( Type t );
	BSTNode<Type> * getLeftSide() const;
	BSTNode<Type> * getRightSide() const;
    void setLeftSide( BSTNode<Type> * node );
    void setRightSide( BSTNode<Type> * node );

	std::ostream& printBSTNode ( std::ostream& outs ) const;
private:
	Type   element;
	BSTNode* rightSide;
	BSTNode* leftSide;
	int      sz;

	static int max( int a, int b );

	friend class BST<Type>;
};

}
#endif
