compiler: cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c
	@cc -o $@ -g $^

compile: compiler
	@./compiler input01

inspect: out.s
	@cc -c -o out.o out.s
	@objdump -d out.o
	@objdump -s out.o

run: out.s
	@cc -o out out.s
	@./out

debug: out.s
	@cc -ggdb out.s -o out
	@gdb out

clean:
	@rm -f compiler out *.o *.s *.out
