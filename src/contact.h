//
// Created by beatka on 13.03.15.
//

#ifndef _CONTACTLIST_CONTACT_H_
#define _CONTACTLIST_CONTACT_H_

typedef struct Contact {
    char* firstName;
    char* lastName;
    char* DOF;
    char* email;
    char* phone;
    char* address;
} Contact;

Contact* newContact(char*, char*);
Contact* newFullContact(char *, char *, char *, char *, char *, char *);
void addDOF(Contact*, char*);
void addEmail(Contact*, char*);
void addPhone(Contact*, char*);
void addAddress(Contact*, char*);

void printContact(Contact*);
void deleteContact(Contact*);

#endif //_CONTACTLIST_CONTACT_H_
