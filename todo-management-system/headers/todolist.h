// define todolist.h if not defined already
#ifndef _TODOLIST_H
#define _TODOLIST_H


// This file implements a linked list of todo type!
// for memory allocation
#include <stdlib.h>
// for boolean type
#include <stdbool.h>
// for assertion
#include <assert.h>
// import the todo type
#include "todo.h"


// declaration of linked-list node
typedef struct TodoListNode{
    // each linked list has a todo type object
    Todo todo;
    // each linked list has a pointer to next node
    struct TodoListNode* next;
    // each linked list has a pointer to previous node
    struct TodoListNode* prev;
}TodoListNode;
// declaration of type todo list
typedef struct TodoList{
    // each linked-list has a head pointer
    TodoListNode* head;
    // each linked-list has a tail pointer
    TodoListNode* tail;
    // each linked-list has size
    size_t size;
}TodoList;

// creates a new linked list node
// returns node if suceeds, NULL otherwise
TodoListNode* new_todo_list_node(Todo todo) {
    // allocate memory for new node
    TodoListNode* node = (TodoListNode*)malloc(sizeof(TodoListNode));
    // validate memory allocation
    if (node == NULL)   return NULL;
    // update the content of the node
    node->todo = todo; node->next = node->prev = NULL;
    // return the newly created list node
    return node;
}

// creates a new empty linked list 
// and returns a pointer to it if succeeds
// otherwise returns a NULL pointer
TodoList* new_todo_list() {
    // allocate memory for new linked list
    TodoList* list = (TodoList*)malloc(sizeof(TodoList));
    // validate memory allocation
    if (list == NULL)   return NULL;
    // update the fields of the list
    list->head = list->tail = NULL; list->size = 0;
    // return the newly created list
    return list;
}



// adds a new node to the end of list
bool add_to_list(TodoList* list, Todo todo) {
    // assert that list is not null
    assert (list != NULL);
    // allocate memory for new node
    TodoListNode* node = new_todo_list_node(todo);
    // validate memory allocation
    if (node == NULL)   return false;
    // add the node to list appropriately
    if (list->head == NULL) {
        // update both the head and the tail pointer
        list->head = list->tail = node;
    } else {
        // update the pointers
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    // update the size of the list
    list->size++;
}





// frees the memory allocated to list
void free_todo_list(TodoList* list) {
    // assert that list is not null
    assert (list != NULL);
    // iterate through list and free nodes
    TodoListNode* temp = list->head;
    while (temp != NULL) {
        // fetch the next node
        TodoListNode* next = temp->next;
        // free memory allocated to current node
        free (temp);
        // jump to next node
        temp = next;
    }
    // free memory allocated to list
    free (list);
}

#endif