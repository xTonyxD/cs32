#ifndef TABLEFULL_H
#define TABLEFULL_H
#include <iostream>
#include <string>

namespace cs32 {

class TableFull : public std::logic_error {
public:
	TableFull( const std::string& msg = "" );
};

}
#endif
