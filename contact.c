//
// Created by beatka on 13.03.15.
//

#include <stdlib.h>
#include <stdio.h>
#include "contact.h"

Contact* newContact(char* name, char* address) {
    Contact* c = (Contact*) malloc(sizeof(Contact));
    c->name = name;
    c->address = address;

    return c;
}

void printContact(Contact* c) {
    printf("Name: %s\nAddress: %s\n", c->name, c->address);
}

void deleteContact(Contact* c) {
    free(c);
}