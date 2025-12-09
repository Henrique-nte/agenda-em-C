CC = gcc
CFLAGS = -I include
SRC = src/*.c
OUT = build/agenda

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

