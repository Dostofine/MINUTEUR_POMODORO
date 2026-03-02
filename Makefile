CC = gcc
CFLAGS = -I include -Wall -Wpedantic -Werror
src = $(wildcard src/*.c)
TARGET = DOSTO_POMODORO
OUTPUT_DIR=build
all:
	$(CC) $(CFLAGS) $(src) -o $(OUTPUT_DIR)/$(TARGET)
clean:
	rm -f $(OUTPUT_DIR)/$(TARGET)

run:
	./$(OUTPUT_DIR)/$(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@