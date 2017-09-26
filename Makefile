CC = gcc
CP = cp
MKDIR = mkdir
MAKE = make
MV = mv
RM = rm -r
RMRF = rm -rf
OPTIONS = -Wall -g -std=c99
FLAGS = -pthread
OPTIMISE = -O3
EXEC = main

INCLUDE_DIRS = ./inc
SRC_DIR = ./src
C_SRCS = $(wildcard $(SRC_DIR)/*.c)
C_OBJS = ${C_SRCS:.c=.o}
OBJS = $(C_SRCS)
WPI = wiringPi/wiringPi/
LIBS = -lwiringPi -lm -lcrypt -lrt

BUILD = build
.PHONY: all clean

all:
	echo Compiling program
	$(CC) $(OPTIONS) $(FLAGS) -I$(INCLUDE_DIRS) -L./$(WPI) $(C_SRCS) -o $(EXEC) $(LIBS)

clean:
	$(RMRF) $(EXEC)
