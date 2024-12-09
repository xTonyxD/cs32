#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

using namespace std;

namespace cs32 {

template <typename Type >
List< Type >::List() {
	head = nullptr;
}

template <typename Type >
List< Type >::List( const List& rhs ) {
	if( rhs.head==nullptr ) head = nullptr;
    else
	   *this = rhs;
}

template <typename Type >
List< Type >::~List() {
	makeEmpty();
}

template <typename Type >
bool List< Type >::isEmpty() const {
	return( head == nullptr );
}

template <typename Type >
void List< Type >::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

template <typename Type >
void List< Type >::addToFront( const Type & data )
{
    ListNode< Type > * newnode = new ListNode< Type >( data );
    newnode->setNext( head );
    head = newnode;
}

template <typename Type >
void List< Type >::addToRear( const Type & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode< Type > * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode< Type > * newnode = new ListNode< Type >( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

template <typename Type >
void List< Type >::deleteItem( const Type & data )
{
    ListNode< Type > * node = head;
    ListNode< Type > * priornode = nullptr;
        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

template <typename Type >
bool List< Type >::findItem( const Type & data )
{
    bool result = false;
    ListNode< Type > * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

template <typename Type >
std::string List< Type >::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode< Type > * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
template <typename Type >
const List< Type >& List< Type >::operator =( const List< Type >& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		
        ListNode< Type > * right = rhs.head;
		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}
	return( *this );
}

}


#endif
