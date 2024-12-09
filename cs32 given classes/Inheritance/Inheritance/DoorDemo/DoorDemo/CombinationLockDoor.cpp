#include <iostream>
#include <cstdlib>
#include <string>
#include "Door.h"
#include "LockableDoor.h"
#include "CombinationLockDoor.h"

namespace cs32 {
	
CombinationLockDoor::CombinationLockDoor( int combo, bool debug ) : LockableDoor( debug ), theCombination( combo ) {
	
}

void CombinationLockDoor::unlock( int combo ) {
	if (isLocked() && (combo == theCombination))
		LockableDoor::unlock();
}

int CombinationLockDoor::getCombo() const {
	return( theCombination );
}

std::string CombinationLockDoor::name() const {
	return( "CombinationLockDoor" );
}

std::ostream& operator <<( std::ostream& outs, const CombinationLockDoor& d ) {
	outs << d.name() << " - ";
	if (d.isLocked()) {
		outs << "locked";
	}
	else {
		outs << "unlocked";
	}
	outs << "(" << d.getCombo() << ")";
	outs << " - ";
	if (d.isOpen()) {
		outs << "open";
	}
	else {
		outs << "shut";
	}
	outs << std::endl;
	return( outs );
}

}
