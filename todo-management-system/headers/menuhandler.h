// define menuhandler.h if not defined already
#ifndef _MENUHANDLER_H
#define _MENUHANDLER_H

// include todo.h
#include "todo.h"
// include todoio.h
#include "todoio.h"
// for clearscreen
#include "clearscreen.h"
// for file processing
#include "filehandling.h"
// for list of todos
#include "todolist.h"

// adds a new todo
void add_todo() {
    // create a new todo
    Todo todo;
    // clear the console
    clear_screen();
    // header
    print_header(50, '=', "ADD TODO");
    // query the todo
    if (!query_todo(&todo)) return;

    // update the todo-Id
    for(size_t i = 0; i < ID_SIZE; ++i) todo.todoId[i] = rand() % 10 + '0';
    // append a null character at the end
    todo.todoId[ID_SIZE] = '\0'; 

    // update the status
    todo.finished = false;

    // print the generated todo
    printf ("\n\nCreated the following todo: \n");
    uncolored_todo(&todo);
    // write the todo to file
    if (!write_todo_to_file(&todo)) {
        // failed to save todo
        printf ("\033[31;1mFailed to save your todo.\nOperation failed!\nYou will now be redirected to main menu!\n\033[0m");
    } else {
        // operation succeeded
        printf ("\033[32;1mYour todo was successfully saved.\nOperation succeeded!\nYou will now be redirected to main menu!\n\033[0m");
    }
}


// enquiry about todo
void show_todo() {
    // create a new todo
    Todo todo;
    // clear the console
    clear_screen();
    // header
    print_header(50, '=', "TODO DETAILS");
    // read todoId
    if(!read_todoId(todo.todoId))   return;
    // search for todo in file
    int location = read_todo_from_file(&todo);
    // validate location
    if (location == -1) {
        // failed to find a matching record
        printf ("\033[31;1mFailed to find a matching record.\nOperation failed!\nYou will now be redirected to main menu!\n\033[0m");
    } else {
        // print the details of the todo
        uncolored_todo(&todo);
        printf ("\033[32;1mOperation succeeded!\nYou will now be redirected to main menu!\n\033[0m");
    }
}

// list the todos based on types
void list_todos(FILTER_TYPE type) {
    // fetch the list of todos
    TodoList* list = read_all_from_file();
    // validate list
    if (list == NULL) {
        // failed to fetch list
        printf ("\033[31;1mFailed to fetch list of todos.\nOperation failed!\nYou will now be redirected to main menu!\n\033[0m");
    } else {
        // print the all filtered todos
        list_filter_todos(list, type);
    }
}

// print all todos
void all_todos() {
    // list all todos
    list_todos(ALL);
}
// print today's todos
void today_todos() {
    // list all today's todos
    list_todos(TODAY);
}
// print upcoming todos
void upcoming_todos() {
    // list all upcoming todos
    list_todos(AFTER);
}
// print past todos
void past_todos() {
    // list all past todos
    list_todos(BEFORE);
}
// print done todos
void done_todos() {
    // list all done todos
    list_todos(DONE);
}
// print not done todos
void not_done_todos() {
    // list all not-done todos
    list_todos(NOT_DONE);
}



// update the finished status 
void toggle_todo(char* title, bool finished) {
    // create a new todo
    Todo todo;
    // clear the console
    clear_screen();
    // header
    print_header(50, '=', title);
    // read todoId
    if(!read_todoId(todo.todoId))   return;
    // search for todo in file
    int location = read_todo_from_file(&todo);
    // validate location
    if (location == -1) {
        // failed to find a matching record
        printf ("\033[31;1mFailed to find a matching record.\nOperation failed!\nYou will now be redirected to main menu!\n\033[0m");
    } else {
        // update the todo-status
        todo.finished = finished;
        // save this todo to file
        if (!update_todo_in_file(&todo)) {
            // operation failed
            printf ("\033[31;1mFailed to update details.\nOperation failed!\nYou will now be redirected to main menu!\n");
        } else {
            // operation suceeded
            printf ("\033[32;1mYour todo was successfully marked as %s\nOperation succeeded!\nYou will now be redirected to main menu!\n\033[0m", 
                            (finished ? "DONE" : "NOT DONE"));
        }
    }
}

// mark as done
void mark_done() {
    // mark this as finished
    toggle_todo("MARK AS DONE", true);
}

// mark as todo
void mark_todo() {
    // mark this as finished
    toggle_todo("MARK AS NOT DONE", false);
}


// edit the todo
void edit_todo() {
    // create a new todo
    Todo todo;
    // clear the console
    clear_screen();
    // header
    print_header(50, '=', "EDIT TODO");
    // read todoId
    if(!read_todoId(todo.todoId))   return;
    // search for todo in file
    int location = read_todo_from_file(&todo);
    // validate location
    if (location == -1) {
        // failed to find a matching record
        printf ("\033[31;1mFailed to find a matching record.\nOperation failed!\nYou will now be redirected to main menu!\n\033[0m");
    } else {
        // query the details of the todo
        if(!query_todo(&todo))  return;
        // save this todo to file
        if (!update_todo_in_file(&todo)) {
            // operation failed
            printf ("\033[31;1mFailed to update details.\nOperation failed!\nYou will now be redirected to main menu!\n");
        } else {
            // operation suceeded
            printf ("\033[32;1mYour todo was successfully updated.\nOperation succeeded!\nYou will now be redirected to main menu!\n\033[0m");
        }
    }

}

// delete the todo
void delete_todo() {
    // clear the screen
    clear_screen();
    // header
    print_header(50, '=', "DELETE TODO");
    // stores the Todo
    Todo todo;
    // prompt for todoId
    if(!read_todoId(todo.todoId))   return;
    // search for the given todo
    int location = read_todo_from_file(&todo);
    // validate the location
    if (location == -1) {
        // failed to find a matching todo
        printf ("\033[31;1mFailed to find a matching todo.\nOperation failed!\nYou will now be redirected to main menu!\n\033[0m");
    } else if (!delete_todo_from_file(&todo)) {
        // failed to delete todo
        printf ("\033[31;1mFailed to delete your todo.\nOperation failed!\nYou will now be redirected to main menu!\n\033[0m");
    } else {
        // todo deleted
        printf ("\033[32;1mYou todo was successfuly deleted.\nOperation succeeded!\nYou will now be redirected to main menu!\n\033[0m");
    }
}


#endif