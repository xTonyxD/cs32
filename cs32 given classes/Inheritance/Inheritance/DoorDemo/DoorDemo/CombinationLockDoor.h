#ifndef COMBINATIONLOCKDOOR_H
#define COMBINATIONLOCKDOOR_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Door.h"
#include "LockableDoor.h"

namespace cs32 {

class CombinationLockDoor : public LockableDoor {
public:
	CombinationLockDoor( int combo = 0,
						 bool debug =false );

	std::string name() const;
	void   unlock( int combo );
	int    getCombo() const;

	friend std::ostream& operator <<( std::ostream& outs, const CombinationLockDoor& d );
protected:
	int theCombination;
};

}

#endif
