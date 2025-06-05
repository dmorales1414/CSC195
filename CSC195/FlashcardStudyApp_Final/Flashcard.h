#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Flashcard
{
protected:
	string question, answer;
public:
	// Methods
	virtual void Display(bool answer) const = 0;
	virtual void Quiz() const = 0;
	virtual void Read(ifstream& in) = 0;
	virtual void Write(ofstream& out) = 0;

	// inputing and outputing
	friend istream& operator >> (istream& ist, Flashcard& f)
	{
		return ist;
	}
	friend ostream& operator << (ostream& ost, const Flashcard& f)
	{
		f.Display(false);
		return ost;
	}

	// Destructor
	virtual ~Flashcard() = default;
};