# BANKING MANAGEMENT SYSTEM  
This is a simple application written using C programming language for banking management system.  
The following operations are supported with the application  
1. New user registration  
2. Balance enquiry  
3. Cash withdrawl  
4. Cash deposit  
5. Update account details  
6. Deregister user  
7. List all users  
In short the application demonstrats `CRUD (Create, Read, Update and Delete)` operations using file processing in C programming language.  

# Project structure  
`main.c` is the driver file which accepts the user's response and invoke appropriate functions with respect to user's choice and repeats this procedure till user opt for an exit operation.  
The project is fully modular and is divided into multiple files. The source code are written under `headers/` which are accessible to other files.  
`headers/menu.h` displays the menu to the user.  
`headers/clearscreen.h` defines a function to clear the console. You may wish to update this file depending on your OS (Operating system).  
`headers/delay.h` defines a busy-wait function so that we can wait for sometime before reprinting the menu - this is done for user-friendly environment.  
`headers/strutil.h` defines the utility-function for working with strings.  
`headers/user.h` defines the type of user.  
`headers/userio.h` define functions which interact with user via console for IO.  
`headers/banking.h` performs all the file-related operations.  
`headers/menuhandler.h` acts as an intermediary between the `userio.h` and `banking.h`. It defines all the procedures that handles the user's choice and then invoke functions from `userio.h` for user IO and `banking.h` for reading/writing to file.
`user-data/user_details.dat` contains the binary file which stores the details about  the users.  
`executable/main` is the binary executable file.  


# Execution  
cd into the directory where `main.c` is located and run the following command depending on your compiler:  
`gcc main.c -o ./executable/main`  
`g++ main.c -o ./executable/main`  
`clang main.c -o ./executable/main`  
This will generate `executable/main` which is a binary file.  
Next you execute the binary file as follows:  
`./executable/main`  


# Referenes  
[The Complete C Course](http://udemy.com/the-complete-c-course-ppa/)  
[Panchal Programming Academy](http://panchalprogrammingacademy.herokuapp.com/)  
For any query feel free to write to panchalprogrammingacademy@gmail.com  

