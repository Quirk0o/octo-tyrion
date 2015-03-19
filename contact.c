//
// Created by beatka on 13.03.15.
//

#include <stdlib.h>
#include <stdio.h>
#include "src/contact.h"

Contact* newContact(char* firstName, char* lastName) {
    Contact* c = (Contact*) malloc(sizeof(Contact));
    c->firstName = firstName;
    c->lastName = lastName;

    return c;
}

Contact* newFullContact(
    char *firstName,
    char *lastName,
    char *dateOfBirth,
    char *email,
    char *phone,
    char *address) {

    Contact* c = newContact(firstName, lastName);
    c->DOF = dateOfBirth;
    c->email = email;
    c->phone = phone;
    c->address = address;

    return c;
}

void addDOF(Contact* c, char* dateOfBirth) {
    c->DOF = dateOfBirth;
}

void addEmail(Contact* c, char* email) {
    c->email = email;
}

void addPhone(Contact* c, char* phone) {
    c->phone = phone;
}

void addAddress(Contact* c, char* address) {
    c->address = address;
}


void printContact(Contact* c) {
    printf("Name: %s\nAddress: %s\n", c->firstName, c->address);
}

void deleteContact(Contact* c) {
    free(c);
}