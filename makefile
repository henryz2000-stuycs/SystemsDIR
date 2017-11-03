all: work09.c
	gcc -o work09 work09.c

clean:
	rm *~

run: all
	./work09
