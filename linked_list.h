//
// Created by beatka on 13.03.15.
//

#ifndef _CONTACTLIST_LINKED_LIST_H_
#define _CONTACTLIST_LINKED_LIST_H_

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



#endif //_CONTACTLIST_LINKED_LIST_H_
