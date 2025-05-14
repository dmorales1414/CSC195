// Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; // Once this is added, its not necessary to add std at the beginning of every cin, cout, etc.

void set(int& i) {
    i = 123;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapper(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i1 = 10;
    int i2 = 20;

    set(i1); // Gives 123 instead of 10 because its referenced


    //int& r = i1; // referencing i1

    int& r = i1; // reference once declared NEEDS to be assigned to a variable

    // r = 30;

    //set(i1);

    int* p = nullptr; // pointer can be declared and point to nothing
    p = &i2;

    swap(i1, i2);

    cout << "i1: " << i1 << endl;
    cout << "i2: " << i2 << endl;
    cout << "Address i2: " << &i2 << endl;
    cout << "Address r: " << &r << endl;
    cout << "Value p: " << p << endl;
    cout << "Dereference p: " << *p << endl;
    cout << "Address p: " << &p << endl;
}
