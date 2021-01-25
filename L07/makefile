program: program.o IO.o
	gcc program.o IO.o -o program -Wall -std=c99 -pedantic
program.o: program.c IO.h
	gcc program.c -c -Wall -std=c99 -pedantic
IO.o: IO.c IO.h
	gcc IO.c -c -Wall -std=c99 -pedantic
