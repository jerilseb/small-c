compiler: cg.c expr.c gen.c interp.c main.c scan.c tree.c
	@cc -o $@ -g $^

run: compiler
	@./compiler input01

clean:
	@rm -f compiler out *.o *.s
