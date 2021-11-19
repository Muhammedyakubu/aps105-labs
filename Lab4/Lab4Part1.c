/*Author: Muhammed Al-Mustapha Yakubu
 * Student Number: 1007034013
 *Lab Purpose: Making Change */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    int centInput,quarter,dime,nickel,centOutput;
    
    bool done;
    
    done = false;
    while(done==false){
        printf("Please give an amount in cents less than 100: ");
        scanf("%d",&centInput);
        if ( centInput>0 && centInput<100){
            quarter= centInput/25;
            dime = (centInput%25)/10;
            nickel = (centInput - dime*10 - quarter*25)/5;
            centOutput = (centInput%5);

            printf("%d cents:",centInput);
                        
            //Decision making module 
            //quarters
            if (quarter>1){
                printf(" %d quarters",quarter);
            }else if (quarter==1){
                printf(" %d quarter",quarter);
            }
            
            //dimes
            if (quarter==0){
                if (dime>1){
                printf(" %d dimes",dime);
                }else if (dime==1){
                printf(" %d dime",dime);
                }
            }else{
             if (dime>1){
                printf(", %d dimes",dime);
            }else if (dime==1){
                printf(", %d dime",dime);
            }            
            }
            
            //nickels
            if (dime==0 && quarter==0){
                if (nickel>1){
                printf(" %d nickels",nickel);
                }else if (nickel==1){
                printf(" %d nickel",nickel);
                }
            }else{
             if (nickel>1){
                printf(", %d nickels",nickel);
            }else if (nickel==1){
                printf(", %d nickel",nickel);
            }
            }
            
            //centoutput
            if (dime==0 && quarter==0 && nickel==0){
                if (centOutput>1){
                printf(" %d cents",centOutput);
                }else if (centOutput==1){
                printf(" %d cent",centOutput);
                }
            }else{
             if (centOutput>1){
                printf(", %d cents",centOutput);
            }else if (centOutput==1){
                printf(", %d cent",centOutput);
            }
            }
            
            printf(".\n");
            
        }else{
            printf("Goodbye\n");
            done = true;
        }
    }
	return 0;
}
