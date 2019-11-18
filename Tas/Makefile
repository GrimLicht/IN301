run: main
	./main

main: main.o tas.o
	gcc -Wall -o main main.o tas.o

main.o: main.c tas.h
	gcc -Wall -c main.c
	
tas.o: tas.c tas.h
	gcc -Wall -c tas.c

clean:
	rm -f main
	rm -f main.o
	rm -f tas.o
