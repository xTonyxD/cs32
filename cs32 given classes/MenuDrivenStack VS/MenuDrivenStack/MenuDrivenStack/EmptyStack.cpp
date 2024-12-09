#include "EmptyStack.h"

namespace cs32 {

EmptyStack::EmptyStack( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}


