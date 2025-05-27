#pragma once
#include <iostream>
using namespace std;

class Animal
{
public:
	enum class eType
	{
		BIRD,
		REPTILE,
		CAT
	};

	string GetName() { return m_name; }
	virtual eType GetType() = 0;

	virtual void Read(ostream& ostream, istream& istream);
	virtual void Write(ostream& ostream);

protected:
	string m_name;
	int m_lifespin;
};

