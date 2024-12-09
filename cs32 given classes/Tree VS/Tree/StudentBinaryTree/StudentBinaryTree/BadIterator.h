#ifndef BADITERATOR_H
#define BADITERATOR_H
#include <iostream>
#include <string>

namespace cs32 {

class BadIterator : public std::logic_error {
public:
	BadIterator( const std::string& msg = "" );
};

}

#endif
