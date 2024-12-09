#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <cstdlib>

namespace cs32 {

	class Random {
	public:
		Random( int ceiling = 1 );

		int random() const;
	private:
        int my_seed;
        int my_ceiling;
	};

}

#endif
