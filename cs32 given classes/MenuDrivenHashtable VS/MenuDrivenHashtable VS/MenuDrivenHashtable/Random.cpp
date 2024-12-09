// Random.cpp 
//
#include <iostream>
#include "Random.h"
#include <cmath>
#include <time.h>
#include <utility>
#include <random>

namespace cs32 {

Random::Random( int theceil ) {

    
    ceil = theceil;
 
}

Random::Random( long theseed, int theceil ) {
	randx = theseed;
	ceil = theceil;
}
 
void Random::seed( long theseed ) {
    randx = theseed;
}

int Random::random( ) {
    using namespace std;
    static random_device rd;
    static mt19937 generator( rd() );
    uniform_int_distribution<> distro( 1, ceil );
    
    return( distro( generator ));
}


}
