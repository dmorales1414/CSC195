#include "Database.h"

void Database::Create(Animal::eType type)
{
	Animal* animal = nullptr;

	switch (type)
	{
	case Animal::eType::BIRD :
		animal = new Bird;
		cout << endl;
		break;
	case Animal::eType::REPTILE :
		animal = new Reptile;
		cout << endl;
		break;
	case Animal::eType::CAT :
		animal = new Cat;
		cout << endl;
		break;
	default:
		cout << endl;
		break;
	}

	animal->Read(cout, cin);
	m_animals.push_back(animal);
}

void Database::Display(const string& name)
{
	for (Animal* animal : m_animals)
	{
		if (animal->GetName() == name)
		{
			animal->Write(cout);
			cout << endl;
		}
	}
}

void Database::Display(Animal::eType type)
{
	for (Animal* animal : m_animals)
	{
		if (animal->GetType() == type)
		{
			animal->Write(cout);
			cout << endl;
		}
	}
}

Database::~Database()
{
	for (Animal* animal : m_animals)
	{
		delete animal;
	}

}

void Database::DisplayAll()
{
	for (Animal* animal : m_animals)
	{
		animal->Write(cout);
		cout << endl;
	}
}