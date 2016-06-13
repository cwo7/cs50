#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float owed;
    do
    {
    printf("How much do you owe?\n");
    owed = GetFloat();
    }
    while (owed < 0);                          //confirms the value is non-neg
    
    int owedInt = owed*100;                    //this sets the float value to an int so the program can work with it
    
    int leftovers = owedInt % 25;              //gets the remainder of cents before we divide it by quarters
    int quarters = (owedInt - leftovers) / 25; //gives us the amount of quarters needed
    
    int leftovers2 = leftovers % 10;           //this and the following few lines of code below do the
    int dimes = (leftovers - leftovers2) / 10; //same thing as the function below, just with different
                                               //coins
    int leftovers3 = leftovers2 % 5;
    int nickels = (leftovers2 - leftovers3) / 5;
    
    int leftovers4 = leftovers3 % 1;
    int pennies = (leftovers3 - leftovers4) / 1;
    
    int centTotal = quarters + dimes + nickels + pennies;
    float totalFloat = centTotal / 100;        //converts the total amount of cash back into $x.xx form
                                               //basically reverses what line 15 does
    
    printf("You need %d quarters, %d dimes, %d nickels, and %d pennies for a total of $%f\n", quarters, dimes, nickels, pennies, totalFloat);
    
}
