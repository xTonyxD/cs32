// Menu.cpp : Defines the entry point for the console application.
//
/*
#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

using namespace std;
using namespace cs32;

enum class CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };

CHOICE menu();

int main(int argc, char* argv[]) {
    
	string value;
	List list;
    List list2;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
        case CHOICE::MAKEEMPTY:
			list.makeEmpty();
			break;
        case CHOICE::ISEMPTY:
			if (list.isEmpty()) {
				cout << "list is empty" << endl;
			}
			else {
				cout << "list is not empty" << endl;
			}
			break;
        case CHOICE::DELETE:
			cout << "Please provide a string to remove: ";
			cin  >> value; 
			list.deleteItem( value );
			break;
        case CHOICE::ADDTOFRONT:
			cout << "Please provide a string to insert in front: ";
			cin  >> value; 
			list.addToFront( value );
			break;
        case CHOICE::ADDTOREAR:
            cout << "Please provide a string to insert in rear: ";
            cin  >> value;
            list.addToRear( value );
            break;
        case CHOICE::FIND:
			cout << "Please provide a string to find: ";
			cin  >> value;
            cout.setf( ios::boolalpha );
            cout << list.findItem( value ) << endl;
            cout.unsetf( ios::boolalpha );
			break;
        case CHOICE::PRINT:
            cout << list.printItems() << endl;;
			break;
        case CHOICE::OPERATOR:
            list2 = list;
            cout << "second list now:" << endl;
            cout << list2.printItems() << endl;
            break;
        case CHOICE::QUIT:
            break;
	}	

	} while (choice != CHOICE::QUIT);

	return( 0 );
}

CHOICE menu() {
	string s;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty (D)elete (A)ddToFront (R)AddtoRear  (F)ind (P)rint (=) (Q)uit: " << endl;
	cin  >> s;
    char choice = s.at( 0 );
	switch( choice ) {
	case 'M':
	case 'm':
		result = CHOICE::MAKEEMPTY;
		break;
    case 'D':
    case 'd':
        result = CHOICE::DELETE;
        break;
	case 'S':
	case 's':
		result = CHOICE::ISEMPTY;
		break;
    case 'A':
    case 'a':
        result = CHOICE::ADDTOFRONT;
        break;
	case 'R':
	case 'r':
		result = CHOICE::ADDTOREAR;
		break;
	case 'F':
	case 'f':
		result = CHOICE::FIND;
		break;
	case 'Q':
	case 'q':
		result = CHOICE::QUIT;
		break;
	case 'P':
	case 'p':
		result = CHOICE::PRINT;
		break;
    case '=':
        result = CHOICE::OPERATOR;
        break;
    default:
        result = CHOICE::QUIT;
        break;
	}

	return( result );
}*/
