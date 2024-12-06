#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

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

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
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

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
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



const int List::size() {
    if (this->head == nullptr) return 0;
    ListNode* node = head;
    int size = 0;

    while (node != nullptr) {
        size++;
        node = node->getNext();
    }
    
    return size;
}


const bool List::get(int i, std::string& data) {
    if (this->size() <= i) {
        //cout << "dsa"; 
        return false;
    }
    if (this->head == nullptr) {
        //cout << "ads"; 
        return false;
    }

    ListNode* node = head;

    for (int j = 0; j < i; j++) {
        node = node->getNext();
    }

    data = node->getElement();
    return true;
}


const std::string List::max() {
    if (this->head == nullptr) {
        //cout << "ads";
        return "";
    }
    ListNode* node = head;
    ListNode* max = head;

    while (node != nullptr) {
        //cout << node->getElement() << ", " << max->getElement() << " || ";
        if (std::string(node->getElement()) > std::string(max->getElement())) {
            max = node;
        }
        node = node->getNext();
    }

    return max->getElement();
}
const bool List::allMoreThan(const std::string& data) {
    if (this->head == nullptr) {
        //cout << "ads";
        return true;
    }
    ListNode* node = head;
    //cout << data;

    while (node!= nullptr) {
        //cout << node->getElement() << ", " << max->getElement() << " || ";
        if (node->getElement() < data) {
            return false;
        }
        node = node->getNext();
    }

    return true;

}
int List::strip(const std::string& data) {
    int count = 0;
    if (this->head == nullptr) {
        //cout << "ads";
        return 0;
    }
        //cout << "dsfal";
    if (this->head->getElement() == data) {
        if (this->head->getNext() == nullptr) {
            delete head;
            head = nullptr;
            return 1;
        }
        else {
            head = head->getNext();
            count++;
        }
        
    }
    
    ListNode* prev = head;
    ListNode* node = head->getNext();
    ListNode* temp = nullptr;

    while (node != nullptr) {
        if (node->getElement() == data) {
            temp = node->getNext();
            //cout << temp->getElement() << endl;
            prev->setNext(temp);
            //cout << prev->getNext()->getElement() << endl;
            count++;
            node->setNext(nullptr);
            delete node;

            //keep prev same
            node = temp;
            //cout << this->printItems() << endl << endl;
        }
        else {
            prev = node;
            node = node->getNext();
        }
    }

    return count;
}
const int List::count(const std::string& data) {
    if (this->head == nullptr) {
        return 0;
    }
    ListNode* node = head;
    int count = 0;

    while (node!= nullptr) {
        //cout << node->getElement() << ", " << max->getElement() << " || ";
        //cout << data;
        if (node->getElement() == data) {
            count++;
        }
        node = node->getNext();
    }

    return count;
}

// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

}

