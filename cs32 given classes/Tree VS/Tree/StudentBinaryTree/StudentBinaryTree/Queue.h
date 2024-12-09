#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "QueueNode.h"
#include "EmptyQueue.h"

namespace cs32 {

template <typename Type>
class Queue {
public:
	Queue();
	Queue( const Queue& rhs );
	~Queue();

	bool isEmpty() const;
	void makeEmpty();
	void enqueue( const Type& data );
	const Type dequeue();
	const Type& getFront() const;
	
	const Queue& operator =( const Queue& rhs );
// take this out for the student version
	template <typename aType> friend std::ostream& operator << ( std::ostream& outs, const Queue<aType> & q );
	template <typename aType> friend std::ostream& operator << ( std::ostream& outs, const Queue<aType> * q );

private:
	QueueNode<Type> * frontNode;
	QueueNode<Type> * backNode;
};

}
#endif
