#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <dlfcn.h>
#include "../src/linked_list.h"

typedef struct tms tms;

clock_t startReal;
tms startTimes;

void printTimes() {

  static int checkpoint = 1;
  static clock_t prevReal;
  static clock_t currReal;
  prevReal = currReal;
  currReal = clock();

  static tms prevTimes;
  static tms currTimes;
  prevTimes = currTimes;
  times(&currTimes);

  printf("Checkpoint %d\n", checkpoint);
  if (checkpoint > 1) {
    printf("From previous checkpoint:\n");
    printf("real: %.8f\nuser: %.8f\nsys: %.8f\n\n",
        (double) (currReal - prevReal) / CLOCKS_PER_SEC,
        (double) (currTimes.tms_utime - prevTimes.tms_utime) / CLOCKS_PER_SEC,
        (double) (currTimes.tms_stime - prevTimes.tms_stime) / CLOCKS_PER_SEC);
  }
  printf("From start:\n");
  printf("real: %.8f\nuser: %.8f\nsys: %.8f\n\n",
      (double) (currReal - startReal) / CLOCKS_PER_SEC,
      (double) (currTimes.tms_utime - startTimes.tms_utime) / CLOCKS_PER_SEC,
      (double) (currTimes.tms_stime - startTimes.tms_stime) / CLOCKS_PER_SEC);
  checkpoint++;
}

int main() {
  startReal = clock();
  times(&startTimes);

  printTimes();

  List* l = newList();

  addContact(l, "Jane", "Doe");
  addContact(l, "Bob", "Doe");
  addContact(l, "Bob", "Bob");
  addFullContact(l, "Beatka", "Obrok", "29/06/1993", "beata@obrok.eu", "555 555 555", "ul. Uliczna 2");
  addFullContact(l, "John", "Doe", "13/05/1993", "jdoe@gmail.com", "555 555 555", "ul. Uliczna 2");

  printList(l);
  printf("\n");

  printTimes();

  int i;
  for (i = 0; i < 1000000; i++)
    sort(l);
  printList(l);
  printf("\n");

  printTimes();

  Contact* c = search(l, "Beatka", "Obrok");
  addAddress(c, "al. Alejowa 5");
  printList(l);

  printTimes();

  deleteList(l);

  printTimes();

  return 0;
}