/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "phoneBook.h"
#include "hashTableADT.h"

int main (int argc,char * argv[])
{
    FILE * filePointer = openFile (argv[1]);    
    char * fileLine = malloc(sizeof(char)*150);
    char * firstName;
    char * lastName;
    char * phoneNum;
    contactInfo * contactList = createList ();
    hashNode * contactHTable;
    int tableSize;
    /*Loops through the file until end of file and parses information*/
    while (fgets(fileLine, 150, filePointer) != NULL) /* Loop to read in information from file and parse it. */
    {
        fileLine = removeNewline (fileLine);
        phoneNum = malloc(sizeof(char)*10);
        firstName = malloc(sizeof(char)*51);
        lastName = malloc(sizeof(char)*51);
        sscanf(fileLine,"%[^,],%[^,],%s", firstName, lastName, phoneNum);
        /*printf("B4: %s %s (%s) \nNext\n", firstName, lastName, phoneNum);*/
        contactList = addToList (contactList,phoneNum,firstName,lastName); /* Add contact info to list and sort the list. */
        /*printf("AFTR: %s %s (%s) \nNext\n", firstName, lastName, phoneNum);*/
        contactList = sortList (contactList);
    }
    fclose(filePointer);
    /*contactList = sortList(contactList);*/
    /*printList(contactList);
    printf("List Length: %d\n",listLength(contactList));*/

    tableSize = getTableSize (contactList); /* Get the size of table and create table. */
    /*printf("Table Size: %d\n",tableSize);*/
    contactHTable = createHTable (tableSize);

    /* Fill the table witht the contact information. */
    contactHTable = fillContactHTable (contactHTable,contactList,tableSize);
    /*printf("***Printing Table Info***\n");
    printHTable (contactHTable,tableSize); */
    
    /* Start program menu once setup of linked list and hash table are complete. */
    programMenu (contactHTable,contactList);

    free(fileLine);
    destroyHTable (contactHTable);
    destroyList (contactList);
    return(0);
}
