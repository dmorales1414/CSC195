#include <iostream>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main() {
	vector<Shape*> shapes;

	// Creates and adds the Circle
	Circle* c = new Circle(1.0f);
	c->SetRadius(3.0f); // To point (pointer) at the setRadius
	shapes.push_back(c);
	
	// Creates and adds the Rectangle
	Rectangle* r = new Rectangle(4.0f, 5.0f);
	shapes.push_back(r);

	// A for each loop for all the areas as the other for loop would be out of bounds
	for (Shape* shape : shapes)
	{
		cout << "Area: " << shape->Area() << endl;

		// TODO: If shape is a circle, print radius
		Circle* circle = dynamic_cast<Circle*>(shape);
		if (circle) 
		{
			cout << "Radius: " << circle->GetRadius() << endl;
		}
	}
	// FIXME: Getting memory leak! Delete all shapes.
	// Cleanup for each loop
	for (Shape* shape : shapes)
	{
		delete shape; // Needs to delete previous shapes to not cause memory leaks
	}


	return 0;
}