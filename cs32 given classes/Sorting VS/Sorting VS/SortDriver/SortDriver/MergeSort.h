#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "SortRoutine.h"

namespace cs32
{

class MergeSort : public SortRoutine {
public:
    MergeSort();
    
    // each kind of sort will provide an implementation of this method
    virtual void sort( int array[], int size );
    // each kind of sort has an algorithm name
    virtual std::string name() const;
private:
    void mergesort( int array[], int size );
    void mergesort( int array[], int tmpArray[], int size,
                   int left, int right );
    void merge( int array[], int tmpArray[],
               int leftPos, int rightPos, int rightEnd );
};

}

#endif
