#include<iostream>
#include "myString.h"

using std::cout;
using std::endl;


int main(void) {


	string a = "Anirudh is awesome";
	cout << a << endl;
	string b = "hi";
	a.stringCpy(b);
	cout << a << endl;
	return 0;
}