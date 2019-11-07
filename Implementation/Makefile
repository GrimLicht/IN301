run: main
	./main
	
main: main.o prio.o
	gcc -Wall -o main main.o prio.o
	
main.o: main.c prio.h
	gcc -Wall -c main.c
	
prio.o: prio.c prio.h
	gcc -Wall -c prio.c
	
clean:
	rm -f main
	rm -f main.o
	rm -f prio.o
