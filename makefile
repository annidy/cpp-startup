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

all : iheader idebug_test 

iheader : 
	$(CPP) $(CPPFLAGS) -c $(MAKEROOT)/include/iheader.cpp -o $(MAKEROOT)/obj/iheader.o

ierror_test : test/ierror_test.o
	$(CC) -o $(MAKEROOT)/obj/$@ $(MAKEROOT)/obj/$<

idebug_test : test/idebug_test.o
	$(CC) -o  $(MAKEROOT)/obj/$@ $(MAKEROOT)/obj/$< $(MAKEROOT)/obj/iheader.o

clean :
	rm obj/test/*.o
