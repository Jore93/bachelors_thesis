CC = gcc
CP = cp
ECHO = echo 
MKDIR = mkdir
MAKE = make
MV = mv
RM = rm -r
RMRF = rm -rf
OPTIONS = -Wall -g -std=gnu99
FLAGS = -lrt
OPTIMISE = -O3
LIBS = -lm -lpthread -lrt -lcrypt
EXEC = main

INCLUDE_DIRS = ./inc
SRC_DIR = ./src
C_SRCS = $(wildcard $(SRC_DIR)/*.c)
C_OBJS = ${C_SRCS:.c=.o}
OBJS = $(C_SRCS)
WPI = wiringPi/wiringPi/

BUILD = build
.PHONY: all clean

all:
	$(ECHO) [Compiling program]
	$(CC) $(OPTIONS) $(OPTIMISE) -I$(INCLUDE_DIRS) $(C_SRCS) -o $(EXEC)

clean:
	$(ECHO) [Removing executable]
	$(RMRF) $(EXEC)
