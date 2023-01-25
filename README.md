# RollDice

Roll custom dices  
Compute sum or mean from dice rolls  

## Compiler
```
g++ main.cpp dice.cpp dice.h -o rollDice
```

## Executer
```
./rollDice
```

## Examples
* rollDice 1d6 : roll a 6-sided dice  
* rollDice 2d4 3d100 : roll twice a 4-sided dice and roll a 100-sided dice 3 times  
* rollDice --sum 3d20 : sum of 3 rolls of a 20-sided dice  
* rollDice --mean 2d20 3d15 : mean of dices value  
* rollDice --n nbRoll --values [2,4,6,8] : roll a dice with custom values 'nbRoll' times  
