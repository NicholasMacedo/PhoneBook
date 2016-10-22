#include <stdlib.h>
#include <stdio.h>

#ifndef _nmacedovContactInfo
#define _nmacedovContactInfo

/*
The list node holds the first name, last name and phone number to the contact.
It also holds an int for the dummy node as well as a pointer to the next list node.
*/
typedef struct contactInfo
{
    char * firstName;
    char * lastName;
    char * phoneNum;
    int xtraNum;
    struct contactInfo * next;
} contactInfo;

/*
 createList: Creates the dummy head of the list (Malloc) and assigns initial values for the dummy head.
 Pre: Takes in nothing.
 Post: Returns the pointer to the dummyNode.
*/
contactInfo * createList();

/**
 destroyList: Destroys the list and frees allocated memory.
 Pre: Takes in list head.
 Post: Returns nothing.
**/
void destroyList(contactInfo * theList);

/***
 addToList: Adds contact information given to back of the list.
 Pre: Takes in the list head and the contact information to be added.
 Post: Returns the list with added value to the list.
***/
contactInfo * addToList(contactInfo * theList, char * phoneNum, char * firstName, char * lastName);

/****
 addToFront: Adds contact information given to front of the list.
 Pre: Takes in list head and contact information to add to front.
 Post: Returns list head.
****/
contactInfo * addToFront(contactInfo * theList, char * phoneNum, char * firstName, char * lastName);

/******
 initNode: creates a list node from the given contact information.
 Pre: Takes in value of the node.
 Post: Returns pointer to the node.
******/
contactInfo * initNode( char * phoneNum, char * firstName, char * lastName);

/*******
 removeFromFront: removes the first node from the list and frees it (node after head).
 Pre: Takes in list head.
 Post: Returns list with removed and replaced first value.
*******/
contactInfo * removeFromFront(contactInfo * theList);

/********
 printList: Prints the list.
 Pre: Takes in list head.
 Post: Returns nothing.
********/
void printList(contactInfo * theList);

/*********
 listLength: Finds the length of the list.
 Pre: Takes in list head.
 Post: Returns length of list in an int.
*********/
int listLength(contactInfo * theList);

#endif
