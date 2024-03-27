all:  calc.o logic.o
	gcc calc.o logic.o -o calc
calc.o: calc.c calc.h
	gcc -c calc.c
logic.o: logic.c calc.h
	gcc -c logic.c
clean:
	rm -f *.o calc

