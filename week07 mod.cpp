#include<iostream>

#include<iomanip>

#include<string>

#include<fstream>

using namespace std;

#define PLAYERS 10// define the amount of player
#define games 4
struct bowler {
	string name;
	int score[4];
	int avg_scores;
};
bool GetBowlingData(bowler bowlers[], int& n)
{
// defines an input stream for the data file
ifstream dataIn;
// Opening the input file
dataIn.open("BowlingScoresMod.txt");
// checking whether the file name is valid or not
if (dataIn.fail()) {
	return false;
}
else {
	// counting no of records in the file
	while (dataIn >> bowlers[n].name) {
		for (int j = 0; j < 5; j++) {
			dataIn >> bowlers[n].score[j];
		}
		n++;
	}

	// Closing the intput file
	dataIn.close();
}
return true;

}


void GetAverageScore(bowler bowlers[], int n)
{
double total = 0;
for (int i = 0; i < n; i++) {
	total = 0;
	for (int j = 0; j < 5; j++) {
		total += bowlers[i].score[j];
	}
	bowlers[i].avg_scores = (int)(total / 4);
}
}

void PrettyPrintResults(bowler bowlers[], int n)
{

	cout << left << setw(15) << "Name" << "Score1\tScore2\tScore3\tScore4\tAvg_Score" << endl;// get the headers set up 

	for (int i = 0; i < n; i++) 
	{

		cout << left << setw(15) << bowlers[i].name << "\t";//prints names

		for (int j = 0; 5 < games; j++)

			cout << bowlers[i].score[j] << "\t";//print score

			cout << bowlers[i].avg_scores << endl;//prints average

	}

}

int main() 
{
	bowler bowlers[100];
	int n = 0;

	if (GetBowlingData(bowlers, n)) 
	{

		GetAverageScore(bowlers, n);

		PrettyPrintResults(bowlers, n);

	}
	else
	{
		cout << "*Error File not found*" << endl;
	}

	return 0;

}

