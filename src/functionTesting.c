#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "phoneBook.h"
#include "hashTableADT.h"

int main (int argc,char * argv[])
{
    int returnNum = 0;
    FILE * filePointer1 = openFile (argv[1]);
    FILE * filePointer2;    
    char * fileLine = malloc(sizeof(char)*150); /* Creation of needed variables. */
    char * snewFirstName = malloc(sizeof(char)*51);
    char * snewLastName = malloc(sizeof(char)*51);
    char * snewPhoneNumber = malloc(sizeof(char)*10);
    char * snewFirstName1 = malloc(sizeof(char)*51);
    char * snewLastName1 = malloc(sizeof(char)*51);
    char * snewPhoneNumber1 = malloc(sizeof(char)*10);
    char * bnewFirstName = malloc(sizeof(char)*51);
    char * bnewLastName = malloc(sizeof(char)*51);
    char * bnewPhoneNumber = malloc(sizeof(char)*10);
    char * bnewFirstName1 = malloc(sizeof(char)*51);
    char * bnewLastName1 = malloc(sizeof(char)*51);
    char * bnewPhoneNumber1 = malloc(sizeof(char)*10);
    char * testNumber = malloc(sizeof(char)*10);
    char * fakeTestNumber = malloc(sizeof(char)*10);
    contactInfo * lookedUp = NULL;
    char * firstName;
    char * lastName;
    char * phoneNum;
    contactInfo * smallTestList = createList ();
    contactInfo * bigTestList = createList ();
    hashNode * smallTestHTable;
    hashNode * bigTestHTable;
    hashNode * nullHTable = NULL;
    int tableSize;
    int keyValue = 0;

    snewFirstName = "Nicholas"; /* Assigning Value to needed variables. */
    snewLastName = "Macedo";
    snewPhoneNumber = "1234554321";

    bnewFirstName = "Nicholas";
    bnewLastName = "Macedo";
    bnewPhoneNumber = "1234554321";

    snewFirstName1 = "Test";
    snewLastName1 = "Name";
    snewPhoneNumber1 = "1201101021";

    bnewFirstName1 = "Test";
    bnewLastName1 = "Name";
    bnewPhoneNumber1 = "1201101021";

    testNumber = "0098268469";
    fakeTestNumber = "1234554321";

    nullHTable = nullHTable;


    /*Loops through the first file until end of file and parses information*/
    while (fgets(fileLine, 150, filePointer1) != NULL)
    {
        fileLine = removeNewline (fileLine);
        phoneNum = malloc(sizeof(char)*10);
        firstName = malloc(sizeof(char)*51);
        lastName = malloc(sizeof(char)*51);
        sscanf(fileLine,"%[^,],%[^,],%s", firstName, lastName, phoneNum);
        /*printf("B4: %s %s (%s) \nNext\n", firstName, lastName, phoneNum);*/
        smallTestList = addToList (smallTestList,phoneNum,firstName,lastName);
        /*printf("AFTR: %s %s (%s) \nNext\n", firstName, lastName, phoneNum);*/
    }
    fclose(filePointer1);
    filePointer2 = openFile (argv[2]);
    /* Loops through the second file until end of file and parses information. */
    while (fgets(fileLine, 150, filePointer2) != NULL)
    {
        fileLine = removeNewline (fileLine);
        phoneNum = malloc(sizeof(char)*10);
        firstName = malloc(sizeof(char)*51);
        lastName = malloc(sizeof(char)*51);
        sscanf(fileLine,"%[^,],%[^,],%s", firstName, lastName, phoneNum);
        bigTestList = addToList (bigTestList,phoneNum,firstName,lastName);
    }
    fclose(filePointer2);
    smallTestList = sortList (smallTestList);
    printf("\t **Printing Small Test Setup List**\n");
    printList (smallTestList);
    /*printf("List Length: %d\n",listLength(contactList));*/

    tableSize = getTableSize (smallTestList); /* Create Small Test Hash Table. */
    /*printf("Table Size: %d\n",tableSize);*/
    smallTestHTable = createHTable (tableSize);

    smallTestHTable = fillContactHTable (smallTestHTable,smallTestList,tableSize);
    printf("\t***Printing Small Test Setup Table Info***\n");
    printHTable (smallTestHTable,tableSize);

     bigTestList = sortList (bigTestList);
    printf("\t **Printing Big Test Setup List**\n");
    printList (bigTestList);
    /*printf("List Length: %d\n",listLength(contactList));*/

    tableSize = getTableSize (smallTestList);    /* Create Big Test Hash Table. */
    /*printf("Table Size: %d\n",tableSize);*/
    bigTestHTable = createHTable (tableSize);

    bigTestHTable = fillContactHTable (bigTestHTable,bigTestList,tableSize);
    printf("\t***Printing Big Test Setup Table Info***\n");
    printHTable (bigTestHTable,tableSize);
 

    /*Testing Hash Table ADT Functions (Look at prints to follow whats happening.)*/
    printf("\n\t**** Hash Table ADT Function Testing Begins****\n");

    /* Testing insert */
    printf("**Beginning Testing: insert (hashTableADT).**\n");
    printf("*Testing Null Case*\n");
    nullHTable = insert (NULL,NULL,keyValue);
    printf("*Testing Big Table Case*\n");
    printf("Tested when adding the info into the Hash Table. (Look at above table print out.)\n");
    printf("*Testing Small Table Case*\n");
    printf("Tested when adding the info into the Hash Table. (Look at above table print out.)\n");
    printf("**Ending Testing: insert (hashTableADT).**\n\n");  

    /* Testing loopUp */
    printf("**Beginning Testing: lookUp (hashTableADT).**\n");
    printf("*Testing Null Case*\n");
    lookedUp = lookUp (NULL,0,NULL);
    printf("*Testing Unavilable Key*\n");
    tableSize = getTableSize (bigTestList);
    keyValue = createKey (testNumber,tableSize);
    lookedUp = lookUp (bigTestHTable,keyValue,fakeTestNumber);
    printf("The contact with phone number (%s) does not exist.\n",fakeTestNumber);
    printf("*Testing Available Key*\n");
    tableSize = getTableSize (smallTestList);
    keyValue = createKey (testNumber,tableSize);
    lookedUp = lookUp (smallTestHTable,keyValue,testNumber);
    printf("The name of the contact with phone number (%s): ",testNumber);
    printf("%s %s\n",(lookedUp->firstName),(lookedUp->lastName));
    printf("**Ending Testing: lookUp (hashTableADT).**\n\n"); 

    /* Testing removeInfo */
    printf("**Beginning Testing: removeInfo (hashTableADT).**\n");
    printf("*Testing Null Case*\n");
    nullHTable = removeInfo (NULL,4);
    printf("*Testing Big Table Case*\n");
    bigTestHTable = removeInfo (bigTestHTable,4);
    tableSize = getTableSize (smallTestList);
    printf("Removed Successfully.\n");
    printf("*Testing Small Table Case*\n");
    smallTestHTable = removeInfo (smallTestHTable,6);
    tableSize = getTableSize (smallTestList);
    printf("Removed Successfully.\n");
    printf("**Ending Testing: removeInfo (hashTableADT).**\n\n"); 

    /* Testing printHTable */
    printf("**Beginning Testing: printHTable (hashTableADT).**\n");
    printf("*Testing Null Case*\n");
    printHTable (NULL,0);
    printf("**Ending Testing: printHTable (hashTableADT).**\n\n");
 
    /* Testing createKey */
    printf("**Beginning Testing: createKey (hashTableADT).**\n");
    printf("*Testing Null Case*\n");
    keyValue = createKey (NULL,0);
    printf("**Ending Testing: createKey (hashTableADT).**\n\n"); 

    /* Testing Linked List Functions */
    printf("\n\t**** Linked List ADT Function Testing Begins****\n");

    /* Testing removeFromFront */
    printf("**Beginning Testing: removeFromFront (linkedListADT).**\n");
    printf("*Testing Null Case*\n");
    removeFromFront (NULL);
    printf("*Testing Big List Case*\n");
    removeFromFront (bigTestList);
    printList (bigTestList);
    printf("*Testing Small List Case*\n");
    removeFromFront (smallTestList);
    printList (smallTestList);
    printf("**Ending Testing: removeFromFront (linkedListADT).**\n\n");

    /* Testing listLength */
    printf("**Beginning Testing: listLength (linkedListADT).**\n");
    printf("*Testing Null Case*\n");
    listLength (NULL);
    printf("Value: %d\n",returnNum);
    printf("*Testing Big List Case*\n");
    returnNum = listLength (bigTestList);
    printf("Value: %d\n",returnNum);
    printf("*Testing Small List Case*\n");
    returnNum = listLength (smallTestList);
    printf("Value: %d\n",returnNum);
    printf("**Ending Testing: listLength (linkedListADT).**\n\n");

    /* Testing addToList */
    printf("**Beginning Testing: addToList (linkedListADT).**\n");
    printf("*Testing Null Case*\n");
    addToList(NULL,NULL,NULL,NULL);
    printf("*Testing Big List Case*\n");
    addToList (bigTestList,bnewPhoneNumber,bnewFirstName,bnewLastName);
    printList (bigTestList);
    printf("*Testing Small List Case*\n");
    addToList (smallTestList,snewPhoneNumber,snewFirstName,snewLastName);
    printList (smallTestList);
    printf("**Ending Testing: addToList (linkedListADT).**\n\n");
 
    /* Testing addToFront */
    printf("**Beginning Testing: addToFront (linkedListADT).**\n");
    printf("*Testing Null Case*\n");
    addToFront (NULL,NULL,NULL,NULL);
    printf("*Testing Big List Case*\n");
    addToFront (bigTestList,bnewPhoneNumber1,bnewFirstName1,bnewLastName1);
    printList (bigTestList);
    printf("*Testing Small List Case*\n");
    addToFront (smallTestList,snewPhoneNumber1,snewFirstName1,snewLastName1);
    printList (smallTestList);
    printf("**Ending Testing: addToFront (linkedListADT).**\n\n");  

    /* Testing initNode */
    printf("**Beginning Testing: initNode (linkedListADT).**\n");
    printf("*Testing Null Case*\n");
    initNode (NULL,NULL,NULL);
    printf("**Ending Testing: initNode (linkedListADT).**\n\n");

    printf("**Beginning Testing: printList (linkedListADT).**\n");
    printf("*Testing Null Case*\n");
    printList (NULL);
    printf("**Ending Testing: printList (linkedListADT).**\n\n");

    /* Testing Program specific functions (phoneBook.c) */
    printf("\n\t**** Program Specific Function Testing Begins****\n");
    printf("Due to the use of these functions in the above code, the functions shall only be tested for null cases.\n");

    /* Testing sortList */
    printf("**Beginning Testing: sortList.**\n");
    printf("*Testing Null Case*\n");
    lookedUp = sortList (NULL);
    printf("**Ending Testing: sortList.**\n\n");

    /* Testing getTableSize */
    printf("**Beginning Testing: getTableSize.**\n");
    printf("*Testing Null Case*\n");
    tableSize = getTableSize (NULL);
    printf("**Ending Testing: getTableSize.**\n\n");

    /* Testing programMenu */
    printf("**Beginning Testing: programMenu.**\n");
    printf("*Testing Null Case*\n");
    programMenu (NULL,NULL);
    printf("**Ending Testing: programMenu.**\n\n");

    /* Testing fillContactHTable */
    printf("**Beginning Testing: fillContactHTable.**\n");
    printf("*Testing Null Case*\n");
    nullHTable = fillContactHTable (NULL,NULL,0);
    printf("**Ending Testing: fillContactHTable.**\n\n");

    /* Testing destroyList */
    printf("**Beginning Testing: destroyList (linkedListADT).**\n");
    printf("*Testing Null Case*\n");
    destroyList (NULL);
    destroyList (smallTestList);
    destroyList (bigTestList);
    printf("**Ending Testing: destroyList (linkedListADT)**\n");

    /* Testing destroyHTable */
    printf("**Beginning Testing: destroyHTable (hash Table ADT).**\n");
    printf("*Testing Null Case*\n");
    destroyHTable (NULL);
    destroyHTable (smallTestHTable);
    destroyHTable (bigTestHTable);
    printf("**Ending Testing: destroyHTable (linkedListADT)**\n");
    printf("\t****End of Individual Function Testing****\n");
    return(0);
}
