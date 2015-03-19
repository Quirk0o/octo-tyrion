//
// Created by beatka on 13.03.15.
//

#include <stdlib.h>
#include <string.h>
#include "src/linked_list.h"

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

void addContact(List* l, char* firstName, char* lastName) {
    Contact* c = newContact(firstName, lastName);
    addNode(l, newNode(c));
}

void addFullContact(List* l,
    char *firstName,
    char *lastName,
    char *dateOfBirth,
    char *email,
    char *phone,
    char *address) {

    Contact* c = newFullContact(firstName, lastName, dateOfBirth, email, phone, address);
    addNode(l, newNode(c));
}

void updateContact(List* l, Contact* c) {
    Contact* old = search(l, c->firstName, c->lastName);
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

void quicksort(List* l) {
    if (l->head == l->tail)
        return;

    Node* pivot = l->head;
    l->head = pivot->next;
    pivot->next = NULL;

    List left;
    left.tail = NULL;
    left.head = NULL;
    List right;
    right.tail = NULL;
    right.head = NULL;

    Node* it = l->head;
    Node* tmp;
    while (it != NULL) {
        tmp = it;
        it = it->next;
        if (strcmp(tmp->value->firstName, pivot->value->firstName) >= 0) {
            addNode(&right, tmp);
        }
        else {
            addNode(&left, tmp);
        }
    }

    quicksort(&left);
    quicksort(&right);
    List* result = concat(&left, pivot, &right);
    l->head = result->head;
    l->tail = result->tail;
}

void sort(List* l) {
    quicksort(l);
}

Contact* search(List* l, char* firstName, char* lastName) {
    Node* tmp = l->head;
    while (tmp != NULL) {
        if (strcmp(tmp->value->lastName, lastName) == 0) {
            return tmp->value;
        }
        tmp = tmp->next;
    }
}