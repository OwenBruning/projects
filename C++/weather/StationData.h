//
// Created by Owen on 2/10/2018.
//

#ifndef CS124PROJECT2_STATIONDATA_H
#define CS124PROJECT2_STATIONDATA_H
#include <string>
using namespace std;

class StationData
{
    private:
       /**
        * ID of the station
        * Requires: nothing
        * Modifies: nothing
        * Effects: nothing
        */
        string station;

       /**
        * month-to-date amount of precipitation
        * Requires: nothing
        * Modifies: nothing
        * Effects: nothing
        */
        double monthPrecipitation;

       /**
        * month-to-date amount of snow
        * Requires: nothing
        * Modifies: nothing
        * Effects: nothing
        */
        double monthSnow;

       /**
        * year-to-date amount of precipitation
        * Requires: nothing
        * Modifies: nothing
        * Effects: nothing
        */
        double yearPrecipitation;

       /**
        * year-to-date amount of snow
        * Requires: nothing
        * Modifies: nothing
        * Effects: nothing
        */
        double yearSnow;

    public:
       /**
        * default constructor
        * Requires: nothing
        * Modifies: the 5 private variables
        * Effects: sets the 5 private variables to the default values
        */
        StationData();

       /**
        * station getter
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns station
        */
        string getStation() const;

       /**
        * monthPrecipitation getter
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns monthPrecipitation
        */
        double getMonthPrecipitation() const;

       /**
        * monthSnow getter
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns monthSnow
        */
        double getMonthSnow() const;

       /**
        * yearPrecipitation getter
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns yearPrecipitation
        */
        double getYearPrecipitation() const;

       /**
        * yearSnow getter
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns yearSnow
        */
        double getYearSnow() const;

       /**
        * station setter
        * Requires: nothing
        * Modifies: station
        * Effects: sets station to s
        */
        void setStation(string s);

       /**
        * monthPrecipitation setter
        * Requires: nothing
        * Modifies: monthPrecipitation
        * Effects: sets monthPrecipitation to mp
        */
        void setMonthPrecipitation(double mp);

       /**
        * monthSnow setter
        * Requires: nothing
        * Modifies: monthSnow
        * Effects: sets monthSnow to ms
        */
        void setMonthSnow(double ms);

       /**
        * yearPrecipitation setter
        * Requires: nothing
        * Modifies: yearPrecipitation
        * Effects: sets yearPrecipitation to yp
        */
        void setYearPrecipitation(double yp);

       /**
        * yearSnow setter
        * Requires: nothing
        * Modifies: yearSnow
        * Effects: sets yearSnow to ys
        */
        void setYearSnow(double ys);

};


#endif //CS124PROJECT2_STATIONDATA_H
