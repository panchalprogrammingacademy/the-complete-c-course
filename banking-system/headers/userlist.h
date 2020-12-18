// define userlist.h if not defined already
#ifndef _USERLIST_H
#define _USERLIST_H


// This file implements a linked list of user type!
// for memory allocation
#include <stdlib.h>
// for boolean type
#include <stdbool.h>
// for assertion
#include <assert.h>
// import the user type
#include "user.h"


// declaration of linked-list node
typedef struct UserListNode{
    // each linked list has a user type object
    User user;
    // each linked list has a pointer to next node
    struct UserListNode* next;
    // each linked list has a pointer to previous node
    struct UserListNode* prev;
}UserListNode;
// declaration of type user list
typedef struct UserList{
    // each linked-list has a head pointer
    UserListNode* head;
    // each linked-list has a tail pointer
    UserListNode* tail;
    // each linked-list has size
    size_t size;
}UserList;

// creates a new linked list node
// returns node if suceeds, NULL otherwise
UserListNode* new_user_list_node(User user) {
    // allocate memory for new node
    UserListNode* node = (UserListNode*)malloc(sizeof(UserListNode));
    // validate memory allocation
    if (node == NULL)   return NULL;
    // update the content of the node
    node->user = user; node->next = node->prev = NULL;
    // return the newly created list node
    return node;
}

// creates a new empty linked list 
// and returns a pointer to it if succeeds
// otherwise returns a NULL pointer
UserList* new_user_list() {
    // allocate memory for new linked list
    UserList* list = (UserList*)malloc(sizeof(UserList));
    // validate memory allocation
    if (list == NULL)   return NULL;
    // update the fields of the list
    list->head = list->tail = NULL; list->size = 0;
    // return the newly created list
    return list;
}



// adds a new node to the end of list
bool add_to_list(UserList* list, User user) {
    // assert that list is not null
    assert (list != NULL);
    // allocate memory for new node
    UserListNode* node = new_user_list_node(user);
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
void free_user_list(UserList* list) {
    // assert that list is not null
    assert (list != NULL);
    // iterate through list and free nodes
    UserListNode* temp = list->head;
    while (temp != NULL) {
        // fetch the next node
        UserListNode* next = temp->next;
        // free memory allocated to current node
        free (temp);
        // jump to next node
        temp = next;
    }
    // free memory allocated to list
    free (list);
}

#endif