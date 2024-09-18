# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -I./include -Wall -Wextra -O2

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = expert_system

# Create obj directory if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
