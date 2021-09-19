//
// Created by Owen on 3/29/2018.
//

#ifndef CS120PROJECT6_FRUIT_H
#define CS120PROJECT6_FRUIT_H
#include <iostream>
using namespace std;

class Fruit {
private:
    /**
    * volume of the fruit
    * Requires: nothing
    * Modifies: nothing
    * Effects: nothing
    */
    double volume; //Note that the volume is in centimeters cubed.

public:
    /**
    * default constructor
    * Requires: nothing
    * Modifies: nothing
    * Effects: sets the default volume of the fruit
    */
    Fruit();

    /**
    * volume getter
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns volume
    */
    double getVolume() const;

    /**
    * volume setter
    * Requires: nothing
    * Modifies: volume
    * Effects: sets volume to v
    */
    void setVolume(double v);

    /**
    * pure virtual method
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns a string
    */
    virtual string makeJuice() = 0;

};

#endif //CS120PROJECT6_FRUIT_H
