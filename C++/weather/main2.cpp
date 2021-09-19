#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "StationData.h"
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "SplayTree.h"
using namespace std;

void storeInVector(vector<StationData> &stationDataVector);

int main()
{
    vector<StationData> stationDataVector(1003);
    ifstream fIn;
    int index;

    storeInVector(stationDataVector);

    cout << "Note: you have to run the program in debug mode to see the full output (due to a CLion bug)." << endl;

    BinarySearchTree b;

    for (int i = 0; i < 1000; i++)
    {
         b.insert(stationDataVector[i]);
    }

    AvlTree a;

    for (int i = 0; i < 1000; i++)
    {
        a.insert(stationDataVector[i]);
    }

    SplayTree s;

    for (int i = 0; i < 1000; i++)
    {
        s.insert(stationDataVector[i]);
    }

    fIn.open("intFile1.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        b.depth = 0;
        if (b.contains(stationDataVector[index], b.depth))
        {
            cout << b.depth - 1 << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile1.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        a.depth = 0;
        if (a.contains(stationDataVector[index], a.depth))
        {
            cout << a.depth - 1 << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile1.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        if (s.contains(stationDataVector[index], s.depth))
        {
            cout << s.depth << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile2.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        b.depth = 0;
        if (b.contains(stationDataVector[index], b.depth))
        {
            cout << b.depth - 1 << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile2.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        a.depth = 0;
        if (a.contains(stationDataVector[index], a.depth))
        {
            cout << a.depth - 1 << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile2.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        if (s.contains(stationDataVector[index], s.depth))
        {
            cout << s.depth << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile3.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        b.depth = 0;
        if (b.contains(stationDataVector[index], b.depth))
        {
            cout << b.depth - 1 << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile3.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        a.depth = 0;
        if (a.contains(stationDataVector[index], a.depth))
        {
            cout << a.depth - 1 << " ";
        }
    }
    cout << endl;
    fIn.close();

    fIn.open("intFile3.txt");
    while (fIn && fIn.peek() != EOF)
    {
        fIn >> index;
        if (s.contains(stationDataVector[index], s.depth))
        {
            cout << s.depth << " ";
        }
    }
    cout << endl;
    fIn.close();

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
    fIn.close();
}
