#include <iostream>
#include <cstdlib>
#include <string>
#include "QuickSort.h"
#include "SortRoutine.h"

namespace cs32
{

QuickSort::QuickSort() : SortRoutine() {
}

// each kind of sort will provide an implementation of this method
void QuickSort::sort( int array[], int size ) {
    setSize( size );
    quicksort( array, size );
}

// perform the quick sort
void QuickSort::quicksort( int array[], int size ) {
    quicksort( array, 0, size-1 );
}

void QuickSort::quicksort( int array[], 
                          int low, int high ) {
    // Base case
    if (low + 1 >= high) {
        if (lessthan( array, high, low )) {
            exchange( array, high, low );
        }
    }
    else {
        // Sort low, middle and high
        int middle = (low + high) / 2;
        if (lessthan( array, middle, low )) {
            exchange( array, middle, low );
        }
        if (lessthan( array, high, low )) {
            exchange( array, high, low );
        }
        if (lessthan( array, high, middle )) {
            exchange( array, high, middle );
        }
        
        // Place Pivot
        int pivot = array[ middle ];
        exchange( array, middle, high-1 );
        
        // Partition
        int i, j;
        for (i = low, j = high - 1; ; ) {
            while (lessthan( array[ ++i ], pivot)) {}
            while (lessthan(pivot, array[ --j ])) {}
            if (lessthan( i, j )) {
                exchange( array, i, j );
            }
            else {
                break;
            }
        }
        
        // Restore pivot
        exchange( array, i, high-1 );
        
        // Recurse on set L and set G
        quicksort( array, low, i - 1 );
        quicksort( array, i + 1, high );
    }
}

// each kind of sort has an algorithm name
std::string QuickSort::name() const {
    return( "QuickSort" );
}

}
