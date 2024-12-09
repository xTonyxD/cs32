#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "SortRoutine.h"

namespace cs32
{

class ShellSort : public SortRoutine {
public:
    ShellSort();
    
    // each kind of sort will provide an implementation of this method
    virtual void sort( int array[], int size );
    // each kind of sort has an algorithm name
    virtual std::string name() const;
private:
    void shell( int array[], int size );
};

}

#endif
