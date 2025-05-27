#pragma once
#include "Animal.h"

class Reptile : public Animal
{
public:
	eType GetType() override { return eType::REPTILE; }

	virtual void Read(ostream& ostream, istream& istream) override;
	virtual void Write(ostream& ostream) override;

protected:
	int m_numOfScales = 0;
};

