#ifndef BST_H
#define BST_H
// pragma for Visual Studio's lack of support for checked exceptions
#pragma warning( disable: 4290)
#include <iostream>
#include <cstddef>
#include "BSTNode.h"
#include "InvalidTreeArgument.h"

namespace cs32 {

template <typename Type>
class BSTIterator;

template <typename Type>
class BST {
public:
	BST();
	BST( const Type& rootElement );
	BST( const BST& rhs );
	~BST();

	bool isEmpty() const;
	void makeEmpty();
	int size() const;
	int height() const;
	const Type& find( const Type& x ) const ;
	const Type& findMin() const ;
	const Type& findMax() const ;
	void insert( const Type& x ) ;
	void remove( const Type& x ) ;
	void removeMin() ;
	void removeMax() ;

	const BST& operator =( const BST& rhs );
	std::ostream& printBST( std::ostream& outs ) const;

	BSTNode<Type>* getRoot() const;
private:
    BSTNode< Type > * root;
	void makeEmpty( BSTNode<Type> * &t );

	const Type& find( const Type& x, BSTNode<Type> * node ) const ;
	const Type& findMin( BSTNode<Type> * node ) const;
	const Type& findMax( BSTNode<Type> * node ) const;
	void insert( const Type& x, BSTNode<Type> * & node ) ;
	void remove( const Type& x, BSTNode<Type> * & node ) ;
	void removeMin( BSTNode<Type> * & node ) ;
	void removeMax(BSTNode<Type>*& node);
};

}
#endif
