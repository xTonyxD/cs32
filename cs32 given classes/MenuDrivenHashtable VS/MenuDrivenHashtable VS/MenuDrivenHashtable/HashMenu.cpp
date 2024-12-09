// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Hashtable.cpp"
#include "Hashtable.h"
#include "HashtableNode.cpp"
#include "HashtableNode.h"
#include "Random.h"
#include "ItemNotFound.h"
#include "DuplicateItem.h"

using namespace std;
using namespace cs32;

enum CHOICE {LINEAR, QUADRATIC, MAKEEMPTY, INSERT, ISEMPTY, REMOVE, FIND, QUIT, PRINT, STATS, RESETSTATS, GENERATESTATS, FILLTABLE };

CHOICE menu();

int main() {
	int value;
	Hashtable<int> ht = Hashtable<int>( 101 );
	cout << "hashtable size is 101!" << endl;
	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case LINEAR:
			cout << "clearing table -- linear collision resolution" << endl;
			ht = Hashtable<int>( 101, true );
			break;
		case QUADRATIC:
			cout << "clearing table -- quadratic collision resolution" << endl;
			ht = Hashtable<int>( 101, false );
			break;
		case MAKEEMPTY:
			ht.makeEmpty();
			break;
		case ISEMPTY:
			if (ht.isEmpty()) {
				cout << "hashtable is empty" << endl;
			}
			else {
				cout << "hashtable is not empty" << endl;
			}
			break;
		case REMOVE:
			try {
				cout << "Enter the value to remove: ";
				cin  >> value;
				ht.remove( value );
			} catch( ItemNotFound &  ) {
				cout << "you silly! this value wasn't in the table" << endl;			
			}
			break;
		case INSERT:
			try {
				cout << "Enter the value to insert: ";
				cin  >> value;
				ht.insert( value );
			} catch( DuplicateItem &  ) {
				cout << "you silly! this value wasn't in the table" << endl;			
			} catch( TableFull &  ) {
				cout << "you silly! the table is completely full!" << endl;
			}
			break;
		case FIND:
			try {
				cout << "Enter the value to find: ";
				cin  >> value;
				ht.find( value );
				cout << value << " was found in the table" << endl;
			} catch( ItemNotFound &  ) {
				cout << "you silly! this value wasn't in the table" << endl;			
			}
			break;
		case PRINT:
			ht.printHashTable( cout );
			break;
		case STATS:
			ht.printStats( cout );
			break;
		case RESETSTATS:
			ht.resetStats();
			break;
		case GENERATESTATS:
			ht.resetStats();
			ht.generateStats();
			ht.printStats( cout );
			break;
		case FILLTABLE:
			cout << "provide table fill percentage [1-100]:";
			cin  >> value;
			if (value < 1 || value > 100) {
				cout << "Invalid value.... please try again" << endl;
			}
			else if (value > 90) {
				cout << "Random number selection scheme does not\nreally support more than a 90% full table." << endl;
				cout << "Please try again..." << endl;
			}
			else {
				cout << "clearing table" << endl;
				ht.makeEmpty();
				Random r( 10000 );
				int i = 0;
                cout << "filling table" << endl;
				while( i < value ) {
					int insertValue = r.random();
					// only insert if it can't be found...
					try {
						ht.find( insertValue );
					} catch( ItemNotFound &  ) {
						ht.insert( insertValue );
						i++;
					}
				}
			}
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

	cout << "(L)inear Qua(D)ratic (M)akeEmpty I(s)Empty (I)nsert (R)emove (F)ind (P)rint s(T)ats resetSt(A)ts (G)enerateStats FillTa(B)le (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'I':
	case 'i':
		result = INSERT;
		break;
	case 'R':
	case 'r':
		result = REMOVE;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case 'F':
	case 'f':
		result = FIND;
		break;
	case 'T':
	case 't':
		result = STATS;
		break;
	case 'A':
	case 'a':
		result = RESETSTATS;
		break;
	case 'L':
	case 'l':
		result = LINEAR;
		break;
	case 'D':
	case 'd':
		result = QUADRATIC;
		break;
	case 'G':
	case 'g':
		result = GENERATESTATS;
		break;
	case 'B':
	case 'b':
		result = FILLTABLE;
		break;
	}

	return( result );
}

