#include <iostream>

using namespace std;

int main() {
    // Declare variables
    string name; // Stores the employee’s name
    char initial; // Stores the first letter of the last name
    short age; // Stores employee age (smallest type for 18-99 range)
    bool isAdult; // True if 18 or older, false otherwise
    unsigned int zipcode; // Stores a 5-digit zip code (non-negative)
    float wage; // Stores the hourly wage
    short daysWorked; // Stores the number of days worked (max 7)
    float hoursWorkedPerDay[7]; // Stores hours worked per day(array for up to 7 days)

    const float TAX = 0.1f; // 10% tax

    // Get user input
    cout << "Enter first name: ";
    cin >> name;

    cout << "Enter initial of last name: ";
    cin >> initial;

    cout << "Enter age: ";
    cin >> age;
    isAdult = (age >= 18); // // Determine adulthood status

    cout << "Enter zipcode: ";
    cin >> zipcode;

    cout << "Enter hourly wage: ";
    cin >> wage;

    cout << "Enter number of days worked (max 7): ";
    cin >> daysWorked;

    // Collect Hours Worked Per Day
    float totalHours = 0;
    for (int i = 0; i < daysWorked; i++) {
        cout << "Enter hours worked for day " << (i + 1) << ": ";
        cin >> hoursWorkedPerDay[i];
        totalHours += hoursWorkedPerDay[i];
    }

    // Calculate payroll
    float grossIncome = totalHours * wage;
    float taxAmount = grossIncome * TAX;
    float netIncome = grossIncome - taxAmount;

    // Display Payroll Information
    cout << "\nEmployee Payroll Summary\n";
    cout << "-------------------------\n";
    cout << "Name: " << name << " " << initial << ".\n";
    cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")\n";
    cout << "Zipcode: " << zipcode << "\n";
    cout << "Hourly Wage: $" << wage << " per hour\n";
    cout << "Total Hours Worked: " << totalHours << " hours\n";
    cout << "Gross Income: $" << grossIncome << "\n";
    cout << "Tax Amount: $" << taxAmount << "\n";
    cout << "Net Income: $" << netIncome << "\n";

    return 0;
}