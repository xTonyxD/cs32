#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
using namespace std;


void print (int elem)
{
    cout << elem << ' ';
}

void printx (int* elem)
{
    cout << *elem << ' ';
}

int main()
{
list< int > l;
size_t ttt = l.size( );
l.empty();
l.clear();

queue< int > q;
size_t uuu = q.size( );
q.empty();
q.push( 1 );
q.pop(  );


std::vector< int > v;
v.push_back( 123 );
v[ 0 ] = 42;
cout << "size = " << v.size() << endl;
cout << "capacity = " << v.capacity() << endl;
cout << v[ 3 ];
v[ 4 ] = 1971;
cout << v[ 77 ];
cout << v.back( );
cout << "size = " << v.size() << endl;
cout << "capacity = " << v.capacity() << endl;

l.clear();
int i(1), j(2), k(3);

l.push_back( i );
l.push_back( j );
l.push_back( k );
 for_each (l.begin(), l.end(),    // range
              print);                      // operation
    cout << endl;

k = 12;
 for_each (l.begin(), l.end(),    // range
              print);                      // operation
    cout << endl;


int * pI = new int(1);
int * pJ = new int(2);
int * pK = new int(3);

std::list< int * > ll;

ll.push_back( pI );
ll.push_back( pJ );
ll.push_back( pK );
 for_each (ll.begin(), ll.end(),    // range
              printx);                      // operation
    cout << endl;

*pK = 12;
 for_each (ll.begin(), ll.end(),    // range
              printx);                      // operation

delete pI;
delete pJ;
delete pK;


std::list< int >::iterator it = find( l.begin(), l.end(), 100 );
*it = 200;

    list<int> v2( 5 );
v2.push_back( 1 );
v2.push_back( 5 );
v2.push_back( 10 );
v2.push_back( 15 );
v2.push_back( 20 );

 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (list< int >::iterator it = v2.begin(); it != v2.end(); it++)
        if ((*it) == 5)
            v2.push_back(-1);
 
    for (list< int >::iterator it = v2.begin(); it != v2.end(); it++)
        cout << (*it) << " ";

v2.clear();
//v2.resize( 5 );
cout << "AA" << endl;
v2.push_back( 1 );
v2.push_back( 5 );
v2.push_back( 10 );
v2.push_back( 15 );
v2.push_back( 20 );

cout << "BB" << endl;
 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (list< int >::iterator it = v2.begin(); it != v2.end(); it++)
        if ((*it) == 5)
        {    v2.push_back(-1);
	     break;
	}
 
cout << "CC" << endl;
    for (list< int >::iterator it = v2.begin(); it != v2.end(); it++)
        cout << (*it) << " ";


v2.push_back( 5 );
v2.push_back( 5 );

cout << "DD" << endl;
    for (list< int >::iterator it = v2.begin(); it != v2.end(); it++)
        cout << (*it) << " ";


list< int >::iterator iter = v2.begin();
while (iter != v2.end()) {
  if (*iter == 5) {
    iter = v2.erase(iter); // note that erase() returns the next iterator
  } else {
    ++iter;
  }
}

cout << "EE" << endl;
    for (list< int >::iterator it = v2.begin(); it != v2.end(); it++)
        cout << (*it) << " ";

cout << "FF" << endl;

std::set< int > s;
s.insert( 12 );
s.insert( 5 );
s.insert( 6 );
s.insert( 100 );
s.insert( 5 );
    for (set< int >::iterator it = s.begin(); it != s.end(); it++)
        cout << (*it) << " ";

return( 0 );
}
