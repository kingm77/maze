CC = g++
CFLAGS = -Wall -g

PathFinding: PathFinding.o Node.o Process.o
	$(CC) $(CFLAGS) -o main PathFinding.o Node.o Process.o


main.o: PathFinding.cpp Node.h Process.h
	$(CC) $(CFLAGS) -c PathFinding.cpp

Node.o: Node.h

Process.o: Process.h Node.h
