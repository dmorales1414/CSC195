#pragma once
#include <iostream>
using namespace std;


class Food
{
public:
	// Constructor
	~Food(){ // Deallocates Memory

	}

	Food(int calories) {
		m_calories = calories;
	}

	virtual void Consume() = 0; // Pure virtual function, does not need a body, makes the base class abstract
	int GetCalories() { return m_calories; }
	void SetCalories(int calories) { m_calories = calories; }

protected:
	int m_calories;
	int* m_p;
};