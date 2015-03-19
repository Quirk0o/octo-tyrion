cmake_minimum_required(VERSION 3.1)
project(contactList)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES test/default_test.c)
add_executable(contactList ${SOURCE_FILES} src/linked_list.h src/contact.h src/contact.c src/linked_list.c)