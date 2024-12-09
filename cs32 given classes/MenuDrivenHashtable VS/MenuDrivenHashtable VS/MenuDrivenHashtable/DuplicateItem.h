#ifndef DUPLICATEITEM_H
#define DUPLICATEITEM_H
#include <iostream>
#include <string>

namespace cs32 {

class DuplicateItem : public std::logic_error {
public:
	DuplicateItem( const std::string& msg = "" );
};

}
#endif
