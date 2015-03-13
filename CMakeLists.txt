cmake_minimum_required(VERSION 3.1)
project(contactList)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c)
add_executable(contactList ${SOURCE_FILES} linked_list.h contact.h)