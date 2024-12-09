#ifndef LOCKABLEDOOR_H
#define LOCKABLEDOOR_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Door.h"

namespace cs32 {

class LockableDoor : public Door {
public:
	LockableDoor( bool debug = false );

	bool   isLocked() const;
	void   open();
	void   lock();
	std::string name() const;
	void   unlock();

	friend std::ostream& operator <<( std::ostream& outs, const LockableDoor& d );
protected:
	bool theLock;
};

}

#endif
