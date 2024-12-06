#include <iostream> 
#include <string> 
#include <cassert>
#include "List.h"
#include "ListNode.h"
using namespace std;
using namespace cs32;
void testone(int n)
{

    List l;
    List l1, l2;
    ListNode node;
    ListNode* otherNode;
    std::string s;


    switch (n)
    {
    case  1:
        node = ListNode("12");
        assert(node.getElement() == "12");
        assert(node.getNext() == nullptr);
        assert(node.nextIsNull());
        break;

    case  2:
        otherNode = new ListNode("13");
        node = ListNode("12");
        node.setNext(otherNode);

        assert(node.getElement() == "12");
        assert(node.getNext() == otherNode);
        assert(node.nextIsNull() == false);
        assert(otherNode->getElement() == "13");
        assert(otherNode->getNext() == nullptr);
        assert(otherNode->nextIsNull());

        delete(otherNode);
        break;

    case  3:
        assert(l.isEmpty());
        assert(l.size() == 0);

        l.makeEmpty();

        assert(l.isEmpty());
        assert(l.size() == 0);
        assert(l.get(0, s) == false);
        assert(l.get(-10, s) == false);
        assert(l.get(10, s) == false);
        break;


    case  4:
        l.addToFront("12");
        l.addToRear("13");

        assert(l.isEmpty() == false);
        //cout << l.size() << endl;
        assert(l.size() == 2);
        assert(l.get(0, s) && s == "12");
        assert(l.get(1, s) && s == "13");
        l.makeEmpty();

        assert(l.isEmpty());
        assert(l.size() == 0);
        break;

    case  5:
        l.addToFront("12");
        l.addToRear("13");
        l.addToRear("14");

        assert(l.isEmpty() == false);
        assert(l.size() == 3);
        assert(l.get(0, s) && s == "12");
        assert(l.get(1, s) && s == "13");
        assert(l.get(2, s) && s == "14");

        assert(l.findItem("14"));
        assert(l.findItem("13"));
        assert(l.findItem("12"));
        assert(l.findItem("10") == false);

        l.makeEmpty();

        assert(l.isEmpty());
        assert(l.size() == 0);
        assert(l.findItem("14") == false);
        assert(l.findItem("13") == false);
        assert(l.findItem("12") == false);
        assert(l.findItem("10") == false);
        break;

    case  6:
        l.addToFront("12");
        l.addToRear("13");
        l.addToRear("14");

        assert(l.isEmpty() == false);
        assert(l.size() == 3);
        assert(l.get(0, s) && s == "12");
        assert(l.get(1, s) && s == "13");
        assert(l.get(2, s) && s == "14");

        l.deleteItem("14");
        assert(l.size() == 2);
        assert(l.get(0, s) && s == "12");
        assert(l.get(1, s) && s == "13");
        l.deleteItem("13");
        assert(l.size() == 1);
        assert(l.get(0, s) && s == "12");
        l.deleteItem("12");
        assert(l.isEmpty());
        assert(l.findItem("14") == false);
        assert(l.findItem("13") == false);
        assert(l.findItem("12") == false);
        assert(l.findItem("10") == false);
        break;

    case  7:
        l.addToFront("12");
        l.addToRear("13");
        l.addToRear("14");

        assert(l.isEmpty() == false);
        assert(l.size() == 3);
        assert(l.get(0, s) && s == "12");
        assert(l.get(1, s) && s == "13");
        assert(l.get(2, s) && s == "14");

        l.deleteItem("12");
        assert(l.size() == 2);
        assert(l.get(0, s) && s == "13");
        assert(l.get(1, s) && s == "14");
        l.deleteItem("13");
        assert(l.size() == 1);
        assert(l.get(0, s) && s == "14");
        l.deleteItem("14");
        assert(l.isEmpty());
        assert(l.findItem("14") == false);
        assert(l.findItem("13") == false);
        assert(l.findItem("12") == false);
        assert(l.findItem("10") == false);
        break;

    case  8:
        l.addToRear("12");
        l.addToRear("13");
        l.addToRear("14");

        assert(l.isEmpty() == false);
        assert(l.size() == 3);
        assert(l.get(0, s) && s == "12");
        assert(l.get(1, s) && s == "13");
        assert(l.get(2, s) && s == "14");
        l.deleteItem("12");
        assert(l.size() == 2);
        assert(l.get(0, s) && s == "13");
        assert(l.get(1, s) && s == "14");
        l.deleteItem("13");
        assert(l.size() == 1);
        assert(l.get(0, s) && s == "14");
        l.deleteItem("14");
        assert(l.isEmpty());
        assert(l.findItem("14") == false);
        assert(l.findItem("13") == false);
        assert(l.findItem("12") == false);
        assert(l.findItem("10") == false);
        break;

    case  9:
        l.addToFront("14");
        l.addToFront("13");
        l.addToFront("12");

        assert(l.isEmpty() == false);
        assert(l.size() == 3);
        assert(l.get(0, s) && s == "12");
        assert(l.get(1, s) && s == "13");
        assert(l.get(2, s) && s == "14");
        l.deleteItem("12");
        assert(l.size() == 2);
        assert(l.get(0, s) && s == "13");
        assert(l.get(1, s) && s == "14");
        l.deleteItem("13");
        assert(l.size() == 1);
        assert(l.get(0, s) && s == "14");
        l.deleteItem("14");
        assert(l.isEmpty());
        assert(l.findItem("14") == false);
        assert(l.findItem("13") == false);
        assert(l.findItem("12") == false);
        assert(l.findItem("10") == false);
        break;

    case  10:
        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");

        l2 = l1;

        assert(l1.isEmpty() == false);
        assert(l1.size() == 3);
        assert(l1.get(0, s) && s == "12");
        assert(l1.get(1, s) && s == "13");
        assert(l1.get(2, s) && s == "14");
        assert(l1.findItem("14"));
        assert(l1.findItem("13"));
        assert(l1.findItem("12"));
        assert(l1.findItem("10") == false);

        assert(l2.isEmpty() == false);
        assert(l2.size() == 3);
        assert(l2.get(0, s) && s == "12");
        assert(l2.get(1, s) && s == "13");
        assert(l2.get(2, s) && s == "14");
        assert(l2.findItem("14"));
        assert(l2.findItem("13"));
        assert(l2.findItem("12"));
        assert(l2.findItem("10") == false);

        l1.makeEmpty();

        assert(l1.isEmpty());
        assert(l1.size() == 0);
        assert(l1.findItem("14") == false);
        assert(l1.findItem("13") == false);
        assert(l1.findItem("12") == false);
        assert(l1.findItem("10") == false);

        assert(l2.isEmpty() == false);
        assert(l2.size() == 3);
        assert(l2.get(0, s) && s == "12");
        assert(l2.get(1, s) && s == "13");
        assert(l2.get(2, s) && s == "14");
        assert(l2.findItem("14"));
        assert(l2.findItem("13"));
        assert(l2.findItem("12"));
        assert(l2.findItem("10") == false);
        break;

    case 11:
        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");

        l2 = l1;

        assert(l1.isEmpty() == false);
        assert(l1.size() == 3);
        assert(l1.get(0, s) && s == "12");
        assert(l1.get(1, s) && s == "13");
        assert(l1.get(2, s) && s == "14");
        assert(l1.findItem("14"));
        assert(l1.findItem("13"));
        assert(l1.findItem("12"));
        assert(l1.findItem("10") == false);

        assert(l2.isEmpty() == false);
        assert(l2.size() == 3);
        assert(l2.get(0, s) && s == "12");
        assert(l2.get(1, s) && s == "13");
        assert(l2.get(2, s) && s == "14");
        assert(l2.findItem("14"));
        assert(l2.findItem("13"));
        assert(l2.findItem("12"));
        assert(l2.findItem("10") == false);

        l1.makeEmpty();

        assert(l1.isEmpty());
        assert(l1.size() == 0);
        assert(l1.findItem("14") == false);
        assert(l1.findItem("13") == false);
        assert(l1.findItem("12") == false);
        assert(l1.findItem("10") == false);

        assert(l2.isEmpty() == false);
        assert(l2.size() == 3);
        assert(l2.get(0, s) && s == "12");
        assert(l2.get(1, s) && s == "13");
        assert(l2.get(2, s) && s == "14");
        assert(l2.findItem("14"));
        assert(l2.findItem("13"));
        assert(l2.findItem("12"));
        assert(l2.findItem("10") == false);
        break;

    case 12:
        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");

        l2 = List(l1);

        assert(l1.isEmpty() == false);
        assert(l1.size() == 3);
        assert(l1.get(0, s) && s == "12");
        assert(l1.get(1, s) && s == "13");
        assert(l1.get(2, s) && s == "14");

        assert(l1.count("12") == 1);
        assert(l1.count("13") == 1);
        assert(l1.count("14") == 1);
        assert(l1.count("15") == 0);
        assert(l1.count("16") == 0);
        assert(l1.count("17") == 0);
        break;

    case 13:
        assert(l1.max() == "");

        l1.addToFront("12");
        assert(l1.max() == "12");
        l1.addToRear("13");
        assert(l1.max() == "13");
        l1.addToRear("14");
        assert(l1.max() == "14");
        break;

    case 14:
        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");

        l2 = List(l1);

        assert(l1.isEmpty() == false);
        assert(l1.size() == 3);
        assert(l1.get(0, s) && s == "12");
        assert(l1.get(1, s) && s == "13");
        assert(l1.get(2, s) && s == "14");

        assert(l1.strip("15") == 0);
        assert(l1.size() == 3);
        assert(l1.strip("16") == 0);
        assert(l1.size() == 3);
        assert(l1.strip("17") == 0);
        assert(l1.size() == 3);
        assert(l1.strip("12") == 1);
        assert(l1.size() == 2);
        assert(l1.get(0, s) && s == "13");
        assert(l1.get(1, s) && s == "14");
        assert(l1.strip("14") == 1);
        assert(l1.size() == 1);
        assert(l1.get(0, s) && s == "13");
        assert(l1.strip("13") == 1);
        assert(l1.size() == 0);
        break;

    case 15:
        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");

        l2 = List(l1);

        assert(l2.isEmpty() == false);
        assert(l2.size() == 3);
        assert(l2.get(0, s) && s == "12");
        assert(l2.get(1, s) && s == "13");
        assert(l2.get(2, s) && s == "14");

        assert(l1.allMoreThan("2") == false);
        assert(l1.allMoreThan("12") == false);
        assert(l1.allMoreThan("11") == true);

        break;

    case 16:
        assert(l1.max() == "");

        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");

        assert(l1.max() == "14");
        l1.deleteItem("12");
        assert(l1.max() == "14");
        l1.deleteItem("13");
        assert(l1.max() == "14");

        l1.deleteItem("14");

        assert(l1.max() == "");
        break;

    case 17:
        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");
        l1.addToRear("12");
        l1.addToRear("13");
        l1.addToRear("14");

        assert(l1.isEmpty() == false);
        assert(l1.size() == 6);
        assert(l1.get(0, s) && s == "12");
        assert(l1.get(1, s) && s == "13");
        assert(l1.get(2, s) && s == "14");
        assert(l1.get(3, s) && s == "12");
        assert(l1.get(4, s) && s == "13");
        assert(l1.get(5, s) && s == "14");

        assert(l1.count("12") == 2);
        assert(l1.count("13") == 2);
        assert(l1.count("14") == 2);
        assert(l1.count("15") == 0);
        assert(l1.count("16") == 0);
        assert(l1.count("17") == 0);
        break;

    case 18:
        l1.addToFront("12");
        l1.addToRear("13");
        l1.addToRear("14");
        l1.addToRear("12");
        l1.addToRear("13");
        l1.addToRear("14");
        assert(l1.isEmpty() == false);
        assert(l1.size() == 6);
        assert(l1.get(0, s) && s == "12");
        assert(l1.get(1, s) && s == "13");
        assert(l1.get(2, s) && s == "14");
        assert(l1.get(3, s) && s == "12");
        assert(l1.get(4, s) && s == "13");
        assert(l1.get(5, s) && s == "14");

        assert(l1.size() == 6);
        assert(l1.strip("12") == 2);
        assert(l1.size() == 4);
        assert(l1.get(0, s) && s == "13");
        assert(l1.get(1, s) && s == "14");
        assert(l1.get(2, s) && s == "13");
        assert(l1.get(3, s) && s == "14");
        assert(l1.strip("14") == 2);
        assert(l1.size() == 2);
        assert(l1.get(0, s) && s == "13");
        assert(l1.get(1, s) && s == "13");
        assert(l1.strip("13") == 2);
        assert(l1.size() == 0);
        break;

    case 19:
        l1.addToRear("12");
        l1.addToRear("13");
        l1.addToRear("14");
        l1.addToRear("12");
        l1.addToRear("13");
        l1.addToRear("14");

        assert(l1.isEmpty() == false);
        assert(l1.size() == 6);
        assert(l1.get(0, s) && s == "12");
        assert(l1.get(1, s) && s == "13");
        assert(l1.get(2, s) && s == "14");
        assert(l1.get(3, s) && s == "12");
        assert(l1.get(4, s) && s == "13");
        assert(l1.get(5, s) && s == "14");

        assert(l1.allMoreThan("2") == false);
        assert(l1.allMoreThan("12") == false);
        assert(l1.allMoreThan("11") == true);
        break;

    case 20:
        l1.addToFront("12");
        l1.addToFront("13");
        l1.addToFront("14");
        l1.addToFront("15");
        l1.addToRear("16");
        l1.addToRear("17");
        cout << l1.size();
        cout << l1.printItems();

        assert(l1.isEmpty() == false); 
        
        assert(l1.size() == 6);
        assert(l1.get(0, s) && s == "15");
        assert(l1.get(1, s) && s == "14");
        assert(l1.get(2, s) && s == "13");
        assert(l1.get(3, s) && s == "12");
        assert(l1.get(4, s) && s == "16");
        assert(l1.get(5, s) && s == "17");

        assert(l1.max() == "17");

        l1.deleteItem("17");

        assert(l1.max() == "16");

        l1.deleteItem("16");
        assert(l1.max() == "15");

        l1.deleteItem("15");
        assert(l1.max() == "14");

        l1.deleteItem("14");
        assert(l1.max() == "13");

        l1.deleteItem("13");
        assert(l1.max() == "12");

        l1.deleteItem("12");
        assert(l1.size() == 0);
        break;

    default:
        cout << "Bad argument";
        break;
    }
}

int main() {
    int x = 1;
    if (x == 0) {

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
    if (x == 1) {
        while (1) {
            cout << "Enter test number: ";
            int n;
            cin >> n;
            testone(n);
            cout << "Passed!" << endl;
        }
    }
}




