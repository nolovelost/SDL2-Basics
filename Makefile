# Files to compile as part of the project
OBJS = src/texture.h src/texture.cpp src/mandala.h src/mandala.cpp src/main.cpp 

# Compiler used
CC = g++

# Compiler flags
# -w suppresses all Warnings
COMPILER_FLAGS = -w

# Liker Flags
LINKER_FLAGS = -lSDL2 -lSDL2_image

# Name of output file
OUT_NAME = game

# Default target
all: $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUT_NAME)
