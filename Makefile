SRCS= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c \
	sym.c tree.c types.c

compiler: $(SRCS)
	@cc -o $@ $(SRCS)

out.s: compiler test/input.c
	@./compiler -T test/input.c

debug_build: $(SRCS)
	@cc -ggdb -o compiler $(SRCS)
	# @gdb --args compiler test/input.c

inspect: out.s
	@cc -c -o out.o out.s
	@objdump -d out.o
	@objdump -s out.o

run: out.s
	@cc -o out out.s lib/printint.c
	@./out

debug2: out.s lib/printint.c
	@cc -ggdb out.s lib/printint.c -o out
	@gdb out

clean:
	@rm -f compiler out *.o *.s *.out
