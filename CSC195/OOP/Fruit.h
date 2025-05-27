#pragma once
#include "Food.h"

class Fruit : public Food
{
public:
    Fruit(int calories, int numSeeds) : Food(calories){
        numOfSeeds = numSeeds;
    }
    void Consume() override {
        cout << "This is a fruit" << endl;
    }
protected:
    int numOfSeeds;
};

