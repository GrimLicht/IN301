run: tas
	./tas

tas: tas.o tas.h
	gcc -o tas tas.o
	
tas.o: tas.c tas.h
	gcc -c tas.c tas.h

clean:
	rm -f tas
	rm -f tas.o
	rm -f tas.h.gch
