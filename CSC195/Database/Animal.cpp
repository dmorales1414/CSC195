#include "Animal.h"

void Animal::Read(ostream& ostream, istream& istream) 
{
	ostream << "Enter Name: ";
	istream >> m_name;

	ostream << "Enter Lifespan: ";
	istream >> m_lifespin;
}

void Animal::Write(ostream& ostream)
{
	ostream << "Name: " << m_name << endl;
	ostream << "Remaining Lifespan: " << m_lifespin << endl;
}