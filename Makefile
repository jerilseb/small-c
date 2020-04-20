scanner: main.c scan.c
	cc -o scanner -g main.c scan.c

build:
	cc -c main.c scan.c

clean:
	rm -f scanner *.o
