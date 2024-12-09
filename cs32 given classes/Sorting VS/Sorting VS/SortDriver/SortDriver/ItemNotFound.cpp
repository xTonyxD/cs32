#include <iostream>
#include <string>
#include "ItemNotFound.h"

namespace cs32
{

ItemNotFound::ItemNotFound( const std::string& msg ) : logic_error( msg.c_str() ) {}


}
