#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include <iostream>
#include "Hashtable.h"
#include "HashtableNode.h"
#include "HashtableNode.cpp"
#include "InvalidNodeState.h"
#include "Random.h"

namespace cs32 {

template <typename Type>
Hashtable<Type>::Hashtable(int size, bool linearProbing) {
	mySize = size;
	array = new HashtableNode<Type>[ mySize ];
	occupied = 0;
	totalUnsuccessfulFinds = 0;
	probeUnsuccessfulFinds = 0;
	totalSuccessfulFinds = 0;
	probeSuccessfulFinds = 0;
	myCollisionResolutionIsLinearProbing = linearProbing;
}

template <typename Type>
Hashtable<Type>::~Hashtable() {
	delete( array );
}

template <typename Type>
Hashtable<Type>::Hashtable( const Hashtable& rhs ) {
	mySize = rhs.mySize;
	array = new HashtableNode<Type>[ mySize ];
	occupied = 0;
	totalUnsuccessfulFinds = 0;
	probeUnsuccessfulFinds = 0;
	totalSuccessfulFinds = 0;
	probeSuccessfulFinds = 0;
	myCollisionResolutionIsLinearProbing = rhs.myCollisionResolutionIsLinearProbing;
	*this = rhs;
}

// Deep copy of hashtable
template <typename Type>
const Hashtable<Type>& Hashtable<Type>::operator =( const Hashtable<Type>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		mySize = rhs.mySize;
		array = new HashtableNode<Type>[ mySize ];
		occupied = 0;
		totalUnsuccessfulFinds = 0;
		probeUnsuccessfulFinds = 0;
		totalSuccessfulFinds = 0;
		probeSuccessfulFinds = 0;
		myCollisionResolutionIsLinearProbing = rhs.myCollisionResolutionIsLinearProbing;

		for (int i = 0; i < rhs.mySize; ++i) {
			if (rhs.array[i].isActive()) {
				array[i] = rhs.array[i];
			}
		}		
	}
	return( *this );
}

template <typename Type>
void Hashtable<Type>::makeEmpty() {
	occupied = 0;
	for (int i = 0; i < mySize; ++i) {
		try {
			array[i].deleteNode();
		} catch( InvalidNodeState &  ) {
			// ignore
		}
	}
}

template <typename Type>
bool Hashtable<Type>::isEmpty() const {
	return( occupied == 0 );
}

template <typename Type>
void Hashtable<Type>::resetStats() {
	totalUnsuccessfulFinds = 0;
	probeUnsuccessfulFinds = 0;
	totalSuccessfulFinds = 0;
	probeSuccessfulFinds = 0;
}

template <typename Type>
Type Hashtable<Type>::find( const Type& data )  {
	Type result( data );
	int counter = 1;
	int currentPos = findPosition( data );
    
	if (array[currentPos].isActive()) {
		result = array[currentPos].getValue();
		totalSuccessfulFinds++;
		probeSuccessfulFinds += probesForCurrentFind;
	}
	else if (array[currentPos].isDeleted()) {
		while( array[currentPos].isActiveOrDeleted() ) {
			if (myCollisionResolutionIsLinearProbing) {
				// perform linear chaining
				currentPos++;
				if (currentPos >= mySize)
					currentPos %= mySize;
			}
			else {
				// perform quadratic chaining
				currentPos += counter * counter;
				counter++;
				if (currentPos >= mySize)
					currentPos %= mySize;
			}
			if (array[currentPos].isActive() && array[currentPos].getValue() == data) {
				result = array[currentPos].getValue();
				totalSuccessfulFinds++;
				probeSuccessfulFinds += probesForCurrentFind;
				// exit loop
				break;
			}
			else if (array[currentPos].isEmpty()) {
				totalUnsuccessfulFinds++;
				probeUnsuccessfulFinds += probesForCurrentFind;
				throw ItemNotFound();
			}
		}
	}
	else {
		totalUnsuccessfulFinds++;
		probeUnsuccessfulFinds += probesForCurrentFind;
		throw ItemNotFound();
	}
	return( result );
}

template <typename Type>
void Hashtable<Type>::insert( const Type& data )  {
	if (occupied == mySize)
		throw TableFull();
	int currentPosition = findPosition( data );
	if (array[currentPosition].isActive()) {
		throw DuplicateItem();
	}
	array[currentPosition] = HashtableNode<Type>( data, HashtableNode<Type>::ACTIVE );
	++occupied;
}

template <typename Type>
void Hashtable<Type>::remove( const Type& data )  {
	int currentPosition = findPosition( data );
	if (array[currentPosition].isActive()) {
		array[currentPosition].deleteNode();
		--occupied;
	}
	else {
		throw ItemNotFound();
	}
}

template <typename Type>
unsigned int Hashtable<Type>::hash( const Type& data ) const {
	// the following hash function came out of the Weiss book
	// it seems pretty clever, using the prime value of 31 but
	// this will only really work for simple types
//	unsigned int result = 0;
//	const char* key = reinterpret_cast<const char*>( &data );
//
//	for (size_t i = 0; i < sizeof( Object ); ++i) 
//		result = 31 * result + key[ i ];
//
//	return( result );
	// for class purposes, it much more helpful to have a
	// hash function that one can compute easily in your mind
	// so I am going to use the function below
	// this will only really work for ints, but heh, se la vie!
	unsigned int result = 0;
	const int* key = reinterpret_cast<const int*>( &data );
	int k = *key;
	result = k % mySize;
	return( result );
}

template <typename Type>
int Hashtable<Type>::findPosition( const Type& data ) {
	probesForCurrentFind = 1;
	int counter = 1;
	int currentPos = hash( data ) % mySize;
	while (array[ currentPos ].isActiveOrDeleted()) {
		try {
			if (array[ currentPos ].getValue() != data) {
				probesForCurrentFind++;
				if (myCollisionResolutionIsLinearProbing) {
					// perform linear chaining
					currentPos++;
					if (currentPos >= mySize)
						currentPos %= mySize;
				}
				else {
					// perform quadratic chaining
					currentPos += counter * counter;
					counter++;
					if (currentPos >= mySize)
						currentPos %= mySize;
				}
			}
			else {
				break;
			}
		} catch( InvalidNodeState &  ) {
			// ignore, I guess...
			break;
		}
	}
	return( currentPos );
}

template <typename Type>
void Hashtable<Type>::printHashTable( std::ostream& outs ) const {
	outs << "occupied=" << occupied << "  size=" << mySize;
	outs << "  collision=";
	if (myCollisionResolutionIsLinearProbing) {
		outs << "linear";	
	}
	else {
		outs << "quadratic";	
	}
	outs << std::endl;
	for (int i = 0; i < mySize; i++) {
		if (array[i].isActive()) {
			outs << i << "-"; 
			array[i].printHashTableNode( outs );
		}
	}
	outs << std::endl;
}

template <typename Type>
void Hashtable<Type>::printStats( std::ostream& outs ) const {
	if (totalSuccessfulFinds != 0)
		outs << totalSuccessfulFinds << " successful finds, each in an average of " << 	((double) probeSuccessfulFinds ) / ((double) totalSuccessfulFinds) << " probes" << std::endl;
	if (totalUnsuccessfulFinds != 0)
		outs << totalUnsuccessfulFinds << " unsuccessful finds, each in an average of " << 	((double) probeUnsuccessfulFinds ) / ((double) totalUnsuccessfulFinds) << " probes" << std::endl;
}

template <typename Type>
void Hashtable<Type>::generateStats() {
	// look successfully
	for (int i = 0; i < mySize; i++) {
		if (array[i].isActive()) {
		 	find( array[i].getValue() );
		}
	}
	Random r( 10000 );
	int k = 0;
	// look unsuccessfully
	for (int j = 0; j < occupied; j++) {
		int value = r.random();
		// is the value in the table?
		bool foundValue = false;
		while (!foundValue) {
			for (k = 0; k < mySize; k++) {
				if (array[k].isActive()) {
					if (array[k].getValue() == value) {
						foundValue = true;
					}
				}
			}
			if (foundValue) {
				foundValue = false;
				value = r.random();
			}
			else if (k == mySize) {
				break;
			}
		}
		try {
			find( value );   /// this will fail
		} catch( ItemNotFound &   ) {
			// ignore
		}

	}
}	


}
#endif
