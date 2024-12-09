#include "main.h"
#include <iostream>
using namespace std;

int subtractDown(int n, bool debug) {
	if (debug) cout << "***SUBTRACTDOWN***" << endl;
	int out = n;
	for (int i = n - 1; i >= 0; i--) {
		out -= i;
		if (debug) cout << "out = " << out << ", n = " << n << endl;
	}
	return out;
}

int subDownRecurse(int n, bool debug) {
	if (debug) cout << endl << "***SBD RECURSE AT " << n << " ***" << endl;

	if (n == 0) {
		if (debug) cout << "exit" << endl;
		return 0;
	}

	int k = subDownRecurse(n - 1, debug);
	
	if (debug) cout << n << " recurse " << k << endl;

	if (n % 2) return n - k;
	else return n - k;
}

int subtractDownkyle(int n, bool debug) {
	if (n == 0) return 0;
	if (n > 0) return n + subtractDownkyle(-1 * (n - 1), debug);
	if (n < 0) return n + subtractDownkyle(n + 1, debug);
}

int main() {
	cout << subtractDown(5, true);
	cout << "final: " << subDownRecurse(5, true);
	cout << subtractDownkyle(10, true) << endl;
}