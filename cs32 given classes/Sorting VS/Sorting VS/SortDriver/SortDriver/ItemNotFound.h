#ifndef ITEMNOTFOUND_H
#define ITEMNOTFOUND_H
#include <iostream>
#include <string>
#include <stdexcept>

namespace cs32
{

class ItemNotFound : public std::logic_error {
public:
    ItemNotFound( const std::string& msg = "" );
};

}

#endif
