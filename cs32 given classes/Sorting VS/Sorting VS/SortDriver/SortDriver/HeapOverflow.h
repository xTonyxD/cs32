#ifndef HEAPOVERFLOW_H
#define HEAPOVERFLOW_H
#include <iostream>
#include <string>
#include <stdexcept>

namespace cs32
{

class HeapOverflow : public std::logic_error {
public:
    HeapOverflow( const std::string& msg = "" );
};

}


#endif
