#include <iostream>
#include <cstdlib>
#include <string>
#include "Door.h"
#include "LockableDoor.h"

namespace cs32 {

LockableDoor::LockableDoor( bool debug ) : Door( debug ), theLock( false ) {
	
}

void LockableDoor::open() {
	if (debugFlag)
		std::cout << ">>>> inside LockableDoor::open() <<<<" << std::endl;
	if (!isLocked())
		Door::open();
}

void LockableDoor::lock() {
	theLock = true;
}

void LockableDoor::unlock() {
	theLock = false;
}

bool LockableDoor::isLocked() const {
	return( theLock );
}

std::string LockableDoor::name() const {
	return( "LockableDoor" );
}

std::ostream& operator <<( std::ostream& outs, const LockableDoor& d ) {
	outs << d.name() << " - ";
	if (d.isLocked()) {
		outs << "locked";
	}
	else {
		outs << "unlocked";
	}
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
