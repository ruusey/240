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

alist : $(BUILD)/alist.o $(BUILD)/main.o
	$(LINK) $(BINARY)/$@ $^


$(BUILD)/alist.o : $(SOURCE)/alist.c $(INCLUDE)/alist.h $(INCLUDE)/bool.h \
                         
	$(COMPILE) $< -o $@

$(BUILD)/main.o : $(SOURCE)/main.c $(BUILD)/alist.o
	$(COMPILE) $< -o $@



clean:
	@rm bin/* build/*
