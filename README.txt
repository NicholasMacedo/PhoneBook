****************************************************
Nicholas Macedo - Van Horne    0889469
CIS*2520 (DE)  		          Assignment 2/A2
Friday July 3rd 2015
****************************************************


************
Compilation
************

Both programs are compiled using gcc and the flags -ansi -Wall -pedantic

Phone Book Program:
	The phone book program can be compiled by typing "make program" into the command-line.
	When this is done, it will compile the necessary files producing an executable called "phoneBook".  

Testing Program:
	The testing program can be compiled by typing "make testing" into the command-line.
	When this is done, it will compile the necessary files producing an executable called "runTests". 


***********************
Running the program(s)
***********************

Both program's executable can be found in the bin folder in the main assignment directory.
Phone Book Program:
	The phone book program can be run by typing "./bin/phoneBook <contact file location>" into the command-line.
	In order to run properly, the program must be passed a contact file. When this is done, it will run the program.  
	Each line of the file that is passed in must be formatted like this: firstName,lastName,phoneNumber
	
Testing Program:
	The testing program can be run by typing "./bin/runTests assets/smallTestingList.txt assets/bigTestingList.txt" into the command-line.
	In order to run properly, the program must be passed the smallTastingList.txt and bigTestingList.txt. When this is done, it will run the program.
        For more details of the testing see the testing document in the docs folder.
	The above files are the files I used for testing and are NEEDED to run the test accuretly. Failure to use the files given will result in 
        program failure. (Due to specific situations in the testing code like the lookUp function)


*****************
Known Limitations
*****************

-> Passing No File into the program will cause it to exit w/ a warning.
-> Passing in a file that is not in the given format will cause it to segfault.
-> (NOT PROGRAM RELATED) Style Checker gives errors for header guards.
-> Any spaces in the file will show in the name/location they are. 
-> If the information of a contact is exactly copied it will not check and both will be added.
-> User Input can only take spam up to 1000 characters.
-> Empty lines anywhere but the end of the file result in program failure. (In between lines)
-> Testing program will produce an error if not run with the files told to.
-> Pressing Enter without entering information needed will produce a program error.
-> Entering Special Characters when asked for name produces error in printing.
-> Not entering full number will produce error when searching for contact.
-> Program can handle input spam. Not crazy amounts.
-> Loop of input smap to other side of screen causes problems.


*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.

