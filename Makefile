# _*_ MakeFile_*_

main: main.o insertion.o selection.o mergesort.o heapsort.o quicksort.o bucketsort.o lista.o
	gcc main.o insertion.o selection.o mergesort.o heapsort.o quicksort.o bucketsort.o lista.o -o main

main.o: main.c ordenacao.h
	gcc -g -c main.c

quicksort.o: quicksort.c quicksort.h
	gcc -g -c quicksort.c

heapsort.o: heapsort.c heapsort.h
	gcc -g -c heapsort.c

mergesort.o: mergesort.c mergesort.h
	gcc -g -c mergesort.c

insertion.o: insertion.c insertion.h
	gcc -g -c insertion.c

selection.o: selection.c selection.h
	gcc -g -c selection.c
	
bucketsort.o: lista.o bucketsort.c bucketsort.h
	gcc -g -c bucketsort.c

lista.o: lista.c lista.h
	gcc -g -c lista.c

clean:
	rm -f *.o main