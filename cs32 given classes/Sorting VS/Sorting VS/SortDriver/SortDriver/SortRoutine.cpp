#include <iostream>
#include <cstdlib>
#include "SortRoutine.h"

using namespace std;

namespace cs32
{


SortRoutine::SortRoutine() {
    comparisons = 0;
    exchanges = 0;
    size = 0;
}

void SortRoutine::clearStats() {
    comparisons = 0;
    exchanges = 0;
    size = 0;
}

void SortRoutine::printStats() const {
    cout << name() << " performed sort of size " << size << " with " << comparisons << " comparisons and " << exchanges << " exchanges" << endl;
}

void SortRoutine::exchange( int array[],
                           const int i,
                           const int j ) {
    exchanges++;
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

bool SortRoutine::lessthan( const int array[],
                           const int i,
                           const int j ) {
    comparisons++;
    bool result = false;
    if (array[i] < array[j])
        result = true;
    return( result );
}

bool SortRoutine::lessthan( const int value1,
                           const int value2 ) {
    comparisons++;
    bool result = false;
    if (value1 < value2)
        result = true;
    return( result );
}


std::string SortRoutine::name() const {
    return( "SortRoutine" );
}

void SortRoutine::setSize( const int theSize ) {
    size = theSize;
}

void SortRoutine::incrementExchanges( int amount ) {
    exchanges += amount;
}

void SortRoutine::incrementComparisons( int amount ) {
    comparisons += amount;
}

}
