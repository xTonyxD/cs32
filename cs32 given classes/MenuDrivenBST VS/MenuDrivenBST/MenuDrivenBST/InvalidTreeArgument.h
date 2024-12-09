#ifndef INVALIDTREEARGUMENT_H
#define INVALIDTREEARGUMENT_H
#include <iostream>
#include <string>
#include <stdexcept>

namespace cs32 {

class InvalidTreeArgument : public std::logic_error {
public:
	InvalidTreeArgument( const std::string& msg = "" );
};

}

#endif
