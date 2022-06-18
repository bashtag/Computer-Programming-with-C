all: clear clean compile run

compile: main.c
	@gcc -c main.c
	@gcc main.o -lm -o main.out

run:
	./main.out

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.bin
	
clear:
	@clear