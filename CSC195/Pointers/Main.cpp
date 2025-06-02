#include <iostream>
using namespace std;

int main()
{
	int a[] = { 1,2,3,4,5 };

	int* p = a; // int* p = &a[0]


	cout << p << endl;
	// pointer arithmatic
	p++;

	cout << *p << endl;
}