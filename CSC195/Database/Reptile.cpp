#include "Reptile.h"

void Reptile::Read(ostream& ostream, istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "Enter number of scales: ";
	istream >> m_numOfScales;
}

void Reptile::Write(ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "Number of scales: " << m_numOfScales << endl;
}
