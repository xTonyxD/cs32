#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <string>

namespace cs32 {

template <typename Type>
class ListNode {
public:
	ListNode( Type data, ListNode< Type > * node = nullptr );
	bool nextIsNull() const;

	Type getElement() const;
	ListNode< Type >* getNext() const;
	void setNext( ListNode< Type > * node );

private:
	Type    value;
	ListNode< Type >* next;

};

}
#endif
