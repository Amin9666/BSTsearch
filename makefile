CC = gcc
CFLAGS = -Wall -g
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
TARGET = dictionary

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/RedBlackTree.c
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/RedBlackTree.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)