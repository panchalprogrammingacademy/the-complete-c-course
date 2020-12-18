// define filehandling.h if not defined already
#ifndef _FILEHANDLING_H
#define _FILEHANDLING_H

// for file IO
#include <stdio.h>
// for boolean operations
#include <stdbool.h>
// for todo operations
#include "todo.h"
// for string operations
#include "strutil.h"
// for todo list
#include "todolist.h"

// stores the filename
const char* filename = "data/todo_details.dat";
const char* tempfilename = "data/temp_todo_details.dat";

// writes the todo to file
// returns true if operation succeeds
// otherwise returns false
bool write_todo_to_file(Todo* todo) {
    // open the file for append mode
    FILE* fptr = fopen(filename, "ab");
    // validate file pointer
    if (fptr == NULL)   return false;
    // write the object to file
    fwrite(todo, sizeof(struct Todo), 1, fptr);
    // close the file
    fclose(fptr);
    // success
    return true;
}


// reads the todo with given id
// and returns the location where record is found
// if fails to find then returns -1
// also if record is found then 
// updates the passed argument
int read_todo_from_file(Todo* todo) {
    // open file for reading
    FILE* fptr = fopen(filename, "rb");
    // validate file
    if (fptr == NULL)   return false;
    // stores the details of the todo
    Todo tempTodo;
    // iterate through file and read documents
    while (fread(&tempTodo, sizeof(tempTodo), 1, fptr) == 1) {
        // check if user matches
        if (string_equal(tempTodo.todoId, todo->todoId)) {
            // found todo - update details
            *todo = tempTodo;
            // close the file
            fclose(fptr);
            // return the location
            return ftell(fptr) - 1*sizeof(struct Todo);
        }
    }
    // close the file
    fclose(fptr);
    // failed to find user
    return -1;
}


// replaces the todo with given details (if exist)
// for update we over-write; for delete we drop 
bool replace_todo_in_file(Todo* todo, bool dropTodo) {
    // open file for reading
    FILE* fptr = fopen(filename, "rb");
    // validate file
    if (fptr == NULL)   return false;
    // open another file for writing
    FILE* tempPtr = fopen(tempfilename, "wb");
    // validate file
    if (tempPtr == NULL)    return false;
    // stores the details of the todo
    Todo tempTodo;
    // iterate through file and read documents
    while (fread(&tempTodo, sizeof(struct Todo), 1, fptr) == 1) {
        // check if this user matches
        if (string_equal(tempTodo.todoId, todo->todoId)) {
            // check if we need to write another user
            if (!dropTodo)   fwrite(todo, sizeof(struct Todo), 1, tempPtr);
        } else {
            // write object to file
            fwrite(&tempTodo, sizeof(struct Todo), 1, tempPtr);
        }
    }
    // close both the files
    fclose(fptr); fclose(tempPtr);
    // delete the actual file
    if (remove(filename) != 0)  return false;
    // rename and validate
    if (rename(tempfilename, filename) != 0) return false;
    // success 
    return true;
}

// saves the todo with given details
bool update_todo_in_file(Todo* todo) {
    // replace the todo with new details
    return replace_todo_in_file(todo, false);
}

// deletes the todo
bool delete_todo_from_file(Todo* todo) {
    // replace the todo with null
    return replace_todo_in_file(todo, true);
}

// reads and returns the 
// list of todos available
TodoList* read_all_from_file() {
    // create a new empty list
    TodoList* list = new_todo_list();
    // validate list
    if (list == NULL)   return list;
    // open file for reading
    FILE* fptr = fopen(filename, "rb");
    // validate file
    if (fptr == NULL)   return list;
    // stores the details of the todo
    Todo todo;
    // iterate through file and read documents
    while (fread(&todo, sizeof(struct Todo), 1, fptr) == 1) {
        // add the item to list
        add_to_list(list, todo);
    }
    // close the file
    fclose(fptr);
    // return the newly created list
    return list;
}

#endif