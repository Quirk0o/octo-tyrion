CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=main.c

LIBDIR=lib
LIBS=

SRCDIR=src
_DEPS=linked_list.h contact.h
DEPS=$(patsubst %,$(SRCDIR)/%,$(_DEPS))

OBJDIR=build
_OBJECTS=$(_DEPS:.h=.o)
OBJECTS=$(patsubst %,$(OBJDIR)/%,$(_OBJECTS))

EXECUTABLE=contactList

$(EXECUTABLE): $(OBJECTS) $(SOURCES)
	$(CC) $(LDFLAGS) $(OBJECTS) $(SOURCES) $(LIBS) -o $(EXECUTABLE)

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o
