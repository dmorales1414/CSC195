#include "Cat.h"

void Cat::Read(ostream& ostream, istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "Enter number of whiskers: ";
	istream >> m_numOfWhiskers;
}

void Cat::Write(ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "Number of Whiskers: " << m_numOfWhiskers << endl;
}