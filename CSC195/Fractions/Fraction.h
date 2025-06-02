#pragma once
#include <iostream>

using namespace std;

namespace mathlib
{
	class Fraction
	{
	private:
		int numerator, denominator;
	public:
		Fraction(int numerator, int denominator) : numerator{ numerator }, denominator{denominator} {}

		void Write(ostream& ost);

		
	};
}