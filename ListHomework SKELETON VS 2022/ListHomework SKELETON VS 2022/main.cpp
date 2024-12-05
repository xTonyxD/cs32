#include "List.h"
#include "ListNode.h"
#include <string>
using namespace cs32;

int main() {
	using namespace std;

	List l1;
	for (int i = 0; i < 10; i++) {
		l1.addToFront(std::to_string(i));
	}

	cout << l1.printItems();
	cout << l1.size() << endl; 

	List empty;
	cout << empty.size() << endl;

	string str = "";
	cout << l1.get(5, str) << ", " << str << endl;
	cout << empty.get(5, str) << ", " << str << endl;


	cout << "testing max method" << endl;
	List l3;
	l3.addToFront("Hawkeye");
	l3.addToFront("Thor");
	l3.addToFront("Hulk");
	l3.addToFront("Black Widow");
	l3.addToFront("Iron Man");
	l3.addToFront("Captain America");

	cout << l3.max() << endl;
	cout << "l1: " << l1.printItems() << endl;
	cout << l1.max() << endl;
		
	cout << "***************testing allmorethan***************" << endl;
	cout << l3.allMoreThan("Iron Man") << endl;
	cout << l3.allMoreThan("Thor") << endl;
	cout << l3.allMoreThan("0") << endl;


	cout << "***************testing strip***************" << endl;
	l3.addToFront("Black Widow");
	l3.addToFront("Iron Man");
	l3.addToFront("Captain America");
	cout << l3.printItems() << endl;

	cout << l3.strip("Iron Man") << " stripped, now: ";
	cout << l3.printItems() << endl;

	cout << "***************testing count***************" << endl;
	cout << l3.count("Thor") << endl;
	cout << l3.count("peanits") << endl;

	cout << "***************testing weird shit***************" << endl;

	bool answer = true;
	List list;
	string s = "";
	list.addToFront("a");
	list.addToFront("b");
	list.addToFront("c");
	list.addToFront("d");
	list.addToFront("c");
	cout << list.strip("c") << " || " << list.printItems() << endl;
	answer = (list.get(0, s) && s == "d");
	answer = answer && (list.get(1, s) && s == "b");
	cout << answer << endl;

	answer = answer && (list.get(2, s) && s == "a");
	cout << answer << endl;
}