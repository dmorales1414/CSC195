#include <iostream>
#include <array>
#include <list>
using namespace std;

int main() 
{
	// Using built-in array

	int numbers[] = { 1,2,3,4,5 };

	cout << "Third Element: " << numbers[2] << endl;
	// Undefined  behaviour - returns random value form accessed memory
	cout << "Out of bound element: " << numbers[7] << endl;

	numbers[1] = 25;

	// Iterrating through array
	cout << "All elements: ";
	for (int i = 0; i < 5; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	int size = sizeof(numbers) / sizeof(int);
	// Numbers.size() -- limited functionality of built-in array

	cout << "First element: " << numbers << endl;

	// Fixed length at compile time
	// No built-in methods for common operations
	// Fast access to elements, easy to set-up

	// STL array
	cout << endl << "STL Array" << endl;

	array<string, 4> animals = { "Mouse", "Tiger", "Snake", "Penguin" };

	cout << "Third Element: " << animals[2] << endl;

	cout << "Size of array: " << animals.size() << endl;

	// Iterating through array with for each
	cout << "All Elements: ";
	for (string ani : animals)
	{
		cout << ani << " ";
	}
	cout << endl;

	// cout << "Out of bound element: " << (Unfinished Couldn't get the rest of the notes, though it was only 3 lines)

	//cout << "Last element: " << animals.end() << endl;
	// Fixed size with STL algorithm compatibility
	// out of exception

	// STL List
	cout << "STL List" << endl;

	list<float> height = { 5.6f, 6.3f, 4.2f };

	cout << "Size of List : " << height.size() << endl;

	height.push_front(2.3f);
	height.push_back(7.3f);

	height.sort();

	// Iterating through list
	cout << "All elements: ";
	for (float hei : height) {
		cout << hei << " ";
	}
	cout << endl;

	// Resizeable Container - helpful for frequent & efficient insertion & deletion
	// Higher memory overhead (pointer for each element)
	// Works well iterators and other STL compability
}