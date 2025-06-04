#include <iostream>
#include "Fraction.h"

using namespace std;
using namespace mathlib;

int main()
{
    try {
        Fraction<> fraction1{ 15, 5 };
        cout << fraction1 << endl;

        Fraction<> fraction2{ 21, 5 }; // There's one bug that can't figure out, which is having -21/5, and the 5 being the negative in the console
        fraction2.Simplify();
        cout << fraction2 << endl;

        cout << fraction1 << " == " << fraction2 << " result: " << (fraction1 == fraction2) << endl;
        cout << fraction1 << " > " << fraction2 << " result: " << (fraction1 > fraction2) << endl;

        cout << fraction1 << " + " << fraction2 << " result: " << (fraction1 + fraction2) << endl;
        cout << fraction1 << " * " << fraction2 << " result: " << (fraction1 * fraction2) << endl;

        Fraction<> fraction3;
        cout << "input fraction (numerator (-, +) denominator): \n"; // - will make it negative, + will make positive
        cin >> fraction3;
        cout << fraction3 << endl;
        cout << fraction3.toDouble() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << '\n';
    }

    _CrtDumpMemoryLeaks();
}