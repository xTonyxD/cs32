#ifndef DOOR_H
#define DOOR_H
#include <iostream>
#include <string>
#include <cstdlib>

namespace cs32 {

class Door {
public:
	Door( bool debug = false );
	virtual ~Door();

	bool   isOpen() const;
	virtual void   open();
	void   close();
	std::string name() const;

	friend std::ostream& operator <<( std::ostream& outs, const Door& d );
protected:
	bool isShut;
	bool debugFlag;
};

}

#endif
