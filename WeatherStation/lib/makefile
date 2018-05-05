CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

I = -I $(INCLUDE)  #  Paths which should be included into search path for
                   #  #include preprocessor macro
COMPILE = $(CC) $(FLAGS) $(I) -c  # compilation to intermediary .o files

test_sensor_net : $(BUILD)/test_sensor_net.o $(BUILD)/sensor_net.o
	$(LINK) $(BINARY)/$@  $^

library : $(BUILD)/sensor_net.o

$(BUILD)/test_sensor_net.o : $(TEST)/test_sensor_net.cc $(BUILD)/sensor_net.o
	$(COMPILE) $< -o $@

$(BUILD)/sensor_net.o : $(SOURCE)/sensor_net.cc $(INCLUDE)/sensor_net.h
	$(COMPILE) $< -o $@

clean:
	@rm $(BINARY)/* $(BUILD)/*
