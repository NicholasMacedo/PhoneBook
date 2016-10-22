#include "hashTableADT.h"
#include "linkedList.h"

/*
This function creates the list using a dummy head. It can be used by calling it and equaling it to the list you made.
*/
hashNode * createHTable (int size)
{
    int i = 0;
    hashNode * hashTable = malloc(sizeof(hashNode)*size);
    /* Fills the contact table with the default info. */
    for (i=0;i<size;i++)
    {
        hashTable[i].numEntry = 0;
        hashTable[i].infoList = createList ();
    }
    return(hashTable);
}

/*
This function destroys the list. It can be used by calling it and giving it a pointer to the list.
*/
void destroyHTable (hashNode * hashTable)
{
    if (hashTable == NULL)
    {
        printf("Error. NULL hashTable. Returning.\n");
        return;
    }
    free(hashTable);
    return;
}

/*
This function is used to add to the front of the list. The user gives it the list and the number they would like to put in the front.
*/
hashNode * insert (hashNode * hashTable,contactInfo * entry,int keyValue)
{
    contactInfo * tailNode;
    contactInfo * newNode;
    if (hashTable == NULL)
    {
        printf("Error. NULL Hash Table. Returning Null.\n");
        return(NULL);
    }
    /* Makes tail node equal to the list at this key value. */
    tailNode = hashTable[keyValue].infoList;
    newNode = initNode(entry->phoneNum,entry->firstName,entry->lastName);
    
    /* Finds end of list and puts new node there. */
    while (tailNode->next != NULL)
    {
        tailNode = tailNode->next;
    }
    
    tailNode->next = newNode;
    hashTable[keyValue].numEntry ++;
    return(hashTable);
}

/*
This function is used to look for the contact info of the given phone number. 
*/
contactInfo * lookUp (hashNode * hashTable, int keyValue, char * phoneNumber)
{
    int listLen = 0;
    int i=0;
    contactInfo * currListPos = malloc(sizeof(contactInfo)*1);

    if (hashTable == NULL)
    {
        printf("Error. The hashTable is NULL.\n");
        return(NULL);
    }

    /* Looks for the phone number in the keyValue's list. */
    currListPos = hashTable[keyValue].infoList;
    /*printf("**List Inside Node # %d**\n",keyValue);*/
    /*printList(currListPos);*/
    listLen = hashTable[keyValue].numEntry;
    /*printf("ListLen: %d\n",listLen);*/
    currListPos = currListPos->next;
    /*printf("Before Loop\n");*/
    for (i = 0; i < listLen; i++)
    {
        /*printf("%s %s (%s)\n",(currListPos->firstName),(currListPos->lastName),(currListPos->phoneNum));*/
        if (strcmp(currListPos->phoneNum,phoneNumber) == 0)
        {
            return(currListPos);
        }
        /*printf("Next Node\n");*/
        if (i + 1 != listLen)
        currListPos = currListPos->next;
    }
    /*printf("After Loop\n");*/
    currListPos->phoneNum = NULL;
    return(currListPos);
}

/*
This function is used to remove the information from a given key value. 
*/
hashNode * removeInfo (hashNode * hashTable, int keyValue)
{
    if (hashTable == NULL)
    {
        printf("Error. The hashTable is NULL.\n");
        return(NULL);
    }
    else if (hashTable[keyValue].infoList == NULL) /* Makes sure the node is not already empty. */
    {
        printf("Error. Retuning hashTable. No Information to remove.\n");
        return(hashTable);
    }
    else /* Removes the information. */
    {
        hashTable[keyValue].numEntry = 0;
        hashTable[keyValue].infoList = NULL;
    } 
    return(hashTable);
}

/*
This function is used to print the hash table. 
*/
void printHTable (hashNode * hashTable,int size)
{
    int i;
    if (hashTable == NULL)
    {
        printf("Empty Hash Table. Returning.\n");
    }
    for (i = 0; i < size-1; i++) /* Loops through hash table printing the list in every spot. */
    {
        /*printf("Hash Table @ %d\n",i);*/
        if (hashTable[i].numEntry > 0)
        {
            printList (hashTable[i].infoList);
        }
    }
    return;

}

/*
This function is used to create the key based off of the phone number. 
*/
int createKey (char * phoneNumber,int tableSize)
{
    int i = 0;
    int sum = 0;
    int modSum = 0;
    int numArray[10];
    sum = 0;
    modSum = 0;

    if (phoneNumber == NULL)
    {
        printf("Unable to create key. NULL number. Returning.\n");
        return(0);
    }

    for (i = 0; i < 10; i++) /* Loops through the phone number string and converts char 1 to string 1. */
    { 
        switch ((phoneNumber[i]))
        {
        case '1':
            numArray[i] = 1;
            break;

        case '2':
            numArray[i] = 2;
            break;

        case '3':
            numArray[i] = 3;
            break;

        case '4':
            numArray[i] = 4;
            break;

        case '5':
            numArray[i] = 5;
            break;

        case '6':
            numArray[i] = 6;
            break;

        case '7':
            numArray[i] = 7;
            break;

        case '8':
            numArray[i] = 8;
            break;

        case '9':
            numArray[i] = 9;
            break;

        default:
            numArray[i] = 0;

        }
       sum = numArray[i] + sum;
    }
    sum = sum * numArray[4]; /* Multiplies by the fourth key num to spice things up. */
    /*printf("Sum: %d\n",sum);*/
    modSum = sum % tableSize; /* Modulates the sum by the table size to form the key. */
    /*printf("ModSum: %d\n",modSum);*/
    return(modSum);
}
