#include "ValueNotFound.h"

namespace cs32 {

ValueNotFound::ValueNotFound( const std::string& msg ) : std::logic_error( msg.c_str() ) {}


}
