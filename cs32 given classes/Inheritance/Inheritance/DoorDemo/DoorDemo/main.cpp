// DoorDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Door.h"
#include "LockableDoor.h"
#include "CombinationLockDoor.h"
#include "PasswordLockDoor.h"

typedef cs32::Door* DoorPtr;
typedef cs32::LockableDoor* LockablePtr;

void useDoorPointers();
void workWithDoors();
void open( cs32::Door& d );

int main()
{
	using namespace cs32;
	using namespace std;
	cout << "===================" << endl;
	workWithDoors();
	useDoorPointers();
	cout << "===================" << endl;
	return( 0 );
}

void useDoorPointers() {
	using namespace cs32;
	using namespace std;
	cout << "-----1. Calling open() on Door----" << endl;
	DoorPtr p = new Door( true );	// set debugFlag
	p->open();		// calls Door::open
	delete( p );
	cout << "-----2. Calling open() on Door----" << endl;
	LockablePtr lp = new LockableDoor( true );   // set debugFlag
	p = lp; 
	lp->open();		// calls LockableDoor::open
	p->open();		// which open??
	delete( p );

	cout << "-----3. Calling open() on Door----" << endl;
	// let's prove this invocation has everything
	// to do with pointers
	LockableDoor ld = LockableDoor( true );
	Door d;
	d = ld;

	ld.open();      // which open??
	d.open();       // which open??

}

void workWithDoors() {
	using namespace cs32;
	using namespace std;
	cout << "---work with doors---" << endl;
	Door d = Door( true ); // set debugFlag
	LockableDoor ld = LockableDoor( true ); // set debugFlag
	cout << "---calling open( Door )---" << endl;
	open( d );
	cout << "---calling open( LockableDoor )---" << endl;
	open( ld );
}

void open( cs32::Door& d ) {
	d.open();
}
