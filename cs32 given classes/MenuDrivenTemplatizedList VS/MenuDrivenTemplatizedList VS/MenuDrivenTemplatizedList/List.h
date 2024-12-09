#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "ListNode.h"

namespace cs32 {

template <typename Type>
class List {
public:
	List();
	List( const List& rhs );
	~List();

	bool isEmpty() const;
	void makeEmpty();
    void addToFront( const Type & data );
    void addToRear( const Type & data );
    void deleteItem( const Type & data );
    bool findItem( const Type & data );
    std::string printItems( );
	
	const List& operator =( const List& rhs );
private:
	ListNode< Type > * head;
	
};

}
#endif
