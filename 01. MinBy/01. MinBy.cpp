#include <iostream>
#include "SmartArray.h"

using namespace std;

int main() {
	//SmartArray <int> arrB(arr);
	SmartArray <int> arrB(8);
	arrB[2] = 3;
	arrB[7] = 8;
	arrB.print();

	arrB.resize(5);
	arrB.print();

	return 0;
}