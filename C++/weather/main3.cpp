#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "StationData.h"
int reads;
#include "Probing.h"
#include "SeparateChaining.h"
using namespace std;

void storeInVector(vector<StationData> &stationDataVector); //Declare all of the functions.
string guessWho(const StationData &s);
void separateChaining(int tableSize, vector<StationData> &v, ofstream &out, int newHash);
void probing(int tableSize, vector<StationData> &v, ofstream &out, int newHash);

int main()
{
    cout << "Note: you might have to run the program in debug mode (due to a CLion bug)." << endl;
    cout << "Note: this program writes the results to the file called results.txt, so there is no console output." << endl;
    vector<StationData> stationDataVector(1000); //Create stationDataVector and give it a size of 1000.
    storeInVector(stationDataVector); //Store the data in stationDataVector.

    ofstream out; //Declare an output file stream.
    out.open("results.txt"); //Open the file which is called results.txt.

    out << "-------------------- SEPARATE CHAINING (ORIGINAL HASH FUNCTION) --------------------" << endl << endl;

    out << "---------- SIZE 10 ----------" << endl;
    separateChaining(10, stationDataVector, out, 37);

    out << "---------- SIZE 2 ----------" << endl;
    separateChaining(2, stationDataVector, out, 37);

    out << "---------- SIZE 3 ----------" << endl;
    separateChaining(3, stationDataVector, out, 37);

    out << "---------- SIZE 5 ----------" << endl;
    separateChaining(5, stationDataVector, out, 37);

    out << "---------- SIZE 7 ----------" << endl;
    separateChaining(7, stationDataVector, out, 37);

    out << "---------- SIZE 11 ----------" << endl;
    separateChaining(11, stationDataVector, out, 37);

    out << "-------------------- SEPARATE CHAINING (MODIFIED HASH FUNCTION) --------------------" << endl << endl;

    out << "---------- SIZE 10 ----------" << endl;
    separateChaining(10, stationDataVector, out, 30);

    out << "---------- SIZE 2 ----------" << endl;
    separateChaining(2, stationDataVector, out, 30);

    out << "---------- SIZE 3 ----------" << endl;
    separateChaining(3, stationDataVector, out, 30);

    out << "---------- SIZE 5 ----------" << endl;
    separateChaining(5, stationDataVector, out, 30);

    out << "---------- SIZE 7 ----------" << endl;
    separateChaining(7, stationDataVector, out, 30);

    out << "---------- SIZE 11 ----------" << endl;
    separateChaining(11, stationDataVector, out, 30);

    out << "-------------------- PROBING (ORIGINAL HASH FUNCTION) --------------------" << endl << endl;

    out << "---------- SIZE 10 ----------" << endl;
    probing(10, stationDataVector, out, 37);

    out << "---------- SIZE 2 ----------" << endl;
    probing(2, stationDataVector, out, 37);

    out << "---------- SIZE 3 ----------" << endl;
    probing(3, stationDataVector, out, 37);

    out << "---------- SIZE 5 ----------" << endl;
    probing(5, stationDataVector, out, 37);

    out << "---------- SIZE 7 ----------" << endl;
    probing(7, stationDataVector, out, 37);

    out << "---------- SIZE 11 ----------" << endl;
    probing(11, stationDataVector, out, 37);

    out << "-------------------- PROBING (MODIFIED HASH FUNCTION) --------------------" << endl << endl;

    out << "---------- SIZE 10 ----------" << endl;
    probing(10, stationDataVector, out, 30);

    out << "---------- SIZE 2 ----------" << endl;
    probing(2, stationDataVector, out, 30);

    out << "---------- SIZE 3 ----------" << endl;
    probing(3, stationDataVector, out, 30);

    out << "---------- SIZE 5 ----------" << endl;
    probing(5, stationDataVector, out, 30);

    out << "---------- SIZE 7 ----------" << endl;
    probing(7, stationDataVector, out, 30);

    out << "---------- SIZE 11 ----------" << endl;
    probing(11, stationDataVector, out, 30);

    out.close();

    return 0;
}

//The method below stores the data in a vector of 1000 objects.
void storeInVector(vector<StationData> &stationDataVector)
{
    ifstream fIn; //Declare an input stream.
    char comma;
    int count = 0;
    string station;
    double monthPrecipitation, monthSnow, yearPrecipitation, yearSnow;

    fIn.open("weather.csv"); //Open the csv file.
    while (fIn && fIn.peek() != EOF) //Use a while loop to loop over each line of the file.
    {
        getline(fIn, station, ',');
        stationDataVector[count].setStation(station);

        fIn >> monthPrecipitation >> comma;
        stationDataVector[count].setMonthPrecipitation(monthPrecipitation);

        fIn >> monthSnow >> comma;
        stationDataVector[count].setMonthSnow(monthSnow);

        fIn >> yearPrecipitation >> comma;
        stationDataVector[count].setYearPrecipitation(yearPrecipitation);

        fIn >> yearSnow;
        stationDataVector[count].setYearSnow(yearSnow);

        count++;
    }
}

//The method below takes an object of type StationData and returns its station.
string guessWho(const StationData &s) {
    return s.getStation();
}

//The method below performs separate chaining on all 1000 objects.
void separateChaining(int tableSize, vector<StationData> &v, ofstream &out, int newHash)
{
    SeparateChaining table(tableSize, guessWho);
    double total = 0.0, count = 0.0;
    int max = 0;
    out << "reads: ";
    for (StationData s : v) {
        table.insert(s, newHash);
        out << reads << " ";
        count++;
        total += reads;
        if (reads > max)
            max = reads;
    }
    double average = total / count;
    out << endl << "maximum reads: " << max;
    out << endl << "average reads: " << average << endl << endl;
}

//The method below performs probing on all 1000 objects.
void probing(int tableSize, vector<StationData> &v, ofstream &out, int newHash)
{
    Probing<StationData> table(tableSize, guessWho);
    double total = 0.0, count = 0.0;
    int max = 0;
    out << "reads: ";
    for (StationData s : v) {
        table.insert(s, newHash);
        out << reads << " ";
        count++;
        total += reads;
        if (reads > max)
            max = reads;
    }
    double average = total / count;
    out << endl << "maximum reads: " << max;
    out << endl << "average reads: " << average << endl;
    out << "table size: " << table.getSize() << endl << endl;
}