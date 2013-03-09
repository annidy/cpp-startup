$(shell mkdir -p obj/test)
export MAKEROOT := $(shell pwd)
OBJ_DIR := $(MAKEROOT)/obj

CFLAGS := -I $(MAKEROOT)/include -std=gnu99
CPPFLAGS := -I $(MAKEROOT)/include

CPP := g++
CC := gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(MAKEROOT)/obj/$@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $(MAKEROOT)/obj/$@

.PHONY : all

all : idebug_test ierror_test iutil_test idebug_test_cpp

iheader : include/iheader.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $(MAKEROOT)/obj/test/iheader.o 

ierror_test : test/ierror_test.o
	$(CC) -o $(MAKEROOT)/obj/$@ $(MAKEROOT)/obj/$<

idebug_test : test/idebug_test.o
	$(CPP) -o $(MAKEROOT)/obj/$@ $(MAKEROOT)/obj/$< $(MAKEROOT)/obj/test/iheader.o

idebug_test_cpp : test/idebug_test_cpp.o iheader
	$(CPP) -o $(MAKEROOT)/obj/$@ $(MAKEROOT)/obj/$< $(MAKEROOT)/obj/test/iheader.o

iutil_test : test/iutil_test.o
	$(CC) -o $(MAKEROOT)/obj/$@ $(MAKEROOT)/obj/$<


clean :
	rm obj/test/*.o
