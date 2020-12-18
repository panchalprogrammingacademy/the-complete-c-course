# TODO MANAGEMENT SYSTEM  
This is a simple application written using C programming language for todo management system.  
The following operations are supported with the application  

0. Add Todo  
1. Show Todo  
2. All Todos  
3. Today's Todos  
4. Upcoming Todos  
5. Past Todos  
6. Done Todos  
7. Note done Todos  
8. Mark as done  
9. Mark as not done  
10. Edit Todo  
11. Delete Todo  
12. Exit  

In short the application demonstrats `CRUD (Create, Read, Update and Delete)` operations using file processing in C programming language.  

# Project structure  
`main.c` is the driver file which accepts the user's response and invoke appropriate functions with respect to user's choice and repeats this procedure till user opt for an exit operation.  
The project is fully modular and is divided into multiple files. The source code are written under `headers/` which are accessible to other files.  
`headers/menu.h` displays the menu to the user.  
`headers/clearscreen.h` defines a function to clear the console. You may wish to update this file depending on your OS (Operating system).  
`headers/delay.h` defines a busy-wait function so that we can wait for sometime before reprinting the menu - this is done for user-friendly environment.  
`headers/strutil.h` defines the utility-function for working with strings.  
`headers/todo.h` defines the type of todo.  
`headers/todoio.h` define functions which interact with user via console for IO.  
`headers/filehandling.h` performs all the file-related operations.  
`headers/menuhandler.h` acts as an intermediary between the `todoio.h` and `filehandling.h`. It defines all the procedures that handles the user's choice and then invoke functions from `todoio.h` for user IO and `filehandling.h` for reading/writing to file.
`data/todo_details.dat` contains the binary file which stores the details about  the users.  
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




