CC=gcc
CFLAGS=-c -Wall -fPIC
SOURCES=test/default_test.c

LIBDIR=lib

SRCDIR=src
_DEPS=linked_list.h contact.h
DEPS=$(patsubst %,$(SRCDIR)/%,$(_DEPS))

OBJDIR=build
_OBJECTS=$(_DEPS:.h=.o)
OBJECTS=$(patsubst %,$(OBJDIR)/%,$(_OBJECTS))

EXECUTABLE=contact_list

test: static shared dynamic

static: $(DEPS) $(SOURCES) $(LIBDIR)/$(EXECUTABLE).a
	$(CC) $(SOURCES) $(LIBDIR)/$(EXECUTABLE).a -o $(EXECUTABLE)_$@
	./$(EXECUTABLE)_$@

shared: $(DEPS) $(SOURCES) $(LIBDIR)/lib$(EXECUTABLE).so
	$(CC) $(SOURCES) -L./$(LIBDIR) -l$(EXECUTABLE) -o $(EXECUTABLE)_$@ -Wl,-rpath=./$(LIBDIR)
	./$(EXECUTABLE)_$@

dynamic: ./test/dl_test.c $(DEPS) $(SOURCES) $(LIBDIR)/lib$(EXECUTABLE).so
	$(CC) ./test/dl_test.c -ldl -o $(EXECUTABLE)_dynamic -Wl,-rpath=./$(LIBDIR)
	./$(EXECUTABLE)_$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

$(LIBDIR)/%.a: $(OBJECTS)
	ar crs $(LIBDIR)/$(EXECUTABLE).a $(OBJECTS)

$(LIBDIR)/%.so: $(OBJECTS)
	$(CC) -shared -fPIC $(OBJECTS) -o $(LIBDIR)/lib$(EXECUTABLE).so

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o