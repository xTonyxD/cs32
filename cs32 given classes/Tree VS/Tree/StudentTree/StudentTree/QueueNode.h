#ifndef QUEUENODE_H
#define QUEUENODE_H
#include <iostream>

namespace cs32 {

template <typename Type>
class QueueNode {
public:
	QueueNode( const Type& theElement = Type(), QueueNode * node = nullptr );

	template< typename aType > friend std::ostream& operator <<( std::ostream& outs, const QueueNode < aType > * node );

	// these accessors and mutators are called
	// from Queue class
	// no public methods expose QueueNode instances
	// outside the Queue class
	const Type& getElement() const;
	QueueNode* getNext() const;
	void setNext( QueueNode * node );

private:
	Type element;
	QueueNode* next;

};

}
#endif
