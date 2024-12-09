#include "Random.h"
#include <time.h>
#include <utility>
#include <random>

namespace cs32 {

Random::Random( int ceiling ) {
	my_ceiling = ceiling;


}

int Random::random() const {
    using namespace std;
    static random_device rd;
    static mt19937 generator( rd() );
    uniform_int_distribution<> distro( 1, my_ceiling );
    
    return( distro( generator ));
}

}


