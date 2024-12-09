#ifndef LISTNODE_CPP
#define LISTNODE_CPP

#include "ListNode.h"
using namespace std;

namespace cs32 {

template <typename Type>
ListNode< Type >::ListNode( Type v,
                    ListNode< Type > * node ) {
	value = v;
	next = node;
}

template <typename Type>
bool ListNode< Type >::nextIsNull() const {
	return( next == nullptr );
}

template <typename Type>
Type ListNode< Type >::getElement() const {
	return( value );
}

template <typename Type>
ListNode< Type > * ListNode< Type >::getNext() const {
	return( next );
}

template <typename Type>
void ListNode< Type >::setNext( ListNode * node ) {
	next = node;
}

}

#endif
