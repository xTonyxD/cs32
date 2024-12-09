#ifndef BADARGUMENT_H
#define BADARGUMENT_H
#include <iostream>
#include <string>

namespace cs32
{

class BadArgument : public std::logic_error {
public:
    BadArgument( const std::string& msg = "" );
};

}

#endif
