#include <stdio.h>
#include "src/linked_list.h"

int main() {

    List* l = newList();

    addContact(l, "1", "Dupa");
    addContact(l, "2", "Dupa");
    addContact(l, "3", "Dupa");
    addContact(l, "4", "Dupa");
    addContact(l, "1", "Dupa");
    addContact(l, "2", "Dupa");
    addContact(l, "7", "Dupa");
    addContact(l, "2", "Dupa");
    addContact(l, "6", "Dupa");
    addContact(l, "8", "Dupa");
    addContact(l, "3", "Dupa");
    addContact(l, "1", "Dupa");
    printList(l);
    printf("\n");

    sort(l);
    printList(l);
    printf("\n");

    Contact* c = search(l, "3");
    printContact(c);

    deleteList(l);

    return 0;
}