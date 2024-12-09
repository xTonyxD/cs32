#ifndef BINARYHEAP_CPP
#define BINARYHEAP_CPP

#include "BinaryHeap.h"
#include "ItemNotFound.h"
#include "HeapOverflow.h"
#include "BadArgument.h"

namespace cs32 {

template <typename Type>
BinaryHeap<Type>::BinaryHeap( int initialSize ) {
	cellsOccupied = 0;
	size  = initialSize;
	// leave index 0 empty
	array = new Type[ initialSize + 1 ];
}

template <typename Type>
BinaryHeap<Type>::BinaryHeap( const BinaryHeap<Type>& rhs ) {
	cellsOccupied = rhs.cellsOccupied;
	size  = rhs.size;
	array = rhs.array;
	*this = rhs;
}

template <typename Type>
BinaryHeap<Type>::~BinaryHeap() {
	makeEmpty();
}

template <typename Type>
bool BinaryHeap<Type>::isEmpty() const {
	return( cellsOccupied == 0 );
}

template <typename Type>
void BinaryHeap<Type>::makeEmpty() {
	while (!isEmpty()) 
		deleteMin();
}

template <typename Type>
int BinaryHeap<Type>::occupied() const {
	return( cellsOccupied );
}

template <typename Type>
void BinaryHeap<Type>::buildHeap() {
	for (int i = cellsOccupied / 2; i > 0; i--)
		percolateDown( i );
}

template <typename Type>
void BinaryHeap<Type>::percolateDown( int index ) {
	int child;
	Type temp = array[ index ];

	while (index * 2 <= cellsOccupied) {
		child = index * 2;
		if (child != cellsOccupied &&
			array[ child+1 ] < array[ child ] )
			child++;
		if (array[ child ] < temp) 
			array[ index ] = array[ child ];
		else
			break;
		index = child;
	}

	array[ index ] = temp;
}

template <typename Type>
const Type& BinaryHeap<Type>::findMin() const {
	if (isEmpty()) 
		throw ItemNotFound();
	return( array[ 1 ] );
}

template <typename Type>
int  BinaryHeap<Type>::parentIndex( int index ) const {
	return( index / 2 );
}

template <typename Type>
Type BinaryHeap<Type>::parentValue( int index ) const {
	return( array[ parentIndex( index ) ] );
}

template <typename Type>
int BinaryHeap<Type>::insert( const Type& data ) {
	if (cellsOccupied + 1 == size)
		throw HeapOverflow();

	// percolate up, working your way from the back
	int hole = ++cellsOccupied;

	while (data < parentValue( hole )) {
		array[ hole ] = parentValue( hole );
		hole = parentIndex( hole );
	}

	array[ hole ] = data;
	return( hole );
}

template <typename Type>
Type BinaryHeap<Type>::deleteMin() {
	if (isEmpty())
		throw HeapOverflow();
	Type minItem = findMin();
	// clobber minimum element with the last value
	array[ 1 ] = array[ cellsOccupied ];
	// decrement cells occupied
	cellsOccupied--;
	// restore heap ordering
	percolateDown( 1 );
	
	return( minItem );
}

template <typename Type>
const BinaryHeap<Type>& BinaryHeap<Type>::operator =( const BinaryHeap<Type>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		for (int i = 1; i <= rhs.occupied(); ++i) {
			insert( rhs.array[ i ] );
		}
	}
	return( *this );
}

template <typename Type>
void BinaryHeap<Type>::printHeap( std::ostream& outs ) const {
	if (isEmpty()) 
		outs << "Empty Heap";
	else { 
		for (int i = 1; i <= cellsOccupied; ++i) {
			outs << i << ":" << array[i] << " ";
		}
	}
	outs << std::endl;
}

}
#endif
