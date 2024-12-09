#include "BadIterator.h"

namespace cs32 {

BadIterator::BadIterator( const std::string& msg ) : std::logic_error( msg.c_str() ) {}


}
