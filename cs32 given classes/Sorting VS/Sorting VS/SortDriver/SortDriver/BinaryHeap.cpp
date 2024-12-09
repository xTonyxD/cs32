#ifndef BINARYHEAP_CPP
#define BINARYHEAP_CPP

#include <iostream>
#include <cstddef>
#include "BinaryHeap.h"
#include "ItemNotFound.h"
#include "HeapOverflow.h"
#include "BadArgument.h"


using namespace std;

namespace cs32
{

template <class Object>
BinaryHeap<Object>::BinaryHeap( int initialSize ) {
    cellsOccupied = 0;
    exchanges = 0;
    comparisons = 0;
    size  = initialSize;
    // leave index 0 empty
    array = new Object[ initialSize + 1 ];
}

template <class Object>
BinaryHeap<Object>::BinaryHeap(  const vector<Object> &v ) {
    exchanges = 0;
    comparisons = 0;
    // leave index 0 empty
    array = new Object[ v.size() + 1 ];
    for (int i = 0; i < v.size(); i++) 
        array[i + 1] = v[ i ];
    cellsOccupied = v.size();
    size = v.size();
    buildHeap();
}

template <class Object>
BinaryHeap<Object>::BinaryHeap( const Object data[], int dataSize ) {
    exchanges = 0;
    comparisons = 0;
    // leave index 0 empty
    array = new Object[ dataSize + 1 ];
    for (int i = 0; i < dataSize; i++) 
        array[i + 1] = data[ i ];
    cellsOccupied = dataSize;
    size = dataSize;
    buildHeap();
}

template <class Object>
BinaryHeap<Object>::BinaryHeap( const BinaryHeap<Object>& rhs ) {
    cellsOccupied = rhs.cellsOccupied;
    array = rhs.array;
    *this = rhs;
}

template <class Object>
BinaryHeap<Object>::~BinaryHeap() {
    delete [] array;
}

template <class Object>
bool BinaryHeap<Object>::isEmpty() const {
    return( cellsOccupied == 0 );
}

template <class Object>
void BinaryHeap<Object>::makeEmpty() {
    while (!isEmpty()) 
        deleteMin();
}

template <class Object>
int BinaryHeap<Object>::occupied() const {
    return( cellsOccupied );
}

template <class Object>
void BinaryHeap<Object>::buildHeap() {
    for (int i = cellsOccupied / 2; i > 0; i--)
        percolateDown( i );
}

template <class Object>
void BinaryHeap<Object>::percolateDown( int index ) {
    int child;
    Object temp = array[ index ];
    
    while (index * 2 <= cellsOccupied) {
        child = index * 2;
        if (child != cellsOccupied &&
            array[ child+1 ] < array[ child ] ) {
            comparisons++;
            child++;
        }
        if (array[ child ] < temp) {
            array[ index ] = array[ child ];
            comparisons++;
            exchanges++;
        }
        else
            break;
        index = child;
    }
    
    array[ index ] = temp;
    exchanges++;
}

template <class Object>
const Object& BinaryHeap<Object>::findMin() const {
    if (isEmpty()) 
        throw ItemNotFound();
    return( array[ 1 ] );
}

template <class Object>
int  BinaryHeap<Object>::parentIndex( int index ) const {
    return( index / 2 );
}

template <class Object>
Object BinaryHeap<Object>::parentValue( int index ) const {
    return( array[ parentIndex( index ) ] );
}

template <class Object>
int BinaryHeap<Object>::insert( const Object& data ) {
    if (cellsOccupied + 1 == size)
        throw HeapOverflow();
    
    // percolate up, working your way from the back
    int hole = ++cellsOccupied;
    
    while (data < parentValue( hole )) {
        array[ hole ] = parentValue( hole );
        hole = parentIndex( hole );
        exchanges++;
        comparisons++;
    }
    
    array[ hole ] = data;
    exchanges++;
    return( hole );
}

template <class Object>
void BinaryHeap<Object>::decreaseValue( const int p, const Object& data ) {
    if (array[ p ] < data)
        throw BadArgument();
    
    array[ p ] = data;
    buildHeap();
}

template <class Object>
void BinaryHeap<Object>::merge( BinaryHeap<Object>& bh ) {
    while (!bh.isEmpty()) {
        Object value = bh.deleteMinAndReturn();
        if (cellsOccupied + 1 == size)
            throw( HeapOverflow() );
        int hole = ++cellsOccupied;
        array[ hole ] = value;
    }
    buildHeap();
}

template <class Object>
void BinaryHeap<Object>::deleteMin() {
    deleteMinAndReturn();
}

template <class Object>
Object BinaryHeap<Object>::deleteMinAndReturn() {
    if (isEmpty())
        throw HeapOverflow();
    Object minItem = findMin();
    // clobber minimum element with the last value
    array[ 1 ] = array[ cellsOccupied ];
    // decrement cells occupied
    cellsOccupied--;
    // restore heap ordering
    percolateDown( 1 );
    
    return( minItem );
}

template <class Object>
const BinaryHeap<Object>& BinaryHeap<Object>::operator =( const BinaryHeap<Object>& rhs ) {
    if (this != &rhs) {
        makeEmpty();
        for (int i = 1; i <= rhs.occupied(); ++i) {
            insert( rhs.array[ i ] );
        }
    }
    return( *this );
}

template <class Object>
ostream& operator << ( ostream& outs, const BinaryHeap<Object>& h ) {
    return( h.insertion( outs ) );
}

template <class Object>
ostream& operator << ( ostream& outs, const BinaryHeap<Object>* h ) {
    return( h->insertion( outs ) );
}

template <class Object>
ostream& BinaryHeap<Object>::insertion( ostream& outs ) const {
    if (isEmpty()) 
        outs << "Empty Heap";
    else { 
        for (int i = 1; i <= cellsOccupied; ++i) {
            outs << i << ":" << array[i] << " ";
        }
    }
    outs << endl;
    return( outs );
}

template <class Object>
int BinaryHeap<Object>::getExchanges() const {
    return( exchanges );
}

template <class Object>
int BinaryHeap<Object>::getComparisons() const {
    return( comparisons );
}

}

#endif
