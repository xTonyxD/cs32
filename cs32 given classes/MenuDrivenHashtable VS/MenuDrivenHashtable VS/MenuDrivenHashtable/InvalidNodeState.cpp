#include "InvalidNodeState.h"

namespace cs32 {

InvalidNodeState::InvalidNodeState( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}
