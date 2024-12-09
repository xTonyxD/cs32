#include <iostream>
#include <cstdlib>
#include <string>
#include "Door.h"

namespace cs32 {

Door::Door( bool debug ) : isShut( false ), debugFlag( debug ) {
}

Door::~Door()
{

}

bool Door::isOpen() const {
	return( !isShut );
}

void Door::open() {
	if (debugFlag)
		std::cout << ">>>> inside Door::open() <<<<" << std::endl;
	isShut = false;
}

void Door::close() {
	isShut = true;
}

std::string Door::name() const {
	return( "Door" );
}

std::ostream& operator <<( std::ostream& outs, const Door& d ) {
	outs << d.name() << " - ";
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
