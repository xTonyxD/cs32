#include "EmptyQueue.h"

namespace cs32 {

EmptyQueue::EmptyQueue( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}
