#include <iostream>
#include <string>
#include <cstdlib>
#include "Door.h"
#include "LockableDoor.h"
#include "PasswordLockDoor.h"

namespace cs32 {

PasswordLockDoor::PasswordLockDoor( const char c[], bool debug ) : LockableDoor( debug ), thePassword( c ) {

}

std::string PasswordLockDoor::name() const {
	return( "PasswordLockDoor" );
}

void   PasswordLockDoor::unlock( const char c[] ) {
	std::string cstring = std::string( c );
	if (thePassword == cstring) 
		LockableDoor::unlock();
}

std::string PasswordLockDoor::getPassword() const {
	return( thePassword );
}

std::ostream& operator <<( std::ostream& outs, const PasswordLockDoor& d ) {
	outs << d.name() << " - ";
	if (d.isLocked()) {
		outs << "locked";
	}
	else {
		outs << "unlocked";
	}
	outs << "(" << d.getPassword() << ")";
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
