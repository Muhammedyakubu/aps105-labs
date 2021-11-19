/*Author: Muhammed Al-Mustapha Yakubu
 * Student Number: 1007034013
 * Lab Purpose: Create a game of Blackjack*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char **argv)
{
    if(argc==1)
      srand(time(NULL));
        else
    srand(atoi(argv[1]));
    
    //Initializing variables
    int dealerCardValue, playerCardValue, hitOrStay, playerCardValue2;
    
    //Generating first cards for dealer and player
    int dealerCard = rand()%13 + 1;
    int playerCard = rand()%13 + 1;
	printf("First cards: player %d, dealer %d\n",playerCard,dealerCard);
    //Assigning values of 10 to cards 10,11,12, and 13
    if (dealerCard>=10){
        dealerCardValue = 10;
    }
    else {
        dealerCardValue = dealerCard;
    }
   if (playerCard>=10){
        playerCardValue = 10;
    }
    else {
        playerCardValue = playerCard;
    }
    
    //Player hit or stay loop 
    bool done;
    
    done = false;
    while(done==false){
        printf("Type 1 for Hit, 0 to Stay:");
        scanf("%d",&hitOrStay);
                
        if (hitOrStay==1){
            int playerCard2 = rand()%13 + 1;
            
            printf("Player gets a %d, worth is", playerCard2);
                if (playerCard2>=10){
                playerCardValue2 = 10;
                }
                else {
                playerCardValue2 = playerCard2;
                }
            playerCardValue = playerCardValue + playerCardValue2;
            
            printf(" %d\n", playerCardValue);
            
            done = false;
        }
        if (hitOrStay==0||playerCardValue>21){//computer does not check the second statement if the first is true
            done = true; 
        }
        else done = false;
    }
    if (playerCardValue>21){
        printf("Player over 21, Dealer wins\n");
        done = true;
    }
    else {
        int dealerCardValue2;
    
    //Dealer's cards
    
    printf("Dealer gets:");
    
    bool done2;
    
    done2 = false;
    while(done2 == false){        
       int dealerCard2 = rand()%13 + 1;
        
        printf(" %d",dealerCard2);
    
        if (dealerCard2>=10){
            dealerCardValue2 = 10;
        }        
        else{
            dealerCardValue2 = dealerCard2;
        }
            
        dealerCardValue = dealerCardValue + dealerCardValue2;
        if (dealerCardValue >=17){
            done2 = true;
        }        
        else {
        done2 = false;
        }
    }
    
    //Deciding game outcome by comparing dealerCardValue and playerCardValue
    if (dealerCardValue>21){
        printf("\nDealer over 21, Player wins\n");
    }else if (dealerCardValue>playerCardValue){
        printf("\nDealer better than Player, Dealer wins\n");
    }else if (playerCardValue>dealerCardValue){
            printf("\nPlayer better than Dealer, Player wins\n");
    }else{
                printf("\nTie!");
    }
    }
    return 0;
}
