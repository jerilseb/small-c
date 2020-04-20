parser: expr.c interp.c main.c scan.c tree.c
	@cc -o $@ -g $^

run: parser
	@./parser input01

clean:
	@rm -f parser *.o
