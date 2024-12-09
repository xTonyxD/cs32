#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include <vector>


// WHAT ABOUT DESTRUCTOR AND OPERATOR = AND COPY CONSTRUCTOR??


namespace cs32
{


template <class Object>
class BinaryHeap {
public:
    BinaryHeap( int initialSize = 100 );
    BinaryHeap( const std::vector<Object> &v );
    BinaryHeap( const Object data[], int dataSize );
    BinaryHeap( const BinaryHeap& rhs );
    ~BinaryHeap();
    
    bool isEmpty() const;
    void makeEmpty();
    int  occupied() const;
    
    const Object& findMin() const;
    
    int insert( const Object& data );
    void decreaseValue( const int p, const Object& data );
    void merge( BinaryHeap& bh );
    void deleteMin();
    Object deleteMinAndReturn();
    
    const BinaryHeap& operator =( const BinaryHeap& rhs );

    template<typename Type> friend std::ostream& operator << ( std::ostream& outs, const BinaryHeap<Type>& b );
    template<typename Type> friend std::ostream& operator << ( std::ostream& outs, const BinaryHeap<Type>* b );
    std::ostream& insertion( std::ostream& outs ) const;
    
    int getExchanges() const;
    int getComparisons() const;
private:
    // this will be sized into a dynamic array to hold the heap
    Object *  array;
    int       cellsOccupied;
    int		  size;
    
    void   buildHeap();
    void   percolateDown( int index );
    int    parentIndex( int index ) const;
    Object parentValue( int index ) const;
    
    int exchanges;
    int comparisons;
};

}
#endif
