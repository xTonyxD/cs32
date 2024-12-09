#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "HashtableNode.h"
#include "ItemNotFound.h"
#include "DuplicateItem.h"
#include "TableFull.h"

namespace cs32 {

template <typename Type>
class Hashtable {

public:
	Hashtable( int size = 101, bool linearProbing = true );
	Hashtable( const Hashtable& rhs );
	const Hashtable& operator =( const Hashtable& rhs );
	~Hashtable();

	void makeEmpty();
	bool isEmpty() const;
	void insert( const Type& data ) ;
	void remove( const Type& data ) ;
	Type find( const Type& data ) ;
	void resetStats();
	void generateStats();
	
	void printHashTable( std::ostream& outs ) const;
	void printStats( std::ostream& outs ) const;
private:
	int mySize;
	bool myCollisionResolutionIsLinearProbing;   // quadratic if false
	HashtableNode<Type>* array;
	int occupied;
	int totalUnsuccessfulFinds, probeUnsuccessfulFinds;
	int totalSuccessfulFinds, probeSuccessfulFinds;
	int probesForCurrentFind;

	int findPosition( const Type& data );

	// this will only really work for simple types
	unsigned int hash( const Type& data ) const;
};

}
#endif
