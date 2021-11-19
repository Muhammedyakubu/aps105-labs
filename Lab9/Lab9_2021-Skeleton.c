#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactList.h"
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

// IF IT'S EASIER, YOU NEED NOT BE OVERLY GENERAL/FLEXIBLE
// BUT CAN ASSUME THESE LIMITS
#define MAXCONTACTS 30 /* max # of contacts */
#define MAXPHONES 10 /* max # of phone numbers for each contact */

#define PHONE_NUMBER_MAX_LENGTH 12

typedef struct contacts{
    char *name;
    char **phoneNumbers;
    int phoneLength;//number of numbers
    struct contacts *next;
}contact;

// INCLUDE YOUR OWN "HELPER" ROUTINES AS YOU SEE FIT
contact *addContact (contact *head, int index);

void ListAllContacts(contact *head)
{
   contact *cur = head;
   while (cur != NULL) {
       printf("Name: %s\nPhone(s):",cur->name);
       for (int i = cur->phoneLength; i > 0; i--) 
           printf(" %s", cur->phoneNumbers[i-1]);
        printf("\n");
        cur = cur->next;
   }
}



int contactListLength() {
    return sizeof(contactList) / sizeof(contactList[0]);
}


/*
 * convertInputToDataStructure
 * Takes the information in contactList.h and puts it into a data
 * structure of your choosing, however: 1 mark of the lab will be
 * for using structs with pointers in your solution.
 * You might also want to consider the outputs from the program
 * (see the menu printed in printMenu) since some structures will
 * make this easier than others.
 */
contact *convertInputToDataStructure(contact *head) {

   int index = 0;
    
    while (index < contactListLength()) {
       if (!atoi(contactList[index])) 
           head = addContact (head, index);

        index++;
   }
    return head;
}

contact *addContact (contact *head, int index) {
    contact *cur = head, *pre = NULL;
    contact *entry = malloc(sizeof(struct contacts));
    entry->next = NULL;
    entry->name = strdup(contactList[index]);
    index++;
    
    entry->phoneLength = 0;
  
    while (index < contactListLength() && atoi(contactList[index])) {
        index++; 
        entry->phoneLength++;
    }
    index -= entry->phoneLength;
    
    char **pN = malloc(sizeof(char *) * (entry->phoneLength + 1));
    entry->phoneNumbers = pN;
    
    for (int i = 0; i < entry->phoneLength; i++, index++) {
        pN[i] = strdup(contactList[index]);
    }
    index -= entry->phoneLength;
    
    //sorting module here
    
    if (index == 1) //First contact
        return entry;
        
    else if (index == 2 + head->phoneLength) {//second contact
        if (strcmp(head->name, entry->name)==1) {
            entry->next = head;
            head->next = NULL;
            return entry;
        }   else {
                head->next = entry;
                return head;
        }
    }
    
        while (cur != NULL && strcmp(entry->name, cur->name) > 0) {
        pre = cur;
        cur = cur->next;
    }//loop stops right when entry precedes cur alphabetically

    //end of sorting module
    entry->next = cur;

    if (pre == NULL)
        head = entry;
        else pre->next = entry;
        
    return head;
}

/*
 * printMenu - Prints out the user menu
 */
void printMenu() {
   printf("\n\nEnter a command by number\n");
   printf("1. List all contacts in alphabetical order\n");
   printf("2. Print phone(s) for a contact\n");
   printf("3. Find duplicate entries\n");
   printf("4. Delete contact\n");
   printf("5. Exit the program\n");
   printf("Your input: ");
}

//eliminate trailing \n
char* rtrim(char* str)
{
   int i;
   for (i = strlen(str) - 1; i >= 0 && str[i] == '\n'; i--)
      str[i] = '\0';
   return str;
}

void PrintContact(contact *head) {
    printf("Enter name: ");
    char input[256];
    fgets(input, sizeof(input), stdin);
    strcpy( input, rtrim(input));
    printf("\n");
    contact *cur = head; 
    while (cur != NULL && strcmp(cur->name, input) != 0) {
        cur = cur->next;
    }
    if (cur == NULL)
        puts("Contact not found");
        else {
            printf("Name: %s\n",cur->name);
            printf("Phone(s): ");
            for (int i = cur->phoneLength; i > 0; i--) 
                printf("%s ",cur->phoneNumbers[i - 1]);
        }
}


/*
 * DeleteContact deletes a contact from the list
 * The user must enter the name of the contact to delete
 * 
 */

contact *DeleteContact(contact *head) {
    contact *cur = head, *pre = NULL;
    char input[256];
    printf("Enter name: ");
    fgets(input, sizeof(input), stdin);
    strcpy( input, rtrim(input));
    while ( cur != NULL && strcmp(cur->name, input)) {
        pre = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        puts("Contact not found");
        else {
            if (pre != NULL)
                pre->next = cur->next;
                else head = cur->next;
            free(cur->name);
            free(cur->phoneNumbers);
            free(cur);
        }
    return head;
}


/*
 * findDuplicates finds the names of contacts with 
 * a phone number in common
 */

void FindDuplicates(contact *head) {
    contact *cur = head, *temp = head->next;
    char *curPhone;
    while (cur->next != NULL) {
        for (int i = 0; i < cur->phoneLength; i++) {
            temp = cur->next;
            curPhone = cur->phoneNumbers[i];
            while ( temp->next != NULL) {
                for (int j = 0; j < temp->phoneLength; j++) 
                    if (strcmp(curPhone, temp->phoneNumbers[j]) == 0)
                        printf("%s and %s have a phone number in common\n",cur->name, temp->name);
                temp = temp->next;
            }
        }
        cur = cur->next;
    }
}

int main()
{
   // first move data from contactList.h to a data structure
    contact *head = malloc(sizeof(struct contacts));
    head = convertInputToDataStructure(head);

   char notDone = 1;
   while (notDone) {
      printMenu();
      char userChoice[100];
      char* s = fgets(userChoice, sizeof(userChoice), stdin);
      if (!s)
      {
         printf("Wrong input\n");
         continue;
      }
      s = rtrim(s); /* eliminate trailing \n */
      //printf("selection = %s\n", s);
      int userSelection = atoi(s);

      switch (userSelection) {
         case 1: ListAllContacts(head); break;
         case 2: PrintContact(head); break;
         case 3: FindDuplicates(head); break;
         case 4: head = DeleteContact(head); break;
         case 5: notDone = 0; break;
         default: printf("Bad command...\n"); break;
         }
   }
   
   contact *ptr = head, *pret;
     while (ptr != NULL){
         pret = ptr; 
         ptr = ptr->next;
         free (pret);
     }
     
   return 0;
}
