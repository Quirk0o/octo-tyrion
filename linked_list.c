//
// Created by beatka on 13.03.15.
//

#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

Node* newNode(Contact* c) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->value = c;
    n->prev = n->next = NULL;

    return n;
}

Node* deleteNode(Node* n) {
    deleteContact(n->value);
    Node* next = n->next;

    free(n);
    return next;
}

List* newList() {
    List* l = (List*) malloc(sizeof(List));
    l->head = l->tail = NULL;

    return l;
}

void deleteList(List* l) {
    Node* tmp = l->head;
    while (tmp != NULL)
        tmp = deleteNode(tmp);

    free(l);
}

void printList(List* l) {
    Node* tmp = l->head;
    while (tmp != NULL) {
        printContact(tmp->value);
        tmp = tmp->next;
    }
}

void addNode(List* l, Node* n) {
    n->prev = NULL;
    n->next = l->head;
    l->head = n;

    if (l->tail == NULL)
        l->tail = n;
}

void addContact(List* l, char*  name, char* address) {
    Contact* c = newContact(name, address);
    addNode(l, newNode(c));
}

bool isEmpty(List* l) {
    return l->head == NULL;
}

List* concat(List* left, Node* pivot, List* right) {
    List* result = newList();
    addNode(right, pivot);

    if (isEmpty(left)) {
        result->head = right->head;
        result->tail = right->tail;
    }
    else if (isEmpty(right)) {
        result->head = left->head;
        result->tail = right->tail;
    }
    else {
        result->head = left->head;
        left->tail->next = right->head;
        result->tail = right->tail;
    }


    return result;
}

List* quicksort(List* l) {
    if (l->head == l->tail)
        return l;

    Node* pivot = l->head;
    l->head = pivot->next;
    pivot->next = NULL;

    List* left = newList();
    List* right = newList();

    Node* it = l->head;
    Node* tmp;
    while (it != NULL) {
        tmp = it;
        it = it->next;
        if (strcmp(tmp->value->name, pivot->value->name) >= 0) {
            addNode(right, tmp);
        }
        else {
            addNode(left, tmp);
        }
    }

    List* result = concat(quicksort(left), pivot, quicksort(right));
    free(left);
    free(right);
    return result;
}

List* sort(List* l) {
    return quicksort(l);
}