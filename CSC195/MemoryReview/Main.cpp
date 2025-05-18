#include <iostream>
using namespace std;
struct Person 
{
char name[32];
int id;
};


// **Reference Parameter Functions**
void square(int& i) {
	i = i * i;
}

// **Pointer Parameter Functions**
void Double(int* i) {
	*i = *i * 2;
}

int main()
{
	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	int intVariable = 3;

	// declare a int reference and set it to the int variable above
	int& intReference = intVariable;
	
	// output the int variable
	cout << "intVariable: " << intVariable << endl;

	// set the int reference to some number
	intReference = 8;

	// output the int variable
	cout << "intReference: " << intVariable << endl;
	
	// what happened to the int variable when the reference was changed? (insert answer)
	//			It would seem that by printing the intVariable to the terminal before setting a number to the alias, it
	//			it would use the original number that was used, but by setting a number to the alias (intReference), it would
	//			instead use that number, in other words intReference is just another name for intVariable and change the variable
	//			directly, since both refer to the same memory location. Therefore it will use
	//			8 instead of 4, when setting a number to the reference because it changes it directly.
		
	// output the address of the int variable
	cout << "intVariable Adress: " << &intVariable << endl;

	// output the address of the int reference
	cout << "intReference Address: " << &intReference << endl;
	
	// are the addresses the same or different? (insert answer)
	//			They are using the same address as referencing changes the value directly 
	//			because it uses the same address



	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	square(intVariable);

	// output the int variable to the console
	cout << "square function: " << intVariable << endl;
	//			[Response] Gives us 8 without the function referencing, which is what we already have as
	//			we previously referenced, the number didn't change as if the function wasn't used

	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	
	
	
	// ** POINTER VARIABLE **
	//
	// declare an int pointer, set it to nullptr (it points to nothing)
	int* intPointer = nullptr;
	
	// set the int pointer to the address of the int variable created in the REFERENCE section
	intPointer = &intVariable;
	
	// output the value of the pointer
	cout << "intPointer: " << intPointer << endl;

	// what is this address that the pointer is pointing to? (insert answer)
	//			It is pointing towards the address of where the variable is stored, and its also the same address
	//			as when we were finding the address while referencing

	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << "Dereference intPointer: " << *intPointer << endl;


	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(intPointer);

	// output the dereference pointer
	cout << "Dereference intPointer using Double function: " << *intPointer << endl;

	// output the int variable created in the REFERENCE section
	cout << "intVariable: " << intVariable << endl;

	// did the int variable's value change when using the pointer?
	//			By derefencing it we went back to when we used the squared function (uses reference input so still valid)
	//			and so the variable didn't change using pointer but it did however change using the double function as
	//			we set it as a pointer and so we ended up with 128 rather than 64. So in the end it did technically did change
	//			the value but not from setting a number to the pointer variable and dreclaring like we did when making an alias
	//			in using reference but by making the function be able to receive a pointer and therefore the value that's within 
	//			the address.
}
