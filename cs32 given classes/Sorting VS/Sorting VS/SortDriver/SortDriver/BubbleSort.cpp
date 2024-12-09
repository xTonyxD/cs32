#include <iostream>
#include <cstdlib>
#include <string>
#include "BubbleSort.h"
#include "SortRoutine.h"

namespace cs32
{

BubbleSort::BubbleSort() : SortRoutine() {
}

// each kind of sort will provide an implementation of this method
void BubbleSort::sort( int array[], int size ) {
    setSize( size );
    bubble( array, size );
}

// perform the bubble sort
void BubbleSort::bubble( int array[], int size ) {
    for (int p = 0; p < size - 1; p++) {
        for (int k = 1; k < size - p; k++) {
            if (lessthan(array, k, k-1))
                exchange(array, k, k-1 );
        }
    }
}

// each kind of sort has an algorithm name
std::string BubbleSort::name() const {
    return( "BubbleSort" );
}


}
