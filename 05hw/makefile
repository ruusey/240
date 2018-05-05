CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall 
FLAGS += -g      # compile with all warnings

DS = / # directory separator for *nix

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib
LIBBUILD = $(LIBRARY)/$(BUILD)

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

I = -I $(INCLUDE) -I $(LIBRARY)/$(INCLUDE)  #  Paths which should be
                                                #  included into search path for
                                                #  #include preprocessor macro
                                                #  during compilation

test_mobile_robot : $(BUILD)/test_mobile_robot.o \
                    $(BUILD)/quad_rotor_translation.o \
                    $(BUILD)/tracked_translation.o \
                    $(BUILD)/mobile_robot.o
	$(LINK) $(BINARY)/$@ $^ $(LIBRARY)/$(BUILD)/point.o \
      $(LIBRARY)/$(BUILD)/vector.o $(LIBRARY)/$(BUILD)/util.o

library :
	make -C $(LIBRARY) library

COMPILE = $(CC) $(FLAGS) $(I) -c  # compilation to intermediary .o files

$(BUILD)/test_mobile_robot.o : $(TEST)/test_mobile_robot.cc \
                               $(BUILD)/quad_rotor_translation.o \
                               $(BUILD)/tracked_translation.o \
                               $(BUILD)/mobile_robot.o
	$(COMPILE) $< -o $@

$(BUILD)/mobile_robot.o : $(SOURCE)/mobile_robot.cc $(INCLUDE)/mobile_robot.h \
                          $(BUILD)/quad_rotor_translation.o \
                          $(BUILD)/tracked_translation.o
	$(COMPILE) $< -o $@

$(BUILD)/tracked_translation.o : $(SOURCE)/tracked_translation.cc \
                                 $(INCLUDE)/tracked_translation.h
	$(COMPILE) $< -o $@

$(BUILD)/quad_rotor_translation.o : $(SOURCE)/quad_rotor_translation.cc \
                                    $(INCLUDE)/quad_rotor_translation.h
	$(COMPILE) $< -o $@

clean:
	@rm $(BUILD)/* $(LIBRARY)/$(BUILD)/*
