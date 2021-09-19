//
// Created by Owen on 3/30/2018.
//

#include <iostream>
#include "Fruit.h"
#include "Apple.h"
#include "Lime.h"
using namespace std;

bool testApple();
bool testLime();

int main()
{
    if (testApple())
        cout << "The Apple class passed testing." << endl;
    if (testLime())
        cout << "The Lime class passed testing." << endl;

    return 0;
}

bool testApple()
{
    bool passed = true;
    Apple a;

    if (a.getVolume() != 100.0)
    {
        passed = false;
        cout << "The default constructor test failed for the Apple class." << endl;
    }

    a.setVolume(50.0);
    if (a.getVolume() != 50.0)
    {
        passed = false;
        cout << "The volume settter test failed for the Apple class." << endl;
    }

    if (a.getHasStem() != true)
    {
        passed = false;
        cout << "The default constructor test failed for the Apple class." << endl;
    }

    a.setHasStem(false);
    if (a.getHasStem() != false)
    {
        passed = false;
        cout << "The hasStem settter test failed for the Apple class." << endl;
    }

    return passed;
}

bool testLime()
{
    bool passed = true;
    Lime l;

    if (l.getVolume() != 100.0)
    {
        passed = false;
        cout << "The default constructor test failed for the Lime class." << endl;
    }

    l.setVolume(50.0);
    if (l.getVolume() != 50.0)
    {
        passed = false;
        cout << "The volume setter test failed for the Lime class." << endl;
    }

    if (l.getHasStem() != false)
    {
        passed = false;
        cout << "The default constructor test failed for the Lime class." << endl;
    }

    l.setHasStem(true);
    if (l.getHasStem() != true)
    {
        passed = false;
        cout << "The hasStem settter test failed for the Lime class." << endl;
    }

    return passed;
}
