// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Stack.h"
#include "EmptyStack.h"
#include "StackNode.h"

using namespace std;
using namespace cs32;

enum CHOICE {MAKEEMPTY, PUSH, ISEMPTY, POP, TOP, TOPANDPOP, QUIT, PRINT, OPERATOR };

CHOICE menu();

int main() {
	std::string value;
	Stack stack;
    Stack stack2;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			stack.makeEmpty();
			break;
		case ISEMPTY:
			if (stack.isEmpty()) {
				cout << "stack is empty" << endl;
			}
			else {
				cout << "stack is not empty" << endl;
			}
			break;
		case TOP:
			try {
				value = stack.top();
				cout << "Here's the value on top: ";
				cout << value << endl;
			} catch( EmptyStack &  ) {
				cout << "You silly... don't try topping an empty stack!" << endl;			
			}
			break;
		case POP:
			try {
				stack.pop();
			} catch( EmptyStack &  ) {
				cout << "You silly... don't try popping an empty stack!" << endl;
			}
			break;
		case PUSH:
			cout << "Please provide a string to push: ";
			cin  >> value; 
			stack.push( value );
			break;
		case TOPANDPOP:
			try {
				value = stack.topAndPop();
				cout << "Here's the value on top that got popped: ";
				cout << value << endl;
			} catch( EmptyStack &  ) {
				cout << "You silly... don't try topAndPopping an empty stack!" << endl;
			}
			break;
		case PRINT:
			cout << stack.printStack(  );
			cout << endl;
			break;
        case OPERATOR:
            stack2 = stack;
            cout << "second stack now:" << endl;
            cout << stack2.printStack( );
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
	cout << "(M)akeEmpty I(s)Empty p(U)sh p(O)p (T)op top(A)ndpop (=) (P)rint (Q)uit: " << endl;
	cin  >> choice;
	switch( choice.at( 0 ) ) {
	case 'A':
	case 'a':
		result = TOPANDPOP;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'U':
	case 'u':
		result = PUSH;
		break;
	case 'O':
	case 'o':
		result = POP;
		break;
	case 'T':
	case 't':
		result = TOP;
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
	Stack s1;
	Stack s2;
	cout << "making s1" << endl;
	s1.push( "1" );
	s1.push( "2" );
	cout << "print s1" << endl;
	cout << s1.printStack(  );
	cout << endl;

	cout << "s2 = s1" << endl;

	s2 = s1;
	cout << "print s2" << endl;
	cout << s2.printStack(  );
	cout << endl;

	s1.pop();
	cout << "pop s1" << endl;

	cout << "print s2" << endl;
	cout << s2.printStack(  );
	cout << endl;

	cout << "print s1" << endl;
	cout << s1.printStack(  );
	cout << endl;

}
