/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"

#ifndef _nmacedovHashTable
#define _nmacedovHashTable

/*
This hash table node holds a number and a list.
The number is how many entries are in the list.
The list node holds the points to the contact information.
*/
typedef struct hashTableNode
{
    int numEntry;
    contactInfo * infoList;
} hashNode;

/*
 createHTable: Creates the array for the hash table (Malloc) and assigns initial values for each array location.
 Pre: Takes in the size of the table.
 Post: Returns the malloced hash table array.
*/
hashNode * createHTable(int size);

/*
 destroyHTable: Frees the allocated memory in the hash table.
 Pre: Takes in the hash table.
 Post: Returns nothing (void) .
*/
void destroyHTable (hashNode * hashTable);

/*
 insert: Inserts the given list node into the list spot of the given key value.
 Pre: Takes in the hash table, list node and the key value.
 Post: Returns the hash table with newly added node.
*/
hashNode * insert(hashNode * hashTable,contactInfo * entry,int keyValue);

/*
 lookUp: Uses the given phoneNumber to check to see if the entry exists.
 Pre: Takes in the hash table, key value and phone number.
 Post: Returns pointer to contact info.
*/
contactInfo * lookUp(hashNode * hashTable, int keyValue, char * phoneNumber);

/*
 removeInfo: Removes all the information from the given key value.
 Pre: Takes in the hash table as well as the key value it will remove.
 Post: Returns the hash table with removed information.
*/
hashNode * removeInfo(hashNode * hashTable, int keyValue);

/*
 createKey: Creates the key value for the table using the phone number.
 Pre: Takes in the phone number it will convert and the table size.
 Post: Returns the key vale.
*/
int createKey(char * phoneNumber,int tableSize);

/*
 printHTable: prints the hash table's contents to the screen.
 Pre: Takes in the hash table.
 Post: Returns nothing (void).
*/
void printHTable (hashNode * hashTable,int size);

#endif
