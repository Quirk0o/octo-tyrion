//
// Created by beatka on 13.03.15.
//

#ifndef _CONTACTLIST_LINKED_LIST_H_
#define _CONTACTLIST_LINKED_LIST_H_

#include <stdbool.h>
#include "contact.h"

typedef struct Node {
    Contact* value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

Node* newNode(Contact*);
Node* deleteNode(Node*);

List* newList();
void deleteList(List*);
void printList(List*);
void addNode(List*, Node*);
bool isEmpty(List*);
void addContact(List*, char*, char*);
List* sort(List*);
Contact* search(List*, char*);
#endif //_CONTACTLIST_LINKED_LIST_H_
