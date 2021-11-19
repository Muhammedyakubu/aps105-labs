#include <stdio.h>

int main(int argc, char **argv)
{
    int numberOfRows,currentRow;
    printf("Enter the number of rows in the triangle: ");
    scanf("%d",&numberOfRows);
    
    //first line
    //Number of spaces before the first star
    for (int i=1; i<numberOfRows; i++)
    {
    printf(" ");	   
    }
    
    printf("*\n");
    
    //subsequent rows
        
    if (numberOfRows>1){
        for (int currentRow=2; currentRow<numberOfRows;currentRow++)
        {
            //Printing the spaces before the first star on each row
            int spacesBefore = numberOfRows-currentRow;
            for (int j=1;j<=spacesBefore;printf(" "),j++);
                       
            printf("*");
            
            //Printing spaces between the two stars on the same row
            int spacesBetween=2*currentRow-3;
            
            for (int l=1;l<=spacesBetween;printf(" "),l++);
                    
            printf("*\n");            
        }
        
        //Printing the stars on the last row
        for (int k=0;k<(2*numberOfRows-1);k++)
        {
            printf("*");
        }
        printf("\n");
    }
	return 0;
}
