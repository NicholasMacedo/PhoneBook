/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"
#include "hashTableADT.h"

#ifndef _nmacedovA2
#define _nmacedovA2

/*
 openFile: Opens the given file name.
 Pre: Takes in name of the file.
 Post: Returns pointer to the file.
*/
FILE * openFile(char * fileName);

/*
 removeNewline: Removes the new line from a given string.
 Pre: Takes in a pointer to a string.
 Post: Returns the pointer to the string without a new line character.
*/
char * removeNewline(char* fileLine);

/*
 sortList: Sorts the given list in alphabetical order.
 Pre: Takes in the list it is to sort.
 Post: Returns the sorted list.
*/
contactInfo * sortList(contactInfo * contactList);

/*
 swapNode: Used in sortList to swap the posistions of the nodes.
 Pre: Takes in list node.
 Post: Returns pointer to list node.
*/
contactInfo * swapNode( contactInfo *ptr1 );

/*
 fillContactHTable: Fills the hash table using the given list.
 Pre: Takes in the hash table, list node and size of the table.
 Post: Returns the hash table with information in it.
*/
hashNode * fillContactHTable(hashNode * hashTable,contactInfo * contactList,int tableSize);

/*
 programMenu: The hub of the program that displays the menu to the user and preforms all of the tasks.
 Pre: Takes in hash table and contact list.
 Post: Returns nothing (void).
*/
void programMenu(hashNode * hashTable,contactInfo * contactList);

/*
 getTableSize: Determines the size of the table using the linked list (listLen * 0.66 - 1).
 Pre: Takes in contact list.
 Post: Returns the size of the table.
*/
int getTableSize(contactInfo * contactList);

#endif
