#ifndef QUEUENODE_H
#define QUEUENODE_H
#include <iostream>
#include <string>

namespace cs32 {

class QueueNode {
public:
	QueueNode( const std::string& theElement = "", QueueNode * node = nullptr );

	// these accessors and mutators are called
	// from Queue class
	// no public methods expose QueueNode instances
	// outside the Queue class
	const std::string& getElement() const;
	QueueNode* getNext() const;
	void setNext( QueueNode * node );

private:
	std::string element;
	QueueNode* next;

};

}
#endif
