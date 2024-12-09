#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "StackNode.h"
#include "EmptyStack.h"

namespace cs32 {

class Stack {
public:
	Stack();
	Stack( const Stack& rhs );
	~Stack();

	bool isEmpty() const;
	void makeEmpty();
	void push( const std::string& data );
	void pop();
	std::string top() const;
	std::string topAndPop();
	std::string printStack( ) const;
	
	const Stack& operator =( const Stack& rhs );

private:
	StackNode * topNode;
};

}

#endif
