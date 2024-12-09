#ifndef HASHTABLENODE_H
#define HASHTABLENODE_H
#include <iostream>

namespace cs32 {

template <typename Type>
class HashtableNode {
public:
	// Node States
	enum NodeState { ACTIVE, EMPTY, DELETED };

	HashtableNode( const Type& v = Type(),
				   NodeState s = EMPTY );

	bool isActive() const;
	bool isEmpty() const;
	bool isDeleted() const;
	bool isEmptyOrDeleted() const;
	bool isActiveOrDeleted() const;
	void deleteNode();
	void setValue( const Type& v );
	Type getValue();

	void printHashTableNode( std::ostream& outs );

private:
	Type value;
	NodeState state;
};

}
#endif
