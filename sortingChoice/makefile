sortingChoice: main.o print.o sorting.o
	gcc -o sortingChoice main.o print.o sorting.o
main.o: main.c print.h sorting.h
	gcc -c main.c
print.o: print.c print.h
	gcc -c print.c 
sorting.o: sorting.c sorting.h
	gcc -c sorting.c