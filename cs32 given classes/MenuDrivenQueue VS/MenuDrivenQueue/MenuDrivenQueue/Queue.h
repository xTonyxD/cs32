#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include "QueueNode.h"
#include "EmptyQueue.h"

namespace cs32 {

class Queue {
public:
	Queue();
	Queue( const Queue& rhs );
	~Queue();

	bool isEmpty() const;
	void makeEmpty();
	void enqueue( const std::string& data );
	std::string dequeue();
	std::string getFront() const;
	
	const Queue& operator =( const Queue& rhs );

	std::string printQueue( );
private:
	QueueNode * frontNode;
	QueueNode * backNode;
};

}
#endif
