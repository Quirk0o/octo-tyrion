#include <stdio.h>
#include "src/linked_list.h"

int main() {

    List* l = newList();

    addContact(l, "Beatka", "Dupa");
    addContact(l, "Beatka2", "Dupa");
    addContact(l, "Beatka3", "Dupa");
    addContact(l, "Beatka4", "Dupa");
    printList(l);
    printf("\n");

    l = sort(l);
    printList(l);
    printf("\n");

    Contact* c = search(l, "Beatka3");
    printContact(c);

    deleteList(l);

    return 0;
}