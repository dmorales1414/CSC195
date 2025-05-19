#include <iostream>
#include <array>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

// Calling the functions at the top to be able to use (cause of the heirarchy system))
void useArray();
void useVector();
void useList();
void useMap();


int main()
{
	useArray(); // Shows the Array
	useVector(); // Shows the Vector
	useList(); // Shows the List
	useMap(); // Shows the Map
	
}


void useArray() {
	// **Array String Container**
	array<string, 7> daysOfTheWeek = {
		"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
	};

	// Print the number of elements
	cout << "Number of elements: " << daysOfTheWeek.size() << endl;

	// Print all the days of the week, stored in the array
	cout << "Days of the week: " << endl;
	for (const string& day : daysOfTheWeek) {
		cout << day << endl;
	}

	cout << endl;
}

void useVector() {
	// **Vector Container**

	vector<int> numbers = {
		1, 2, 3, 4, 5
	};

	// Add two more integers using push_back
	numbers.push_back(6);
	numbers.push_back(10);

	// Remove the last element (in this case 10)
	numbers.pop_back();

	// Printing the contents using a loop
	cout << "Vector Contents: " << endl;
	for (int num : numbers) {
		cout << num << endl;
	}

	cout << endl;
}

void useList() {
	// **List String Container**
	list<string> fruits = {
		"Apple", "Orange", "Grapes" 
	};

	// Adding an item to the front and another to the back
	fruits.push_back("Bananas");
	fruits.push_front("Tangerine");

	// Removing a specific element in fruits
	fruits.remove("Orange"); // Removes Orange from the list


	// Iterating through the fruits list and printing all items
	cout << "All fruits: " << endl;
	for (const string& fruit : fruits) {
		cout << fruit << endl;
	}

	cout << endl;
}

void useMap() {
	// **Map String, int Container**
	map<string, int> fruitPrices;
	
	// Inserting at least 3 key value pairs
	fruitPrices["Apples"] = 10;
	fruitPrices["Bananas"] = 5;
	fruitPrices["Grapes"] = 3;
	fruitPrices["Tangerines"] = 4;

	// Accesses and updates the value for one of the fruits
	fruitPrices["Apples"] -= 3;

	// Print all key values
	cout << "Fruit Prices: " << endl;
	for (const auto& pair : fruitPrices) {
		cout << pair.first << ": " << pair.second << endl;
	}

	cout << endl;
}