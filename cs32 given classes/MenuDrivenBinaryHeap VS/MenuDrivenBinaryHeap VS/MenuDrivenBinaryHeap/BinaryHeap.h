#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>

namespace cs32 {

template <typename Type>
class BinaryHeap {
public:
	BinaryHeap( int initialSize = 100 );
	BinaryHeap( const BinaryHeap& rhs );
	~BinaryHeap();

	bool isEmpty() const;
	void makeEmpty();
	int  occupied() const;

	const Type& findMin() const;

	int insert( const Type& data );
	Type deleteMin();

	const BinaryHeap& operator =( const BinaryHeap& rhs );
	void printHeap( std::ostream& outs ) const;
private:
	Type *  array;
	int       cellsOccupied;
	int		  size;

	void   buildHeap();
	void   percolateDown( int index );
	int    parentIndex( int index ) const;
	Type   parentValue( int index ) const;
};

}
#endif
