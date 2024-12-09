#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>
#include <string>

namespace cs32 {

class StackNode {
public:
	StackNode( const std::string & data = "", StackNode * node = nullptr );

	const std::string & getElement() const;
	StackNode* getNext() const;
	void setNext( StackNode* node );
private:
	std::string element;
	StackNode* next;

};

}
#endif
