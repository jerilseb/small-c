INCDIR=/tmp/include
BINDIR=/tmp

SRCS= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c \
	sym.c tree.c types.c

# INPUTS= test/input.c
INPUTS= test/input1.c test/input2.c

jcc: $(SRCS)
	@cc -o jcc -DINCDIR=\"$(INCDIR)\" $(SRCS)

install: jcc
	mkdir -p $(INCDIR)
	rsync -a include/. $(INCDIR)

.PHONY: compile assemble run debug_build clean

compile: jcc $(INPUTS)
	@./jcc -S $(INPUTS)

assemble: jcc $(INPUTS)
	@./jcc -c $(INPUTS)

run: jcc $(INPUTS)
	@./jcc -T -o test/output $(INPUTS)
	@./test/output

debug_build: $(SRCS)
	@cc -ggdb -o jcc -DINCDIR=\"$(INCDIR)\" $(SRCS)
	# @gdb --args compiler test/input.c

pre:
	@cpp -nostdinc -isystem $(INCDIR) test/input1.c

clean:
	@rm -f jcc a.out *.o *.s *.out test/*.o test/*.s test/output
