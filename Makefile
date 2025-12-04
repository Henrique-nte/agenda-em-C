CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
TARGET = build/programa

all: $(TARGET)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

run:
	$(TARGET)

clean:
	rm -rf build/*.o $(TARGET)
