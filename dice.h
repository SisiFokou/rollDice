#ifndef DICE_H
#define DICE_H

#include <string>
#include <vector>

class Dice
{
public:
    // constructor
    Dice(int faces);
    Dice(const std::vector<int>& v);
    
    // destructor
    ~Dice();
    
    // getter/setter
    int getFaces() { return _values.size();}
    std::vector<int> getValues() { return _values;}
    int getValue(int i){ return _values[i];}
    void setValues(const std::vector<int>& v) { _values = v;}
    void setValues(int i, int val) { _values[i] = val;}
    
    // roll dice
    int roll();
    
    // convert Dice to string - debug usage
    std::string toString();
    
private:
    std::vector<int> _values;
};

#endif
