CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o

I = -I include  # places which should be included into search path for #include
                #    preprocessor macro during compilation
COMPILE = $(CC) $(FLAGS) $(I) -c

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib

library : $(BUILD)/vector.o $(BUILD)/point.o $(BUILD)/util.o

test : test_vector test_point
	@./bin/test_vector && ./bin/test_point

test_point : $(BUILD)/test_point.o $(BUILD)/point.o \
             $(BUILD)/vector.o $(BUILD)/util.o
	$(LINK) $(BINARY)/$@ $^

test_vector: $(BUILD)/test_vector.o $(BUILD)/vector.o $(BUILD)/util.o
	$(LINK) $(BINARY)/$@ $^

$(BUILD)/test_point.o : $(TEST)/test_point.cc $(BUILD)/point.o 
	$(COMPILE) $< -o $@

$(BUILD)/test_vector.o : $(TEST)/test_vector.cc $(BUILD)/vector.o \
                         $(BUILD)/util.o
	$(COMPILE) $< -o $@

$(BUILD)/point.o : $(SOURCE)/point.cc $(INCLUDE)/point.h \
                   $(INCLUDE)/vector.h $(INCLUDE)/util.h
	$(COMPILE) $< -o $@

$(BUILD)/vector.o : $(SOURCE)/vector.cc $(INCLUDE)/vector.h $(BUILD)/util.o
	$(COMPILE) $< -o $@

$(BUILD)/util.o : $(SOURCE)/util.cc $(INCLUDE)/util.h
	$(COMPILE) $< -o $@

clean:
	@rm bin/* build/*
