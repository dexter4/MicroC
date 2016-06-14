# ======================================================================

DIR = tm
FILES = Makefile parser.y scanner.l

# ======================================================================

tm:	parser.o scanner.o tmlibinclude.o
	gcc -O -o tm parser.o scanner.o tmlibinclude.o -lfl

libtminclude.o:
	gcc -O -c tmlibinclude.c

parser.o:	parser.c
	gcc -O -c parser.c

parser.c:	parser.y
	bison -d parser.y
	mv parser.tab.c parser.c
	mv parser.tab.h parser.h

scanner.o:	scanner.c
	gcc -O -c scanner.c

scanner.c:	scanner.l
	flex scanner.l
	mv lex.yy.c scanner.c

# ======================================================================

install:	tm
	install tm /usr/local/bin

# ======================================================================

pdf:	$(FILES)
	a2ps --medium=A4 --line-numbers=1 $(FILES) -o $(DIR).ps
	ps2pdf -sPAPERSIZE=a4 $(DIR).ps $(DIR).pdf
	@rm -f $(DIR) $(DIR).ps

# ======================================================================

clean:
	@rm -rf .*~ *~ tm parser.c parser.h scanner.c *.o *.ps *.pdf
	@(cd tests; make clean)

# ======================================================================
