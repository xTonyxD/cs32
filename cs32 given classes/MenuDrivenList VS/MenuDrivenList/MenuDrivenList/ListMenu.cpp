// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"

using namespace std;
using namespace cs32;

enum CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };

CHOICE menu();
void printList( const List& l );

int main() {
	string value;
	List list;
    List list2;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			list.makeEmpty();
			break;
		case ISEMPTY:
			if (list.isEmpty()) {
				cout << "list is empty" << endl;
			}
			else {
				cout << "list is not empty" << endl;
			}
			break;
		case DELETE:
			cout << "Please provide a string to remove: ";
			cin  >> value; 
			list.deleteItem( value );
			break;
		case ADDTOFRONT:
			cout << "Please provide a string to insert in front: ";
			cin  >> value; 
			list.addToFront( value );
			break;
        case ADDTOREAR:
            cout << "Please provide a string to insert in rear: ";
            cin  >> value;
            list.addToRear( value );
            break;
		case FIND:
			cout << "Please provide a string to find: ";
			cin  >> value;
            cout.setf( ios::boolalpha );
            cout << list.findItem( value ) << endl;
            cout.unsetf( ios::boolalpha );
			break;
		case PRINT:
            cout << list.printItems() << endl;;
			break;
        case OPERATOR:
            list2 = list;
            cout << "second list now:" << endl;
            cout << list2.printItems() << endl;
            break;
        case QUIT:
            break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty (D)elete (A)ddToFront (R)AddtoRear  (F)ind (P)rint (=) (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
    case 'D':
    case 'd':
        result = DELETE;
        break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
    case 'A':
    case 'a':
        result = ADDTOFRONT;
        break;
	case 'R':
	case 'r':
		result = ADDTOREAR;
		break;
	case 'F':
	case 'f':
		result = FIND;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
    case '=':
        result = OPERATOR;
        break;
	}

	return( result );
}
