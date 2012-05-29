$(shell mkdir -p obj/test)
export MAKEROOT := $(shell pwd)
OBJ_DIR := $(MAKEROOT)/obj

CFLAGS := -I $(MAKEROOT)/include -std=gnu99

CPP := gcc
CC := gcc

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(MAKEROOT)/obj/$@

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $< -o $(MAKEROOT)/obj/$@

.PHONY : all

all : ierror_test

ierror_test : test/ierror_test.o
	$(CC) -o $(MAKEROOT)/obj/$@ $(MAKEROOT)/obj/$<

