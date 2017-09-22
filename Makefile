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
C_SRCS = $(wildcard SRC_DIR/*.c)
C_OBJS = ${C_SRCS:.c=.o}
OBJS = $(C_OBJS)
LIBS = wiringPi

BUILD = build


all: $(OBJS)
#	ifdef($(BUILD))
	$(MKDIR) $(BUILD)
	$(MKDIR) $(BUILD)/exe
	$(MKDIR) $(BUILD)/obj
#	endif
	mv $(SRC_DIR)/$(OBJS) $(BUILD)/obj
	$(CC) $(OPTIONS) $(OPTIMISE) $(FLAGS) -I$(INCLUDE_DIRS) -L./ $(SRC_DIR)/*.c -o $(EXEC) -u$(LIBS)
	$(MV) ./$(EXEC) ./$(BUILD)/exe
clean:
	$(RMRF) $(BUILD)
#	$(RMRF) $(OBJS)