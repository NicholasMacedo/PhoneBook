/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/

#include "linkedList.h"

/*
This function creates the list using a dummy head. It can be used by calling it and equaling it to the list you made.
*/
contactInfo * createList()
{
    contactInfo * dummyNode = malloc(sizeof(contactInfo)*1);
    dummyNode->firstName = "AAAAAAAAAAAA DUMMY NODE AAAAAAAAAAAAAAAAAA"; /* Puts dummy node at top of list during sorting. */
    dummyNode->lastName = NULL;
    dummyNode->phoneNum = NULL;
    dummyNode->xtraNum = 0;
    dummyNode->next = NULL;
    return(dummyNode);
}

/*
This function destroys the list. It can be used by calling it and giving it a pointer to the list.
*/
void destroyList (contactInfo * theList)
{
    if (theList == NULL)
    {
        printf("Error. NULL List. Returning.\n");
        return;
    }

    while (theList->next != NULL)
    {
        removeFromFront(theList);
    }
    free(theList);
    return;
}

/*
This function is used to add the given information to the front of the list. 
*/
contactInfo * addToFront(contactInfo * theList, char * phoneNum, char * firstName, char * lastName)
{
    contactInfo * newNode = initNode(phoneNum,firstName,lastName);
    if (theList == NULL)
    {
        printf("Error. Null List. Returning Null.\n");
        return(NULL);
    }

    newNode->next = theList->next;
    theList->next = newNode;
    theList->xtraNum ++;
    return(theList);
}

/*
This function is used to get the length of the list.
*/
int listLength(contactInfo * theList)
{   
    if (theList == NULL)
    {
        printf("Error. NULL List. Returning 0.\n");
        return(0);
    }

    return(theList->xtraNum);
}

/*
This function is used to add the given information to the back of the list. 
*/
contactInfo * addToList(contactInfo * theList, char * phoneNum, char * firstName, char * lastName)
{
    contactInfo * tailNode = malloc(sizeof(contactInfo)*1);
    contactInfo * newNode = initNode(phoneNum,firstName,lastName);
    
    if (theList == NULL)
    {
        printf("Error. NULL list. Returning NULL.\n");
        return(NULL);
    }

    tailNode = theList;

    while (tailNode->next != NULL)
    {
        tailNode = tailNode->next;
    }
    
    tailNode->next = newNode;
    theList->xtraNum ++;
    return(theList);
}

/*
This function is used to create a new node for the list.
*/
contactInfo * initNode( char * phoneNum, char * firstName, char * lastName)
{
    contactInfo * newNode;
    if (phoneNum == NULL && firstName == NULL && lastName == NULL)
    {
        printf("Null Node.\n");
    }
    newNode = malloc(sizeof(contactInfo)*1);
    newNode->firstName = firstName;
    newNode->lastName = lastName;
    newNode->phoneNum = phoneNum;
    newNode->xtraNum = 0;
    newNode->next = NULL;
    return(newNode);
}

/*
This function is used to remove the first node from the list.
*/
contactInfo * removeFromFront (contactInfo * theList)
{
    contactInfo * toBeRemoved;
    if (theList == NULL)
    {
        printf("Error. The list is NULL.\n");
        return(NULL);
    }
    else if (theList->next == NULL)
    {
        printf("Error. Retuning list. List is empty.\n");
        return(theList);
    }
    else
    {
        toBeRemoved = theList->next;
        theList->next = (theList->next)->next;
        free(toBeRemoved);
        theList->xtraNum --;
    } 
    return(theList);
}

/*
This function is used to print the list.
*/
void printList (contactInfo * theList)
{
    contactInfo * currListPos;
    
    if (theList == NULL)
    {
        printf("Error. NULL list. Returning.\n");
        return;
    }
    else if (theList->next == NULL)
    {
        printf("The List is empty. Returning.\n");
        return;
    }
    else
    {
        currListPos = theList->next;

        while (currListPos->next != NULL)
        {
            printf("%s %s (%s)\n",(currListPos->firstName),(currListPos->lastName),(currListPos->phoneNum));
            currListPos = currListPos->next;
        }

        printf("%s %s (%s)\n",(currListPos->firstName),(currListPos->lastName),(currListPos->phoneNum));
    }    
    return;
}
