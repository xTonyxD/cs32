#include <iostream>
#include <cstdlib>
#include <string>
#include "InsertionSort.h"
#include "SortRoutine.h"

namespace cs32
{

InsertionSort::InsertionSort() : SortRoutine() {
}

// each kind of sort will provide an implementation of this method
void InsertionSort::sort( int array[], int size ) {
    setSize( size );
    insertion( array, size );
}

// perform the insertion sort
void InsertionSort::insertion( int array[], int size ) {
    for (int p = 1; p < size; p++) {
        int tmp = array[p];
        int j;
        for (j = p; j > 0 && lessthan( tmp, array[j-1] ); j--) {
            exchange(array, j, j-1 );
        }
        array[j] = tmp;
        incrementExchanges();
    }
}

// each kind of sort has an algorithm name
std::string InsertionSort::name() const {
    return( "InsertionSort" );
}

}
