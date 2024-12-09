#include <iostream>
#include <string>
#include "HeapOverflow.h"

namespace cs32
{

HeapOverflow::HeapOverflow( const std::string& msg ) : std::logic_error( msg.c_str() ) {}


}

