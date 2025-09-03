CC = g++
CFLAGS = -c
TARGET_FILE = MyStr.exe
TARGET_DIR = ./build/

all: setup

setup: main.o MyStr.o
	$(CC) $(TARGET_DIR)MyStr.o $(TARGET_DIR)main.o -o $(TARGET_FILE)
	mv $(TARGET_FILE) $(TARGET_DIR)

main.o: main.cpp MyStr.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) main.cpp
	mv main.o $(TARGET_DIR)

MyStr.o: MyStr.cpp MyStr.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) MyStr.cpp
	mv MyStr.o $(TARGET_DIR)

run:
	$(TARGET_DIR)$(TARGET_FILE)

clean:
	rm -f $(TARGET_DIR)*.o $(TARGET_DIR)$(TARGET_FILE)

.PHONY: clean all setup