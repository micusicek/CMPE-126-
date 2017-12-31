#include <iostream>
#include "Clock.h"

using namespace std;

int main() {
	clockType c1(15, 45, 30), c2(3, 20);  // hour, min, sec
	cout << c1;   // add whatever to beautify it
	cout << c2;
	cout << c1 + c2;
	c2 = c1 + c1;
	cout << c2;
}
