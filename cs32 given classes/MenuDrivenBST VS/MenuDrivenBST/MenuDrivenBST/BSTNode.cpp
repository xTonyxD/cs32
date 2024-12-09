#ifndef BSTNODE_CPP
#define BSTNODE_CPP

#include "BSTNode.h"

namespace cs32 {

template <typename Type>
BSTNode<Type>::BSTNode( const Type& theElement,
                       BSTNode<Type> * theLeftSide,
                       BSTNode<Type> * theRightSide,
                       int theSize) {
    element = theElement;
    rightSide = theRightSide;
    leftSide = theLeftSide;
    sz = theSize;
}

template <typename Type>
int BSTNode<Type>::size( BSTNode<Type> * node ) {
    if (node == nullptr )
        return( 0 );
    else
        return( 1 + size( node->rightSide ) + size( node->leftSide ) );
}

template <typename Type>
int BSTNode<Type>::height( BSTNode<Type> * node ) {
    if (node == nullptr )
        return( -1 );
    else
        return( 1 + max( height( node->leftSide ), height( node->rightSide ) ) );
}

template <typename Type>
BSTNode<Type> * BSTNode<Type>::duplicate( ) const {
    BSTNode<Type> * newNode = new BSTNode<Type>( element );
    if (rightSide != nullptr) {
        newNode->rightSide = rightSide->duplicate();
    }
    if (leftSide != nullptr) {
        newNode->leftSide = leftSide->duplicate();
    }
    newNode->sz = sz;
    return( newNode );
}

template <typename Type>
std::ostream& BSTNode<Type>::printBSTNode( std::ostream& outs ) const {
    Type o = element;
    outs << o << " ";
    if (leftSide != nullptr)
        leftSide->printBSTNode( outs );
    else
        outs << "LSNULLPTR ";
    if (rightSide != nullptr)
        rightSide->printBSTNode( outs );
    else
        outs << "RSNULLPTR ";
    outs << std::endl;
    return( outs );
}

template <typename Type>
int BSTNode<Type>::max( int a, int b ) {
    int result = a;
    if (b > a)
        result = b;
    return( result );
}

template <typename Type>
const Type& BSTNode<Type>::getElement() const {
    return( element );
}

template <typename Type>
void BSTNode<Type>::setElement( Type t )
{
    element = t;
}

template <typename Type>
BSTNode<Type>* BSTNode<Type>::getLeftSide() const {
    return( leftSide );
}

template <typename Type>
BSTNode<Type>* BSTNode<Type>::getRightSide() const {
    return( rightSide );
}

template <typename Type>
void BSTNode<Type>::setLeftSide( BSTNode<Type> * node )
{
    leftSide = node;
}

template <typename Type>
void BSTNode<Type>::setRightSide( BSTNode<Type> * node )
{
    rightSide = node;
}

}

#endif
