//
// Created by Owen on 3/29/2018.
//

#ifndef CS120PROJECT6_LIME_H
#define CS120PROJECT6_LIME_H
#include "Fruit.h"
#include <vector>

class Lime : public Fruit {
private:

    /**
    * whether or not the lime has a stem
    * Requires: nothing
    * Modifies: nothing
    * Effects: nothing
    */
    bool hasStem;

public:
    /**
    * default constructor
    * Requires: nothing
    * Modifies: nothing
    * Effects: sets hasStem to false
    */
    Lime();

    /**
    * hasStem getter
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns hasStem
    */
    bool getHasStem() const;

    /**
    * hasStem setter
    * Requires: nothing
    * Modifies: hasStem
    * Effects: sets hasStem to b
    */
    void setHasStem(bool b);

    /**
    * method to override
    * Requires: nothing
    * Modifies: nothing
    * Effects: overrides the method and returns a string
    */
    string makeJuice() override;
};

#endif //CS120PROJECT6_LIME_H
