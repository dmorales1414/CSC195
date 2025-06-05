#pragma once
#include "Flashcard.h"
#include <random>

class MultipleChoiceCard : public Flashcard
{
private:
	vector<string> choices;

public:
	void Display(bool showAnswer) const override
	{
		cout << "Q: " << question << endl;
		for (size_t i = 0; i < choices.size(); i++)
		{
			cout << char('A' + i) << ") " << choices[i] << endl;
		}
		if (showAnswer)
		{
			cout << "Answer: " << answer << endl;
		}
	}

	void Quiz() const override
	{
		Display(false);
		cout << "Your answer (ex. A, B, etc.): ";
		string userInput;
		getline(cin, userInput);

		if (!userInput.empty() && toupper(userInput[0]) == toupper(answer[0]))
		{
			cout << "Correct!\n";
		}
		else
		{
			cout << "Incorrect! Correct answer is: " << answer << '\n';
		}
	}

	void Read(ifstream& in) override
	{
		getline(in, question);
		choices.clear();
		string line;

		// Will read until it hits answer, so it doesn't copy the numbers when selecting a choice
		while (getline(in, line)) {
			if (line.rfind("Answer:", 0) == 0) {
				answer = line.substr(8); // skip "Answer: "
				break;
			}
			if (!line.empty()) {
				size_t pos = line.find(") ");
				if (pos != string::npos && pos + 2 < line.length()) {
					choices.push_back(line.substr(pos + 2));
				}
			}
		}

	}

	void Write(ofstream& out) override
	{
		out << question << '\n';
		for (size_t i = 0; i < choices.size(); ++i)
		{
			out << char('A' + i) << ") " << choices[i] << '\n';
		}
		out << "Answer: " << answer << '\n';
	}

	friend istream& operator >> (istream& ist, MultipleChoiceCard& card)
	{
		cout << "Enter a question: ";
		getline(ist, card.question);

		cout << "Enter the Correct Answer (ex. A. 'answer'): ";
		getline(ist, card.answer);

		int numChoices;
		cout << "How many choices (including the correct one)? ";
		ist >> numChoices;
		ist.ignore();

		card.choices.clear();

		// Saves all options in the vector
		vector<string> tempChoices;
		for (int i = 0; i < numChoices; i++)
		{
			string choice;
			cout << "Enter a wrong choice: ";
			getline(ist, choice);
			tempChoices.push_back(choice);
		}

		// Insert the correct answer at a random position
		int correctIndex = rand() % numChoices;
		card.choices.resize(numChoices);

		int j = 0;
		for (int i = 0; i < numChoices; i++)
		{
			if (i == correctIndex)
			{
				card.choices[i] = card.answer;
			}
			else {
				card.choices[i] = tempChoices[j++];
			}
		}

		// Store correct letter (A,B, etc. ) as the answer
		card.answer = string(1, 'A' + correctIndex);
		return ist;
	}

	friend ostream& operator << (ostream& ost, const MultipleChoiceCard& card)
	{
		card.Display(false);
		return ost;
	}
};

