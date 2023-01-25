#include <iostream>
#include <cstring>
#include <sstream>
#include <ctime>
#include "dice.h"

using namespace std;

void printUsage()
{
    string AppName = "rollDice";
	string description = "roll custom dices";
		
    cout << AppName << " : " << description << endl;
	cout << "Usages : " << endl;
	cout << AppName << " [option] <dice1> ... <diceN>" << endl;
	cout << AppName << " --n <nbRoll> --values <values>" << endl;
	cout << "Argument : " << endl;
	cout << "<dice> = xdy : roll x times a dice with y sides" << endl;
	cout << "Options : " << endl;
	cout << "--sum             : sum of dices rolled" << endl;
	cout << "--mean            : mean of dices rolled" << endl;
	cout << "--n <nbRoll>      : number of dice rolls" << endl;
	cout << "--values <values> : values of a dice (format a,b,c)" << endl;
}

int main(int argc, char** argv)
{
	if(argc > 1)
	{
		srand(time(0));
		
		// dices to roll
		vector<Dice> vDice;
		
		// number of rolls for each dice
		vector<int> vRoll;
		
		// parse command line arguments
		// argv[1]
		bool option_sum = !strcmp(argv[1], "--sum");
		bool option_mean = !strcmp(argv[1], "--mean");
		bool option_n = !strcmp(argv[1], "--n");
		
		// argv[i>=1]
		if(option_n)
		{
			int nbRoll = atoi(argv[2]);
			vRoll.push_back(nbRoll);
			
			bool option_values = !strcmp(argv[3], "--values");
			if(option_values)
			{
				string vals(argv[4]); 
				stringstream ssv(vals);
				string sVal;
				vector<int> v;

				// read dice values
				while(getline(ssv, sVal, ','))
				{
					v.push_back(stoi(sVal));
				}
				if(!v.empty()){ vDice.push_back(Dice(v));}
			}
			else
			{
				cerr << "Custom dice without values : cannot roll dice" << endl;
			}
		}
		else
		{
			int begin = (option_sum || option_mean) ? 2 : 1;
			for(int i=begin; i<argc; ++i)
			{
				int nbRoll, nbFaces;
				int ret = sscanf(argv[i], "%dd%d", &nbRoll, &nbFaces);
				if(ret == 2)
				{
					vDice.push_back(Dice(nbFaces));
					vRoll.push_back(nbRoll);
				}
				else
				{
					cerr << "Not recognized dice : " << argv[i] << endl;
				}
			}
		}
		
		// print roll results
		int r;
		int sum = 0, sumR = 0;
		double mean = 0.0;
		for(int i=0; i<vDice.size(); ++i)
		{
		    for(int j=0; j<vRoll[i]; ++j)
			{
				r = vDice[i].roll();
				cout << r << " ";
				sum += r;
			}
			sumR += vRoll[i];
		}
		cout << "\n";
		mean = (double) sum / sumR;
		if(option_sum){ cout << "sum = " << sum;}
		if(option_mean){ cout << "mean = " << mean;}
	}
	else
	{
        printUsage();
	}
    
    return 0;
}
