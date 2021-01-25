program: fifth.o subfifth.o
	gcc fifth.o subfifth.o -o program -Wall -std=c99 -pedantic
fifth.o: fifth.c subfifth.h
	gcc fifth.c -c -Wall -std=c99 -pedantic
subfifth.o: subfifth.c subfifth.h
	gcc subfifth.c -c -Wall -std=c99 -pedantic
