CC = g++
CFLAGS = -c -Wall
LIBS = -lboost_program_options

all: program

program: main.o
	$(CC) main.o $(LIBS) -o program

main.o: main.cc
	$(CC) $(CFLAGS) main.cc

clean:
	rm -f *.o program