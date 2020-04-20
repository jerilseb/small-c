parser: expr.c interp.c main.c scan.c tree.c
	cc -o $@ -g $^

clean:
	rm -f parser *.o
