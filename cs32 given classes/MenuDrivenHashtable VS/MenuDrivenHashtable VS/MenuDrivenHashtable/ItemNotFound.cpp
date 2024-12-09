#include "ItemNotFound.h"

namespace cs32 {

ItemNotFound::ItemNotFound( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}
