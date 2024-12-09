// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Queue.h"
#include "EmptyQueue.h"
#include "QueueNode.h"


using namespace std;
using namespace cs32;

enum CHOICE {MAKEEMPTY, ENQUEUE, ISEMPTY, DEQUEUE, GETFRONT, QUIT, PRINT, OPERATOR };

CHOICE menu();

int main() {
	string value;
	Queue q;
    Queue q2;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			q.makeEmpty();
			break;
		case ISEMPTY:
			if (q.isEmpty()) {
				cout << "queue is empty" << endl;
			}
			else {
				cout << "queue is not empty" << endl;
			}
			break;
		case DEQUEUE:
			try {
				value = q.dequeue();
				cout << "Here's the value dequeued: ";
				cout << value << endl;
			} catch( EmptyQueue &  ) {
				cout << "You silly... don't try dequeueing an empty queue!" << endl;			
			}
			break;
		case GETFRONT:
			try {
				value = q.getFront();
				cout << "Here's the value returned from getFront: ";
				cout << value << endl;
			} catch( EmptyQueue &  ) {
				cout << "You silly... don't try gettingFront an empty queue!" << endl;
			}
			break;
		case ENQUEUE:
			cout << "Please provide int to enqueue: ";
			cin  >> value; 
			q.enqueue( value );
			break;
		case PRINT:
			cout << q.printQueue(  );
			cout << endl;
			break;
        case OPERATOR:
            q2 = q;
            cout << "second queue now:" << endl;
            cout << q2.printQueue(  );
            cout << endl;
            break;
        case QUIT:
            break;
        default:
            break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

CHOICE menu() {
    string choice;
	CHOICE result;

	cout << "(M)akeEmpty I(s)Empty (E)nqueue (D)equeue (G)etFront (P)rint (=) (Q)uit: " << endl;
	cin  >> choice;
	switch( choice.at( 0 ) ) {
	case 'E':
	case 'e':
		result = ENQUEUE;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'D':
	case 'd':
		result = DEQUEUE;
		break;
	case 'G':
	case 'g':
		result = GETFRONT;
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
    default:
        result = QUIT;
        break;
	}

	return( result );
}

void sample() {
	Queue q1;
	Queue q2;
	cout << "making q1" << endl;
	q1.enqueue( "1" );
	q1.enqueue( "2" );
	cout << "print q1" << endl;
	cout << q1.printQueue(  );
	cout << endl;

	cout << "q2 = q1" << endl;

	q2 = q1;
	cout << "print q2" << endl;
	cout << q2.printQueue(  );
	cout << endl;

	q1.dequeue();
	cout << "dequeue q1" << endl;

	cout << "print q2" << endl;
    cout << q2.printQueue(  );
	cout << endl;

	cout << "print q1" << endl;
    cout << q1.printQueue(  );
	cout << endl;

}
