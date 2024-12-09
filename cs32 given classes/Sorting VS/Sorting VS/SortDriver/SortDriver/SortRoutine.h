#ifndef SORTROUTINE_H
#define SORTROUTINE_H
#include <iostream>
#include <cstdlib>
#include <string>

namespace cs32
{

class SortRoutine {
public:
    SortRoutine();
    
    void clearStats();
    void printStats() const;
    // each kind of sort will provide an implementation of this method
    virtual void sort( int array[], int size ) = 0;
    // each kind of sort has an algorithm name
    virtual std::string name() const;
    
protected:
    void exchange( int array[],
                  const int i,
                  const int j );
    bool lessthan( const int array[],
                  const int i,
                  const int j );
    bool lessthan( const int value1,
                  const int value2 );
    void setSize( const int theSize );
    void incrementExchanges( int amount = 1 );
    void incrementComparisons( int amount = 1 );
private:
    int comparisons;
    int exchanges;
    int size;
};

}

#endif
