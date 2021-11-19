/*Author: Muhammed Al-Mustapha Yakubu
 * Student Number: 1007034013
 *Lab Purpose: Program that rounds grocery price to the nearest nickel*/
 
#include <stdio.h> 
#include <math.h>

main()
{
    /*Declaring variables*/
    float initialCharge, twentyxRoundedCharge, finalCharge;

	/*user prompts and input*/
    printf("Enter the price as a float with two decimals: ");
    scanf("%f", &initialCharge);

	/*rounding to nearest nickel and final output*/
    twentyxRoundedCharge = round(initialCharge*20);
    finalCharge = twentyxRoundedCharge/20;
    printf("The total charge is: %.2f\n", finalCharge);
}