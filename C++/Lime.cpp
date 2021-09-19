//
// Created by Owen on 3/29/2018.
//

#include "Lime.h"

Lime::Lime()
{
    hasStem = false;
}

bool Lime::getHasStem() const
{
    return hasStem;
}

void Lime::setHasStem(bool b)
{
    hasStem = b;
}

string Lime::makeJuice()
{
    return "To make lime juice, you could squeeze some limes.";
}
