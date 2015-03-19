//
// Created by beatka on 13.03.15.
//

#ifndef _CONTACTLIST_CONTACT_H_
#define _CONTACTLIST_CONTACT_H_

typedef struct Contact {
    char* firstName;
    char* lastName;
    char* birthDate;
    char* email;
    char* phone;
    char* address;
} Contact;

Contact* newContact(char* firstName, char* lastName);
Contact* newFullContact(char* firstName, char* lastName, char* birthDate, char* email, char* phone, char* address);
void addBirthDate(Contact*, char*);
void addEmail(Contact*, char*);
void addPhone(Contact*, char*);
void addAddress(Contact*, char*);

void printContact(Contact*);
void deleteContact(Contact*);

#endif //_CONTACTLIST_CONTACT_H_
