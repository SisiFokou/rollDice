#include "dice.h"
#include <cstdlib>

using namespace std;

Dice::Dice(int faces)
{
    for(int i=0; i<faces; ++i){ _values.push_back(i+1);}
}

Dice::Dice(const vector<int>& v)
{
    setValues(v);
}

Dice::~Dice()
{
    // destructor
}

int Dice::roll()
{
    int i = rand() % getFaces();
    return _values[i];
}

string Dice::toString()
{
    int faces = getFaces();
    string sdice = "{faces: " + to_string(faces) + ", values: ";
    
    // add values to sdice
    for(int i=0; i<faces; ++i){ sdice += to_string(_values[i]) + " ";}
    sdice += "}";
    
    return sdice;
}
