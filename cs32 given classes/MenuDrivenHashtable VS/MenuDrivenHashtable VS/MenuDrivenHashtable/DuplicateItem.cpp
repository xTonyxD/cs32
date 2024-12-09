#include "DuplicateItem.h"

namespace cs32 {

DuplicateItem::DuplicateItem( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}
