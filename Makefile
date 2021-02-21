compiler: cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c
	@cc -o $@ -g $^

compile: compiler
	@./compiler input01

run:
	@cc -o out out.s
	@./out

clean:
	@rm -f compiler out *.o *.s
