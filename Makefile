SRCS= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c \
	sym.c tree.c types.c

jcc: $(SRCS)
	@cc -o $@ $(SRCS)

.PHONY: compile

compile: jcc test/input.c
	@./jcc -o output test/input.c

debug_build: $(SRCS)
	@cc -ggdb -o jcc $(SRCS)
	# @gdb --args compiler test/input.c

clean:
	@rm -f jcc out *.o *.s *.out test/*.o test/*.s a.out output
