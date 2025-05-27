#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	eType GetType() override { return eType::CAT; }

	virtual void Read(ostream& ostream, istream& istream) override;
	virtual void Write(ostream& ostream) override;

protected:
	int m_numOfWhiskers = 0;
};

