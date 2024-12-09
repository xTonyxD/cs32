#ifndef TREE_H
#define TREE_H
// Visual Studio .NET does not support declared exceptions...
#pragma warning( disable:4290 )
#include <iostream>
#include "TreeNode.h"
#include "ValueNotFound.h"

namespace cs32 {

template <typename Type>
class TreeIterator;

template <typename Type>
class Tree {
public:
	Tree();
	Tree( const Type& rootElement );
	Tree( const Tree& rhs );
	~Tree();

	bool isEmpty() const;
	void makeEmpty();
	int size() const;
	int height() const;
	void merge( const Type& rootElement,
				Tree& firstChild,
				Tree& nextSibling );
	void setFirstChild( Tree& theFirstChild );
	TreeNode<Type> * getFirstChild( ) const;
	void setNextSibling( Tree& theNextSibling ); 
	TreeNode<Type> * getNextSibling( ) const;
	const Type& find( const Type& item ) const ;
	
	const Tree& operator =( const Tree& rhs );
	void printTree( std::ostream & outs ) const;

	const Type & getElement() const;
	TreeNode<Type> * getRoot( ) const;
private: 
	typedef TreeNode<Type>* NodePtr;
	
	NodePtr root;
	void makeEmpty( NodePtr &t );
	TreeNode<Type>* find( const Type& item, TreeNode<Type>* node ) const;

};

}

#endif
