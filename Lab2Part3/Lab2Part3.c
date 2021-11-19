/*Author: Muhammed Al-Mustapha Yakubu
 * Student Number: 1007034013
 *Lab Purpose: Program that calculates the total amount in a bank account after t years given the initial 
 *deposit amount, annual interst rate and the number of times the money is compounded yearly */
 
#include <stdio.h> 
#include <math.h>

main()
{
    /*Declaring variables*/
    float initialAmount, interestRate, timeInvested, noTimesCompounded,finalAmount, finalAmount1, x, y, z;

	/*user prompting and input*/
    printf("The amount deposited P: ");
    scanf("%f", &initialAmount);
    printf("The interest rate r: ");
    scanf("%f", &interestRate);
    printf("The number of times the interest is compounded n: ");
    scanf("%f", &noTimesCompounded);
    printf("The period of time t the money is invested (in years): ");
    scanf("%f", &timeInvested);

	/*Calculating final amount*/
    x = 1 + interestRate/noTimesCompounded;/*(1+r/n). x is an intermediate variable*/
    y = pow(x,noTimesCompounded*timeInvested);/*(1+r/n)^nt. y is also an intermediate variable*/
    finalAmount = initialAmount*y;/*P(1+r/n)^nt*/

	/*output*/
    printf("The future value of the investment A: %.2f\n", finalAmount);
}