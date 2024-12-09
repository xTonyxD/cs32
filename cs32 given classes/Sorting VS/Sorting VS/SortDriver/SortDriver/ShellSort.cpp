#include <iostream>
#include <cstdlib>
#include <string>
#include "ShellSort.h"
#include "SortRoutine.h"

namespace cs32
{

ShellSort::ShellSort() : SortRoutine() {
}

// each kind of sort will provide an implementation of this method
void ShellSort::sort( int array[], int size ) {
    setSize( size );
    shell( array, size );
}

// perform the shell sort
void ShellSort::shell( int array[], int size ) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int tmp = array[ i ];
            int j = i;
            for ( ; j >= gap && lessthan( tmp,
                                         array[ j-gap ] ); j -= gap ) {
                exchange(array, j, j-gap );
            }
            array[ j ] = tmp;
            incrementExchanges();
        }
    }
}

// each kind of sort has an algorithm name
std::string ShellSort::name() const {
    return( "ShellSort" );
}


}
