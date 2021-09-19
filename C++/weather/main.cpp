#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "StationData.h"
using namespace std;

void storeInVector(vector<StationData> &stationDataVector);
double sumMonthPrecipitation(vector<StationData> &stationDataVector, double sum);

int main()
{
    vector<StationData> stationDataVector(1000);
    double sum = 0.0;

    storeInVector(stationDataVector);
    cout << "The sum of the monthPrecipitation values is: " << sumMonthPrecipitation(stationDataVector, sum) << endl;
    cout << "The following code will print all of the data from the vector to ensure that it works." << endl;
    cout << "Note: you might have to run the program in debug mode to see the full output (due to a CLion bug)." << endl;
    for (int i = 0; i < stationDataVector.size(); i++)
    {
        cout << stationDataVector[i].getStation() << "   " << stationDataVector[i].getMonthPrecipitation() << "   "
             << stationDataVector[i].getMonthSnow() << "   " << stationDataVector[i].getYearPrecipitation() << "   "
             << stationDataVector[i].getYearSnow() << endl;
    }
    cout << "The following code will test the setters by modifying the final row of data and reprinting it." << endl;
    stationDataVector[999].setStation("modifiedStation");
    stationDataVector[999].setMonthPrecipitation(1.0);
    stationDataVector[999].setMonthSnow(1.0);
    stationDataVector[999].setYearPrecipitation(1.0);
    stationDataVector[999].setYearSnow(1.0);
    cout << stationDataVector[999].getStation() << "   " << stationDataVector[999].getMonthPrecipitation() << "   "
         << stationDataVector[999].getMonthSnow() << "   " << stationDataVector[999].getYearPrecipitation() << "   "
         << stationDataVector[999].getYearSnow() << endl;

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

//The method below calculates the sum of all of the monthPrecipitation values.
double sumMonthPrecipitation(vector<StationData> &stationDataVector, double sum)
{
    for (int i = 0; i < stationDataVector.size(); i++)
    {
        sum += stationDataVector[i].getMonthPrecipitation();
    }
    return sum;
}
