// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "BadArgument.h"
#include "HeapOverflow.h"
#include "ItemNotFound.h"

using namespace std;
using namespace cs32;

enum CHOICE {MAKEEMPTY, OCCUPIED, ISEMPTY, FINDMIN, INSERT, QUIT, PRINT, DELETEMIN };

CHOICE menu();

int main() {
	int value;
	BinaryHeap<int> h;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			h.makeEmpty();
			break;
		case ISEMPTY:
			if (h.isEmpty()) {
				cout << "heap is empty" << endl;
			}
			else {
				cout << "heap is not empty" << endl;
			}
			break;
		case OCCUPIED:
			cout << "occupied in this heap=" << h.occupied() << endl;
			break;
		case FINDMIN:
			cout << "minimum value in this heap=" << h.findMin() << endl;
			break;
		case INSERT:
			cout << "Please provide int to insert into this heap: ";
			cin  >> value; 
			h.insert( value );
			break;
		case DELETEMIN:
			cout << "the minimum element that has been deleted=";
			cout << h.deleteMin() << endl;
			break;
		case PRINT:
			h.printHeap( cout );
			cout << endl;
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

	cout << "(M)akeEmpty  I(s)Empty  (O)ccupied  (F)indMin (I)nsert (D)eleteMin (P)rint (Q)uit:" << endl;
	cin  >> choice;
	switch( choice ) {
	case 'O':
	case 'o':
		result = OCCUPIED;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'F':
	case 'f':
		result = FINDMIN;
		break;
	case 'I':
	case 'i':
		result = INSERT;
		break;
	case 'D':
	case 'd':
		result = DELETEMIN;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	}

	return( result );
}

