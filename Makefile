CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

all : testing program


testing :
	gcc $(CFLAGS) src/linkedList.c src/functionTesting.c src/phoneBookFunctions.c src/hashTableADT.c -o bin/runTests -Iinclude


program: 
	gcc $(CFLAGS) src/linkedList.c src/phoneBook.c src/phoneBookFunctions.c src/hashTableADT.c -o bin/phoneBook -Iinclude

clean:
	@ rm *.o



