// Random.h
//
#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>

namespace cs32 {

class Random {
public:
	Random( int theceil = 1 );  // seed from system clock
	Random( long theseed, int theceil = 1 );

	int    random();        // returns a pseudo-random number
				// between 0 and ceil
	void         seed( long theseed );
								// reseeds the generator
private:
	long double randx;
	int ceil;
};

}
#endif
