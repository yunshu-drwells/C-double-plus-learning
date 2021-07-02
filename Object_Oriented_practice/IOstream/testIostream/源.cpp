#include <iostream>
using namespace std;

class Test {
public:
	friend ostream& operator<<(ostream& os, const Test& x);
	Test(int i = 0): i(i) {
	}
//protected:
//private:
	Test(const Test &x) {
		i = x.i;
	}
private:
	int i;
};
ostream& operator<<(ostream& os, const Test& x) {
	os << x.i;
	return os;
}

int main() {
	Test t1(8);
	cout << t1 << endl;
	Test t2(t1);
	cout << t1 << endl;
	return 0;
}