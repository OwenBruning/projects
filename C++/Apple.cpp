//
// Created by Owen on 3/29/2018.
//

#include "Apple.h"

Apple::Apple()
{
    hasStem = true;
}

bool Apple::getHasStem() const
{
    return hasStem;
}

void Apple::setHasStem(bool b)
{
    hasStem = b;
}

string Apple::makeJuice()
{
    return "To make apple juice, you will need a machine.";
}