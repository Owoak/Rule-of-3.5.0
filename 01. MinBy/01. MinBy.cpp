#include <iostream>
#include "SmartArray.h"

using namespace std;

int main() {
	SmartArray <int> arr(5);
	arr[2] = 42;

	arr.print();

	SmartArray <int> arrB(8);
	arrB.print();
	arrB = arr;
	arr.print();
	arrB.print();

	return 0;
}