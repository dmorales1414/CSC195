#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm> // For shuffling cards when taking quiz
#include "Flashcard.h"
#include "Textcard.h"
#include "MultipleChoiceCard.h"

// To ensure no memory leaks happen
#define _CRTBBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

// Creating the type of flashcards using enums
enum CardType { MULTIPLE_CHOICE = 1, TEXT_CARD = 2 };

unique_ptr<Flashcard> CreateCardFromType(int type)
{
	switch (type)
	{
	case MULTIPLE_CHOICE: return make_unique<MultipleChoiceCard>();
	case TEXT_CARD: return make_unique<TextCard>();
	default: return nullptr;
	}
}

// Loop Fixer to stop inifinite loops
//void LoopFixer()
//{
//	if (std::cin.fail()) 
//	{
//		std::cin.clear(); // will manually clear the error state
//		std::cin.ignore(1000, '\n'); // discards invalid input, such as a letter than a number
//		std::cout << "Invalid Input. \n";
//		continue;
//	}
//}


int main()
{
	// Checks that there's no memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<unique_ptr<Flashcard>> cards;
	int choice;

	while (true)
	{
		cout << "\n1. Add Flashcard\n"
			<< "2. Display All FlashCards\n"
			<< "3. Take Quiz\n"
			<< "4. Load\n"
			<< "5. Save\n"
			<< "6. Quit\n";
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			int userInput;
			cout << "\n1. Multiple Choice Card\n"
				<< "2. Type-in Flashcard\n";
			cin >> userInput;
			cin.ignore();

			auto card = CreateCardFromType(userInput);
			if (card) {
				// call corrects operator >> overload
				if (auto ptr = dynamic_cast<MultipleChoiceCard*>(card.get()))
				{
					cin >> *ptr;
				}
				else if (auto ptr = dynamic_cast<TextCard*>(card.get()))
				{
					cin >> *ptr;
				}
				cards.push_back(move(card));
			}
			else {
				cout << "Invalid Card Type. Please choose from the options provided (1-2).\n";
			}

		}
		else if (choice == 2)
		{
			for (const auto& card : cards)
			{
				card->Display(true);
				cout << endl;
			}
			
		}
		else if (choice == 3)
		{
			vector<Flashcard*> shuffledCards;
			for (const auto& card : cards)
			{
				shuffledCards.push_back(card.get());
			}

			random_shuffle(shuffledCards.begin(), shuffledCards.end());

			for (auto* card : shuffledCards)
			{
				card->Quiz();
				cout << endl;
			}
		}
		else if (choice == 4)
		{
			string filename;
			cout << "Enter filename to load from (ex. (filename).txt): ";
			cin >> filename;
			ifstream in(filename);
			if (in)
			{
				cards.clear(); // Resets everything to prepare for loading the file
				int type;
				while (in >> type)
				{
					in.ignore();
					auto card = CreateCardFromType(type);
					if (card)
					{
						card->Read(in);
						cards.push_back(move(card));
					}
				}
				cout << "Loaded flashcards successfully. \n";
			}
			else
			{
				cout << "Could not open file. \n";
			}
		}
		else if (choice == 5)
		{
			string filename;
			cout << "Enter filename to save to (ex. (filename).txt): ";
			cin >> filename;
			ofstream out(filename);
			if (!out)
			{
				cout << "Failed to open file for writing.\n";
			}
			else
			{
				for (const auto& card : cards)
				{
					if (dynamic_cast<MultipleChoiceCard*>(card.get()))
					{
						out << MULTIPLE_CHOICE << "\n";
					}
					else if (dynamic_cast<TextCard*>(card.get()))
					{
						out << TEXT_CARD << "\n";
					}
					card->Write(out);
				}
				cout << "Saved flashcards successfully. \n";
			}
		}
		else if (choice == 6)
		{
			break;
		}
		else {
			cout << "Invalid choice. \n";
		}

	}
}