#include <iostream>
#include "SmartArray.h"

using namespace std;

int main() {
	//SmartArray <int> arrB(arr);
	SmartArray <int> arrB(8);
	arrB[2] = 3;
	arrB[7] = 8;
	for (auto it = arrB.begin(); it != arrB.end(); ++it) {
		cout << *it;
	}

	return 0;
}