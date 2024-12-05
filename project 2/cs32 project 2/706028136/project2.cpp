#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
	//cout << n;
	//if it's power of 4, eventually u get 4/4 and that is 1 so boom we can get out; also doing it this way catches the case where n = 1
	if (n == 1 || n == 0) {
		//cout << "valid" << endl;
		return true;
	}
	else if (n < 0) {
		return false;
	}

	//check if cleanly divisible without using modulo;
	//if it is cleanly divisible, this'll return true
	//if not, n/4 will give some decimal thats immediately floor()ed and multiplying by 4 won't bring us back to n
	if (n == (n / 4) * 4) {
		//cout << ", divisible" << endl;
		return isPowerOfFour(n / 4);
	}
	else {
		//cout << "break" << endl;
		return false;
	}
}

int count11s(std::string data) {
	//if < 2 literally impossible to have a 11 so just exit
	if (data.length() < 2) return 0;

	//if found a 11, cut it out, add 1, and move on
	if (data.substr(0, 2) == "11") {
		return 1 + count11s(data.substr(2));
	}
	//chop off 1 letter from front and keep going
	else {
		return count11s(data.substr(1));
	}
}

string changexy(std::string data) {
	//empty string case
	if (data.length() < 1) {
		return "";
	} else if (data.length() == 1) {
		if (data == "x") return "y";
		return data;
	}

	//cout << data << endl;

	//if found an x, cut it out, change it to a y, and recurse on the rest of the thing
	if (data.substr(0, 1) == "x") {
		return "y" + changexy(data.substr(1));
	}
	//recurse on rest of string
	else {
		
		return data.substr(0, 1) + changexy(data.substr(1));
	}
}

bool multiplesOfOneAnother(int a, int b) {
	//cout << "a: " << a << "b: " << b << endl;
	//if somehow next condition doesn't fail??? weird thing, this apparently just doesn't work because when i'm iterating i still go below 0
	if (a <= 0 || b <= 0) {
		return false;
	}
	//else if ((a == 1 && b != 1) || (a != 1 && b == 1)) return false;
	//if it would switch 'polarities' i.e. if it starts that a>b but after recursing it would be b>a it gets out because that means that they're not compatible
	//probably an easier way to do this
	else if (((a - b) * (a - b - b) < 0) || (b - a) * (b - a - a) < 0) {
		return false;
	}
	//confirmed that multiple exists
	else if (a == b) {
		return true;
	}
	else {
		return multiplesOfOneAnother(a - b, b) || multiplesOfOneAnother(a, b - a);
	}
}

int main() {
	
	cout << "test 16: " << isPowerOfFour(16) << endl;
	cout << "test 324: " << isPowerOfFour(324) << endl;
	cout << "test 1: " << isPowerOfFour(1) << endl;
	cout << "test 0: " << isPowerOfFour(0) << endl;
	cout << "test 12: " << isPowerOfFour(12) << endl;
	cout << "test 28: " << isPowerOfFour(28) << endl;
	cout << "test 19: " << isPowerOfFour(19) << endl;
	cout << "test -16: " << isPowerOfFour(-16) << endl;
	cout << "test -28: " << isPowerOfFour(-28) << endl;
	cout << "test 4^4: " << isPowerOfFour(4*4*4*4) << endl;

	cout << "test 11: " << count11s("11") << endl;
	cout << "test 1111: " << count11s("1111") << endl;
	cout << "test 11111: " << count11s("11111") << endl;
	cout << "test 11assdaf11: " << count11s("11assdaf11") << endl;
	cout << "test 1d1d1d1d1d: " << count11s("1d1d1d1d1d") << endl;
	cout << "test 11dasdf11das11: " << count11s("11dasdf11das11") << endl;
	cout << "test asdfasf11sfaad: " << count11s("asdfasf11sfaad") << endl;
	cout << "test 114143141411114144431: " << count11s("114143141411114144431") << endl;
	cout << "test 1: " << count11s("1") << endl;
	cout << "test empty string: " << count11s("") << endl;

	cout << "test xx: " << changexy("xx") << endl;
	cout << "test yy: " << changexy("yy") << endl;
	cout << "test asdgajlksdsjkxdzlkxcjdbfagdkflfsdnjfdb: " << changexy("asdgajlksdsjkxdzlkxcjdbfagdkflfsdnjfdb") << endl;
	cout << "test xxxxxxxxxxxxxxxxxxxxxxxxxxxxx: " << changexy("xxxxxxxxxxxxxxxxxxxxxxxxxxxxx") << endl;
	cout << "test empty string: " << changexy("") << endl;
	cout << "test x: " << changexy("x") << endl;
	cout << "test asdlkmxzlcxdadslkxklclosiadskxlsdojixckdsxlkdfakslx: " << changexy("asdlkmxzlcxdadslkxklclosiadskxlsdojixckdsxlkdfakslx") << endl;
	cout << "test xx x x  x xxxxxddsafkdxdx xdxd ddx : " << changexy("xx x x  x xxxxxddsafkdxdx xdxd ddx ") << endl;

	cout << "test 5, 25: " << multiplesOfOneAnother(5, 25) << endl;
	cout << "test 100, 25: " << multiplesOfOneAnother(100, 25) << endl;
	cout << "test 3, 25: " << multiplesOfOneAnother(3, 25) << endl;
	cout << "test 3, 19: " << multiplesOfOneAnother(3, 19) << endl;
	cout << "test 25, 3: " << multiplesOfOneAnother(25, 3) << endl;
	cout << "test 1341, 12: " << multiplesOfOneAnother(1341, 12) << endl;
	cout << "test 5, 5: " << multiplesOfOneAnother(5, 5) << endl;
	cout << "test 15, 4: " << multiplesOfOneAnother(15, 4) << endl;
	cout << "test 5, 4: " << multiplesOfOneAnother(5, 4) << endl;
	cout << "test 4, 5: " << multiplesOfOneAnother(4, 5) << endl;
	cout << "test 0, 0: " << multiplesOfOneAnother(0, 0) << endl;
	cout << "test 0, 5: " << multiplesOfOneAnother(0, 5) << endl;
	cout << "test 4, 0: " << multiplesOfOneAnother(4, 0) << endl;
	cout << "test 318, 317: " << multiplesOfOneAnother(318, 317) << endl;




}
