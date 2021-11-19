/*Author: Muhammed Al-Mustapha Yakubu
 * Student Number: 1007034013
 *Lab Purpose: Program that outputs the total charge and savings on a promotion which gives 10 cents cashback for every three dollars spent*/
 
#include <stdio.h> 
#include <math.h>

main()
{
	/*Declaring veriables*/
	float pricePerPound, totalWeight, initialCharge, cashBack, finalCharge, totalSavings;
    int initialChargeFloor;
    
	/*User prompts and input*/
    printf("Enter the price per pound: ");
    scanf("%f",&pricePerPound);
    printf("Enter the total weight: ");
    scanf("%f",&totalWeight);
    initialCharge = pricePerPound*totalWeight;/*Charge without promo*/

	/*Computing the cashback*/
    initialChargeFloor = floorf(initialCharge);
    cashBack = 0.1*(initialChargeFloor - initialChargeFloor%3)/3;
 
	/*outputing final charge*/
    finalCharge = initialCharge - cashBack;
    printf("The total charge is: %.2f\n", finalCharge);
}
