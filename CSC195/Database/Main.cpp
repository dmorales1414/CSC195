#include "Database.h"
#include "Animal.h"
#include <limits> // For numeric_limits
#include <iostream>

int main() 
{
	Database database;
    int typeChoice;
    string name;


    bool quit = false;
    while (!quit)
    {
        cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit\n";
        int choice;
        cin >> choice;
        if (cin.fail()) { // This is to stop the infinite loop when choosing a letter rather than a number
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please enter a number. \n\n";
            continue;
        }

        cout << "\n";
        switch (choice)
        {
        case 1: // Create object by type break; 
            cout << "1 - Bird\n2 - Reptile\n3 - Cat\n";
            cin >> typeChoice;

            if (cin.fail()) { // This is to stop the infinite loop when choosing a letter rather than a number
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input. Please enter a number. \n\n";
                break;
            }

            switch (typeChoice)
            {
            case 1:
                database.Create(Animal::eType::BIRD);
                break;
            case 2:
                database.Create(Animal::eType::REPTILE);
                break;
            case 3:
                database.Create(Animal::eType::CAT);
                break;
            default:
                cout << "Unvalid Choice.\n\n";
                break;
            }break;

        case 2: // DisplayAll(); break; 
            database.DisplayAll();
            break;

        case 3: // Ask for name, then call database.Display(name) break; 
            cout << "Select the animal you want to display (name): ";
            cin >> name;
            database.Display(name);
            break;

        case 4: // Note to self, enums (type) start at 0 like an array
        {
            cout << "Enter type you want to Display\n(0 - Bird, 1 - Reptile, 2 - Cat): ";
            int t;
            cin >> t;

            if (cin.fail()) { // This is to stop the infinite loop when choosing a letter rather than a number
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input. Please enter a number. \n\n";
                continue;
            }

            database.Display(static_cast<Animal::eType>(t)); break;
        }

        case 5:
            quit = true;
            break;
        }
    }


}