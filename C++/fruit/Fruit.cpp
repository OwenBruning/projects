//
// Created by Owen on 3/29/2018.
//

#include "Fruit.h"

Fruit::Fruit()
{
    volume = 100.0; //Note that the volume is in centimeters cubed.
}

double Fruit::getVolume() const
{
    return volume;
}

void Fruit::setVolume(double v)
{
    volume = v;
}
