CC ?= gcc
CP = cp
MKDIR = mkdir
MAKE = make
MV = mv
RM = rm -r
RMRF = rm -rf
OPTIONS = -Wall -g -std=c99
OPTIMISE = -O3
EXEC = main

INCLUDE_DIRS = ./inc
SRC_DIR = ./src
C_SRCS = $(wildcard SRC_DIR/*.c)
OBJS = ${C_SRCS:.c=.o}
BUILD = build

all: 
	$(MKDIR) $(BUILD)
	$(CC) $(OPTIONS) $(OPTIMISE) -I$(INCLUDE_DIRS) $(SRC_DIR) $(EXEC) -o $(C_SRCS) -lwiringPi

clean:
	$(RMRF) $(BUILD)
	$(RMRF) $(OBJS)
