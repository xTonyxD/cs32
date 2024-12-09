#ifndef INVALIDNODESTATE_H
#define INVALIDNODESTATE_H
#include <iostream>
#include <string>

namespace cs32 {

class InvalidNodeState : public std::logic_error {
public:
	InvalidNodeState( const std::string& msg = "" );
};

}
#endif
