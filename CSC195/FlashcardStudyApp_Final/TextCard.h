#pragma once
#include "Flashcard.h"
#include <sstream>
#include <string>

#ifdef _WIN32
#define strcasecmp _stricmp
#endif // _WIN32


class TextCard : public Flashcard
{
private:
	vector<string> answers;

public:
	void Display(bool showAnswer) const override
	{
		cout << "Q: " << question << endl;
		if (showAnswer)
		{
			cout << "Answers: ";
			for (size_t i = 0; i < answers.size(); i++)
			{
				cout << answers[i];
				if (i != answers.size() - 1) cout << ", ";
			}
			cout << endl;
		}
	}

	void Quiz() const override
	{
		Display(false);
		cout << "Your answer: ";
		string userInput;
		getline(cin, userInput);

		for (const auto& a : answers)
		{
			if (_strcmpi(userInput.c_str(), a.c_str()) == 0)
			{
				cout << "Correct!\n";
				return;
			}
		}
		cout << "Incorrect! One correct answer is: " 
			<< (answers.empty() ? "N/A" : answers[0]) << "\n";
	}

	void Read(ifstream& in) override
	{
		getline(in, question);
		answers.clear();

		string line;
		getline(in, line); // "Answers: ..."
		if (line.rfind("Answers:", 0) == 0) {
			line = line.substr(8); // skip "Answers:"
			stringstream ss(line);
			string ans;
			while (getline(ss, ans, ',')) {
				// Remove leading/trailing spaces
				ans.erase(0, ans.find_first_not_of(" "));
				ans.erase(ans.find_last_not_of(" ") + 1);
				answers.push_back(ans);
			}
		}

	}

	void Write(ofstream& out) override
	{
		out << question << '\n';
		out << "Answers:";
		for (size_t i = 0; i < answers.size(); ++i)
		{
			out << (i == 0 ? " " : ", ") << answers[i];
		}
		out << '\n';
	}

	friend istream& operator >> (istream& ist, TextCard& card)
	{
		cout << "Enter a question: ";
		getline(ist, card.question);
		card.answers.clear();
		string ans;
		char more;
		do {
			cout << "Enter an answer: ";
			getline(ist, ans);
			card.answers.push_back(ans);
			cout << "Do you want to add another answer? (Y/N): ";
			ist >> more;
			ist.ignore();
		} while (toupper(more) == 'Y');
		return ist;
	}

	friend ostream& operator << (ostream& ost, const TextCard& card)
	{
		card.Display(false);
		return ost;
	}

};