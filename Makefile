SRCS= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c \
	sym.c tree.c types.c

INPUTS= test/input1.c test/input2.c

jcc: $(SRCS)
	@cc -o $@ $(SRCS)

.PHONY: compile

compile: jcc $(INPUTS)
	@./jcc -S $(INPUTS)

run: jcc $(INPUTS)
	@./jcc -o test/output $(INPUTS)
	@./test/output

debug_build: $(SRCS)
	@cc -ggdb -o jcc $(SRCS)
	# @gdb --args compiler test/input.c

clean:
	@rm -f jcc out *.o *.s *.out test/*.o test/*.s test/output
