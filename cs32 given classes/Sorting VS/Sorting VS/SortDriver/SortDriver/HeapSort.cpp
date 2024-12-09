#include <iostream>
#include <cstdlib>
#include <string>
#include "HeapSort.h"
#include "SortRoutine.h"
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"

namespace cs32
{

HeapSort::HeapSort() : SortRoutine() {
}

// each kind of sort will provide an implementation of this method
void HeapSort::sort( int array[], int size ) {
    setSize( size );
    heap( array, size );
}

// perform the heap sort
void HeapSort::heap( int array[], int size ) {
    // build the heap
    BinaryHeap<int> theheap( array, size );
    // pull out the minimum value
    for (int i = 0; i < size; i++) {
        array[ i ] = theheap.deleteMinAndReturn();
    }
    // the heap is tracking its comparisons and exchanges
    int exchanges = theheap.getExchanges();
    int comparisons = theheap.getComparisons();
    
    incrementExchanges( exchanges );
    incrementComparisons( comparisons );
}

// each kind of sort has an algorithm name
std::string HeapSort::name() const {
    return( "HeapSort" );
}


}
