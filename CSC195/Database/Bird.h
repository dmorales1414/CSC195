#pragma once
#include "Animal.h"

class Bird : public Animal
{
public:
	eType GetType() override { return eType::BIRD; }

	virtual void Read(ostream& ostream, istream& istream) override;
	virtual void Write(ostream& ostream) override;

protected:
	int m_numFeathers = 0;
};

