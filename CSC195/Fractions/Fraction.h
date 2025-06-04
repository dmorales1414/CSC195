#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

namespace mathlib
{
	template <typename T = int>
	class Fraction
	{
	private:
		T numerator, denominator;
	public:
		// Constructors
		Fraction() : numerator(0), denominator(1) {}
		Fraction(T num, T denom)
		{
			if (denom == 0) throw invalid_argument("Denominator cannot equal 0");
			if (denom < 0)
			{
				num *= -1;
				denom *= -1; // multiplies by -1 to have the numerator be the negative rather than the denominator as standard math
			}

			T gcd1 = gcd(num, denom);
			numerator = num / gcd1;
			denominator = denom / gcd1;
		}


		// Simplify and toDouble methods, as well as gcd
		void Simplify()
		{
			T gcd1 = gcd(numerator, denominator);
			numerator /= gcd1;
			denominator /= gcd1;
		}
		double toDouble() const
		{
			return static_cast<double>(numerator) / denominator;
		}
		T gcd(T a, T b)
		{
			while (b != 0)
			{
				T temp = b;
				b = a % b;
				a = temp;
			}
			return a;
		}

		// Arithmetic operators
		Fraction operator + (const Fraction& other) const
		{
			return Fraction(numerator * other.denominator + other.numerator * denominator, // cross equation = n1 * d2 = n2 * d1
				denominator * other.denominator);
		}
		Fraction operator - (const Fraction& other) const
		{
			return Fraction(numerator * other.denominator - other.numerator * denominator,
				denominator * other.denominator);
		}
		Fraction operator * (const Fraction& other) const
		{
			return Fraction(numerator * other.numerator,
				denominator * other.denominator);
		}
		Fraction operator / (const Fraction& other) const
		{
			if (other.numerator == 0) throw domain_error("Devision by zero fraction");
			return Fraction(numerator * other.denominator,
				denominator * other.numerator);
		}

		// Comparison operators
		int compareTo(const Fraction& other) const
		{
			T lhs = numerator * other.denominator;
			T rhs = denominator * other.numerator;
			return (lhs < rhs) ? -1 : (lhs > rhs) ? 1 : 0; // 1 = true, 0 = false
		}

		bool operator == (const Fraction& other) const { return compareTo(other) == 0; }
		bool operator != (const Fraction& other) const { return compareTo(other) != 0; }
		bool operator < (const Fraction& other) const { return compareTo(other) < 0; }
		bool operator > (const Fraction& other) const { return compareTo(other) > 0; }
		bool operator <= (const Fraction& other) const { return compareTo(other) <= 0; }
		bool operator >= (const Fraction& other) const { return compareTo(other) >= 0; }

		// Friend stream operators
		friend ostream& operator << (ostream& ost, const Fraction& f)
		{
			ost << f.numerator << "/" << f.denominator;
			return ost;
		}

		friend istream& operator >> (istream& ist, Fraction& f)
		{
			ist >> f.numerator >> f.denominator;
			if (f.denominator == 0) throw invalid_argument("Denominator cannot be zero");
			if (f.denominator < 0)
			{
				f.numerator *= -1;
				f.denominator *= -1;
			}
			f.Simplify();
			return ist;
		};
	};
}