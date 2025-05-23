CC = gcc
BISON = bison
FLEX = flex
CFLAGS = -Wall
LDFLAGS = -lfl  # Ou -ll, dependendo do sistema

all: compilador

compilador: arv.o tabela.o parser.tab.o lex.yy.o
	$(CC) $^ -o $@ $(LDFLAGS)

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y

lex.yy.c: scan.l 
	$(FLEX) $<

arv.o: arv.c arv.h
	$(CC) $(CFLAGS) -c arv.c -o arv.o

tabela.o: tabela.c tabela.h
	$(CC) $(CFLAGS) -c tabela.c -o tabela.o

parser.tab.o: parser.tab.c parser.tab.h
	$(CC) $(CFLAGS) -c parser.tab.c -o parser.tab.o

lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c -o lex.yy.o

clean:
	rm -f *.o parser.tab.* lex.yy.c compilador