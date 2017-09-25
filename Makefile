CC = gcc
CP = cp
MKDIR = mkdir
MAKE = make
MV = mv
RM = rm -r
RMRF = rm -rf
OPTIONS = -Wall -g -std=c99
FLAGS = -shared -fPIC
OPTIMISE = -O3
EXEC = main

INCLUDE_DIRS = ./inc
SRC_DIR = ./src
C_SRCS = $(wildcard $(SRC_DIR)/*.c)
C_OBJS = ${C_SRCS:.c=.o}
OBJS = $(C_OBJS)
LIBS = libwiringPi.so.2.44

BUILD = build
.PHONY: all clean

all: $(EXEC)
	echo Compiling program
	$(CC) $(OPTIONS) $(FLAGS) $(OPTIMISE) -I$(INCLUDE_DIRS) -L./ $(C_SRCS) -o $(EXEC) -Wl,$(LIBS)

#	if [ ! -d "$(BUILD)" ]; then
	echo "Creating $(BUILD) directory"
	$(MKDIR) -p $(BUILD)
	echo "Creating $(BUILD)/exe"
	$(MKDIR) -p $(BUILD)/exe
	echo "Creating $(BUILD)/obj"
	$(MKDIR) -p $(BUILD)/obj
#	fi

#	echo Moving program to $(BUILD)/exe
#	$(MV) ./$(EXEC) $(BUILD)/exe
#	echo Moving object files to $(BUILD)/obj
#	$(MV) $(SRC_DIR)/*.o $(BUILD)/obj

clean:
	$(RMRF) $(BUILD)
#	$(RMRF) $(OBJS)