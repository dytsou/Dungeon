# Specify the compiler
CC = g++

# Specify compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Specify the source files
SRCS = $(wildcard src/*.cpp)

# Specify the object files directory
OBJ_DIR = obj

# Specify the object files
OBJS = $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Specify the target executable
TARGET = dungeon

# Default target
all: $(TARGET)

# Create the object files directory
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# Compile source files into object files
$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files, the target executable, and the object files directory
clean:
	del /Q $(OBJ_DIR)\*.o
	rmdir $(OBJ_DIR)
