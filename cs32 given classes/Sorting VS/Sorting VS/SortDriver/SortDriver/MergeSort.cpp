#include <iostream>
#include <cstdlib>
#include <string>
#include "MergeSort.h"
#include "SortRoutine.h"

namespace cs32
{

MergeSort::MergeSort() : SortRoutine() {
}

// each kind of sort will provide an implementation of this method
void MergeSort::sort( int array[], int size ) {
    setSize( size );
    mergesort( array, size );
}

// perform the merge sort
void MergeSort::mergesort( int array[], int size ) {
    int * tmpArray = new int[ size ];
    mergesort( array, tmpArray, size-1, 0, size-1 );
    delete[ ] tmpArray;
}

void MergeSort::mergesort( int array[], int tmpArray[], int size,
                          int left, int right ) {
    if (left < right) {
        int center = (left + right) / 2;
        mergesort( array, tmpArray, size, left, center );
        mergesort( array, tmpArray, size, center+1, right );
        merge( array, tmpArray, left, center+1, right );
    }
}

void MergeSort::merge( int array[], int tmpArray[],
                      int leftPos, int rightPos, int rightEnd ) {
    
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (array[ leftPos ] <= array[ rightPos ]) {
            tmpArray[ tmpPos++ ] = array[ leftPos++ ];
        }
        else {
            tmpArray[ tmpPos++ ] = array[ rightPos++ ];
        }
        incrementExchanges();
    }
    
    while (leftPos <= leftEnd) {
        tmpArray[ tmpPos++ ] = array[ leftPos++ ];
        incrementExchanges();
    }
    
    while (rightPos <= rightEnd) {
        tmpArray[ tmpPos++ ] = array[ rightPos++ ];
        incrementExchanges();
    }
    
    for (int i = 0; i < numElements; i++, rightEnd--) {
        array[ rightEnd ] = tmpArray[ rightEnd ];
        incrementExchanges();
    }
}

// each kind of sort has an algorithm name
std::string MergeSort::name() const {
    return( "MergeSort" );
}

}

