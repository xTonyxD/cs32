#include "BadArgument.h"

namespace cs32 {

BadArgument::BadArgument( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}
