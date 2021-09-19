//
// Created by Owen on 2/10/2018.
//

#include "StationData.h"

StationData::StationData()
{
    station = "";
    monthPrecipitation = 0.0;
    monthSnow = 0.0;
    yearPrecipitation = 0.0;
    yearSnow = 0.0;
}

string StationData::getStation() const
{
    return station;
}

double StationData::getMonthPrecipitation() const
{
    return monthPrecipitation;
}

double StationData::getMonthSnow() const
{
    return monthSnow;
}

double StationData::getYearPrecipitation() const
{
    return yearPrecipitation;
}

double StationData::getYearSnow() const
{
    return yearSnow;
}

void StationData::setStation(string s)
{
    station = s;
}

void StationData::setMonthPrecipitation(double mp)
{
    monthPrecipitation = mp;
}

void StationData::setMonthSnow(double ms)
{
    monthSnow = ms;
}

void StationData::setYearPrecipitation(double yp)
{
    yearPrecipitation = yp;
}

void StationData::setYearSnow(double ys)
{
    yearSnow = ys;
}