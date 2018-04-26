CC = gcc  # use g++ compiler

FLAGS = -std=c11  # compile with C++ 11 standard
FLAGS += -Wall
FLAGS += -g -O0		# compile with all warnings

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib

llist : $(BUILD)/llist.o $(BUILD)/main.o
	$(LINK) $(BINARY)/$@ $^


$(BUILD)/llist.o : $(SOURCE)/llist.c $(INCLUDE)/llist.h $(INCLUDE)/bool.h \
                         
	$(COMPILE) $< -o $@

$(BUILD)/main.o : $(SOURCE)/main.c $(BUILD)/llist.o
	$(COMPILE) $< -o $@



clean:
	@rm bin/* build/*
