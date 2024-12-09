#ifndef PASSWORDLOCKDOOR_H
#define PASSWORDLOCKDOOR_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Door.h"
#include "LockableDoor.h"

namespace cs32 {

class PasswordLockDoor : public LockableDoor {
public:
	PasswordLockDoor( const char c[] = "", 
					  bool debug = false );

	std::string name() const;
	void   unlock( const char c[] = "" );
	std::string getPassword() const;

	friend std::ostream& operator <<( std::ostream& outs, const PasswordLockDoor& d );
protected:
	std::string thePassword;
};

}

#endif
