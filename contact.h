//
// Created by beatka on 13.03.15.
//

#ifndef _CONTACTLIST_CONTACT_H_
#define _CONTACTLIST_CONTACT_H_

typedef struct Contact {
    char* name;
    char* address;
} Contact;

Contact* newContact(char*, char*);
void printContact(Contact*);
void deleteContact(Contact*);

#endif //_CONTACTLIST_CONTACT_H_
