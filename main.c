#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {

    List* l = newList();

    addContact(l, "Beatka", "Dupa");
    addContact(l, "Beatka2", "Dupa");
    addContact(l, "Beatka3", "Dupa");
    addContact(l, "Beatka4", "Dupa");
    printList(l);
    l = sort(l);
    printf("\n");
    printList(l);
    deleteList(l);

    return 0;
}