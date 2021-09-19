#include <iostream>
#include "Fruit.h"
#include "Apple.h"
#include "Lime.h"
using namespace std;

double calculateTotalVolume(vector<Fruit*> pointers);

int main() {
    Apple a; //Create an object of type Apple.
    Lime l; //Create an object of type Lime.
    Apple* applePointer = &a; //Create a pointer to an object of type Apple and make it point to the address of a.
    Lime* limePointer = &l; //Create a pointer to an object of type Lime and make it point to the address of l.
    vector<Fruit*> pointers; //Create a vector of pointers to objects of type Fruit.
    double appleVolume; //Create a double to hold the appleVolume value which will be entered by the user.
    double limeVolume; //Create a double to hold the limeVolume value which will be entered by the user.
    double userVolume; //Create a double to hold the userVolume value which will be the total of the previous 2 values.
    char userChar;

    pointers.push_back(applePointer); //Add the applePointer to the vector.
    pointers.push_back(limePointer); //Add the limePointer to the vector.
    cout << "Run this program in debug mode in CLion." << endl;
    for (int i = 0; i < pointers.size(); i++) //Loop over the vector and call the makeJuice() method many times.
    {
        cout << pointers[i]->makeJuice() << endl; //Use the arrow operator.
    }
    double result = calculateTotalVolume(pointers); //Calculate the total volume and store the result.
    cout << "The total combined default volume for all of the fruit is ";
    cout << result;
    cout << " centimeters cubed." << endl; //Print the total volume.
    do { //Use a do-while loop to continue to prompt the user for input until it is valid.
    cout << "Enter the volume for the apple (in centimeters cubed): "; //Interact with the user.
    cin >> appleVolume;
    if (appleVolume <= 0)
    {
        cout << "The value that is entered must be greater than 0." << endl;
    }
    } while (appleVolume <= 0);
    do {
        cout << "Enter the volume for the lime (in centimeters cubed): ";
        cin >> limeVolume;
        if (limeVolume <= 0)
        {
            cout << "The value that is entered must be greater than 0." << endl;
        }
    } while (limeVolume <= 0);
    userVolume = appleVolume + limeVolume; //Calculate the total userVolume.
    cout << "The total volume for both of the fruits combined is (as chosen by the user): ";
    cout << userVolume << "." << endl;
    cout << "You will now receive advice on how to make juice.  Also, the chef will judge your fruit." << endl;
    do {
        cout << "Enter the first character of the fruit for which you would like to make juice: (a)pple or (l)ime: ";
        cin >> userChar;
        if (userChar != 'a' && userChar != 'l')
        {
            cout << "The character that is entered must be either a or l." << endl;
        }
    } while (userChar != 'a' && userChar != 'l');
    if (userChar == 'a') //Determine the output based on the character that the user entered.
    {
        cout << a.makeJuice() << endl;
        cout << "The chef does not like apples." << endl;
    }
    else if (userChar == 'l')
    {
        cout << l.makeJuice() << endl;
        cout << "The chef likes limes." << endl;
    }

    return 0;
}

double calculateTotalVolume(vector<Fruit*> pointers) //Create a global function to calculate the total volume.
{
    double totalVolume = 0;
    for (int i = 0; i < pointers.size(); i++) //Loop over the vector.
    {
        totalVolume += pointers[i]->getVolume(); //Use the arrow operator.
    }
    return totalVolume;
}
