#include "linkedList.h"
#include "phoneBook.h"
#include "hashTableADT.h"

/*
This function is used to open the given file.
*/
FILE * openFile (char * fileName)
{
    FILE* filePointer = fopen (fileName,"r");
    if (filePointer == NULL)
    {
        printf("Cannot open the file. (Include File Location.)\n");
        exit(1);
    }
    return(filePointer);
}

/*
This function is used to remove the new line from the given pointer to the string. 
*/
char * removeNewline (char* fileLine)
{
    int i;
    int fileLineLen;

    fileLineLen = strlen(fileLine);

    for (i = 0; i < fileLineLen; i++)
    {
        if (fileLine[i] == '\n')
        {
            fileLine[i] = '\0';
        }
    }

    return(fileLine);
}

/*
This function is used to sort the list into alphabetical order. 
*/
contactInfo * sortList (contactInfo * contactList)
{
    if (contactList == NULL)
    {
        return(NULL);
    }
    /*Sorts the next node in the list */
    contactList->next = sortList (contactList->next);
    /* Compairs the current first name to the first name in the next node and swaps them if the first string is lower than the second string. */
    if ( contactList->next != NULL && strcmp(contactList->firstName,(contactList->next)->firstName)>0)
    {
        contactList = swapNode (contactList);
    }

    return (contactList);
}

/*
This function is used to swap the given nodes.
*/
contactInfo * swapNode ( contactInfo * ptr1 )
{
    contactInfo * nextNode;
    contactInfo * ptr2;
    contactInfo * returnNode;

    /* Set up the needed pointers to the locations in the list */
    ptr2 = ptr1;
    nextNode = ptr1->next;
    returnNode = nextNode;

    /* loops through and moves the nodes depening on name */
    while ( nextNode != NULL && strcmp(ptr1->firstName,nextNode->firstName)>0) 
    {
        ptr2 = nextNode;
        nextNode =  nextNode->next;
    }

    /* Move the top item to between ptr2 and nextNode */
    ptr2->next = ptr1;
    ptr1->next = nextNode;

    return(returnNode);
}

/*
This function is used to fill the hash table with the contact information.
*/
hashNode * fillContactHTable (hashNode * hashTable,contactInfo * contactList,int tableSize)
{
    contactInfo * currListPos;
    int keyValue=0;
    /*int i=0;*/

    if (hashTable == NULL)
    {
        printf("Error.Returning.\n");
        return(NULL);
    }

    /* Avoiding the dummy head. */
    currListPos = contactList->next;

    /* Loops through the entire contact list and places every contact in its proper spot.*/
    while (currListPos->next != NULL)
    {
        keyValue = createKey (currListPos->phoneNum,tableSize);
        hashTable = insert (hashTable,currListPos,keyValue);
        currListPos = currListPos->next;
        /*i++;*/
    }
    keyValue = createKey (currListPos->phoneNum,tableSize);
    hashTable = insert (hashTable,currListPos,keyValue);
    /*i++;*/
    /*printf("Number of inserts:%d\n",i);*/
    return(hashTable);
}

/*
This function is the menu of the program.  
*/
void programMenu (hashNode * contactHTable,contactInfo * contactList)
{
    char userChoice[1000];
    char * fileLine = malloc(sizeof(char)*150);
    FILE * filePointer;
    char * fileName;
    char * firstName;
    char * lastName;
    char * phoneNum;
    contactInfo * lookedUp;
    int i = 0;
    int keyValue = 0;
    int tableSize = 0;

    if (contactList == NULL || contactHTable == NULL)
    {
        printf("Error. Returning.\n");
        return;
    }
    
    /* Gets user input and determins what action to do using the switch on user input. If input is not 1-5 then runs default case.*/
    /* Loops until user inputs 5 to quit. */
    printf("Please enter the number of the task you would like to complete.\n");
    printf("(1) Load a file into the directory (List and Table).*Ends Program on Failure*\n(2) Add a single entry to the directory (List and Table).\n(3) Print the entire list.\n(4) Look for a person by entering a phone number.\n(5) Exit Program.\n");
    printf("Task Number: ");
    fgets(userChoice,1000,stdin);
    /*printf("userChoice: %c\n",userChoice[0]);*/ 
    while (userChoice[0] != '5')
    {
        switch (userChoice[0])
        {
        case '1': /* Import from file. */
            fileName = malloc(sizeof(char)*500);
            printf("Warning: *Incorrect entry of file name results in program closure.*\n");
            printf("Please enter the name of the file you would like to load from.(Max 500 Characters): ");
            fgets(fileName,500,stdin);
            fileName = removeNewline (fileName);
            filePointer = openFile (fileName);
            while (fgets(fileLine, 150, filePointer) != NULL) /* Add info from file into the contact list. */
            {
                fileLine = removeNewline (fileLine);
                phoneNum = malloc(sizeof(char)*10);
                firstName = malloc(sizeof(char)*51);
                lastName = malloc(sizeof(char)*51);
                sscanf(fileLine,"%[^,],%[^,],%s", firstName, lastName, phoneNum); 
                /*printf("B4: %s %s (%s) \nNext\n", firstName, lastName, phoneNum);*/
                contactList = addToList (contactList,phoneNum,firstName,lastName);
                contactList = sortList (contactList);
                /*printf("AFTR: %s %s (%s) \nNext\n", firstName, lastName, phoneNum);*/
            }
            free(fileName);
            fclose(filePointer);
            tableSize = getTableSize (contactList); /* Add Information from file into hash table. */
            /*printf("Table Size: %d\n",tableSize);*/
            contactHTable = createHTable (tableSize);
            contactHTable = fillContactHTable (contactHTable,contactList,tableSize);
            printf("\n"); 
            break;

        case '2': /* Add single contact into list and hash table. */
            phoneNum = malloc(sizeof(char)*10);
            firstName = malloc(sizeof(char)*51);
            lastName = malloc(sizeof(char)*51);
            printf("Please enter the first name of the contact (Max 50 Characters): ");
            fgets(userChoice,1000,stdin); /* Get & Process inputted first name . */
            for (i = 0; i < 50; i++)
            {
                (firstName[i]) = userChoice[i];
            }
            firstName = removeNewline (firstName);
            printf("First Name Entered: %s\n",firstName);

            printf("Please enter the last name of the contact (Max 50 Characters): ");
            fgets(userChoice,1000,stdin); /* Get & process inputted last name. */
            for (i = 0; i < 50; i++)
            {
                (lastName[i]) = userChoice[i];
            }
            lastName = removeNewline (lastName);
            printf("Last Name Entered: %s\n",lastName);

            printf("Please enter the phone number of the contact like this: (0000000000) *no beackets* (Max 10 Numbers): ");
            fgets(userChoice,1000,stdin); /* Get and process inputted phone number. */
            for (i = 0; i < 10; i++)
            {
                (phoneNum[i]) = userChoice[i];
            }
            phoneNum = removeNewline (phoneNum);
            printf("Phone Number Entered: %s\n\n",phoneNum);
            contactList = addToList (contactList,phoneNum,firstName,lastName); /* Add the information to the list and hash table. */
            contactList = sortList (contactList); /* Sort newly added contact. */
            tableSize = getTableSize (contactList);
            /*printf("Table Size: %d\n",tableSize);*/
            contactHTable = createHTable (tableSize);
            contactHTable = fillContactHTable (contactHTable,contactList,tableSize);
            break;

        case '3': /* Prints the contact list. */
            printf("\t***Contact List***\n");
            printList (contactList); 
            printf("\n");
            break;

        case '4': /* Search for contact name using phone number. */
            phoneNum = malloc(sizeof(char)*10);
            printf("Please enter the phone number of the contact you would like to search like this: (0000000000) *no brackets* (10 Numbers): ");
            fgets(userChoice,1000,stdin); /* Get and process user inputted phone number. */
            for (i = 0; i < 10; i++)
            {
                (phoneNum[i]) = userChoice[i];
            }
            printf("Phone Number Entered: %s\n",(phoneNum));
            /*printf("B4 Table Size\n");*/
            tableSize = getTableSize (contactList); /* Create the key from the phone number and use that to look for the contact in hash table. */
            /*printf("TableSize: %d\n", tableSize);*/
            keyValue = createKey (phoneNum,tableSize);
            /*printf("KeyMade: %d\n", keyValue);*/
            lookedUp = lookUp (contactHTable,keyValue,phoneNum);
             /*printf("Passed Search\n");*/
            if(lookedUp->phoneNum == NULL) /* Process lookUp's return. lookUp returns NULL phoneNumber on failure. */
            {
                printf("The contact with phone number (%s) does not exist.\n\n",phoneNum);
            }
            else
            {
                printf("The name of the contact with phone number (%s): ",phoneNum);
                printf("%s %s\n\n",(lookedUp->firstName),(lookedUp->lastName));
            } 
            break;

        case '5': /* Exit the program. */
            printf("Thank You.\n");
            return;
            break;

        default: /* Input that is not between 1-5. */
            printf("Invalid Input.\n");
        }
        printf("Please enter the number of the task you would like to complete.\n");
        printf("(1) Load a file into the directory.\n(2) Add a single entry to the directry.\n(3) Print the entire directory.\n(4) Look for a person by entering a phone number.\n(5) Exit.\n");
        printf("Task Number: ");
        fgets(userChoice,1000,stdin);
        /*printf("userChoice: %c\n",userChoice[0]);*/ 
    }
    printf("Thank You.\n");
    return;
}

/*
This function is used to get the size of the table.
*/
int getTableSize (contactInfo * contactList)
{
    int tableSize = 0;
    if (contactList == NULL)
    {
        printf("Error. Null List. Returning.\n");
        return(0);
    }
    /*printf("In Table Size\n");*/
    tableSize = ((listLength (contactList))*0.66)-1;
    return(tableSize);
}
