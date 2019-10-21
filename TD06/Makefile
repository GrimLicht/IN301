run: main
	./main

debug: main
	valgrind ./main

main: liste.o main.o
	gcc -Wall -o main liste.o main.o

liste.o: liste.c liste.h
	gcc -c -Wall liste.c
	
main.o: main.c liste.h
	gcc -c -Wall main.c

clean:
	rm -f main.o
	rm -f liste.o
	rm -f main
