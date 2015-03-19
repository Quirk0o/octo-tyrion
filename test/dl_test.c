#include <stdio.h>
#include "../src/linked_list.h"
#include <dlfcn.h>
#include <time.h>
#include <sys/times.h>
#include <stdlib.h>

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
  printf("From previous checkpoint:\n");
  printf("real: %.8f\nuser: %.8f\nsys: %.8f\n\n",
      (double)(currReal - prevReal)/CLOCKS_PER_SEC,
      (double)(currTimes.tms_utime - prevTimes.tms_utime)/CLOCKS_PER_SEC,
      (double)(currTimes.tms_stime - prevTimes.tms_stime)/CLOCKS_PER_SEC);
  printf("From start:\n");
  printf("real: %.8f\nuser: %.8f\nsys: %.8f\n\n",
      (double)(currReal - startReal)/CLOCKS_PER_SEC,
      (double)(currTimes.tms_utime - startTimes.tms_utime)/CLOCKS_PER_SEC,
      (double)(currTimes.tms_stime - startTimes.tms_stime)/CLOCKS_PER_SEC);
  checkpoint++;
}

void checkDL() {
  char* error;
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
}

void* load(void* handle, char* f) {
  void* func = dlsym(handle, f);
  checkDL();
  return func;
}

int main() {
  startReal = clock();
  times(&startTimes);

  printTimes();

  void *handle = dlopen("./lib/libcontact_list.so", RTLD_LAZY);
  if (!handle) {
    fputs(dlerror(), stderr);
    exit(1);
  }

  List* (*newList)();
  newList = load(handle, "newList");
  List* l = (*newList)();

  void (*addContact)(List*, char*, char*);
  addContact = load(handle, "addContact");
  void (*addFullContact)(List*, char*, char*, char*, char*, char*, char*);
  addFullContact = load(handle, "addFullContact");

  (*addFullContact)(l, "Beatka", "Obrok", "29/06/1993", "beata@obrok.eu", "555 555 555", "ul. Uliczna 2");
  (*addFullContact)(l, "Dawid", "Romanowski", "13/05/1993", "dawid.romanowski@gmail.com", "555 555 555", "ul. Uliczna 2");
  (*addContact)(l, "Barbara", "Obrok");
  (*addContact)(l, "Aleksander", "Gul");
  (*addContact)(l, "Dawid", "Krzyszycha");

  void (*printList)(List*);
  printList = load(handle, "printList");
  (*printList)(l);
  printf("\n");

  printTimes();

  void (*sort)(List*);
  sort = load(handle, "sort");
  int i;
  for (i = 0; i < 1000000; i++) {
    (*sort)(l);
  }
  (*printList)(l);
  printf("\n");

  printTimes();

  Contact* (*search)(List*, char*, char*);
  search = load(handle, "search");
  (*search)(l, "Beatka", "Obrok");

  void (*deleteList)(List*);
  deleteList = load(handle, "deleteList");
  (*deleteList)(l);

  dlclose(handle);

  printTimes();
}