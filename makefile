CC = gcc
BISON = bison
FLEX = flex
CFLAGS = -Wall
LDFLAGS = -lfl # Ou -ll, dependendo do sistema

# Todos os arquivos objeto necessários para o compilador
OBJS = arv.o tabela.o parser.tab.o lex.yy.o quads.o gen_code.o

all: compilador

compilador: $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

# Regras para gerar os arquivos C a partir de .y e .l
parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y

lex.yy.c: scan.l parser.tab.h # lex.yy.c depende de parser.tab.h para as definições de tokens
	$(FLEX) $<

# Regras para compilar os arquivos .c em .o
arv.o: arv.c arv.h
	$(CC) $(CFLAGS) -c $< -o $@

tabela.o: tabela.c tabela.h
	$(CC) $(CFLAGS) -c $< -o $@

parser.tab.o: parser.tab.c parser.tab.h
	$(CC) $(CFLAGS) -c $< -o $@

lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -c $< -o $@

quads.o: quads.c quads.h
	$(CC) $(CFLAGS) -c $< -o $@

gen_code.o: gen_code.c gen_code.h arv.h quads.h # gen_code.o depende de arv.h e quads.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) parser.tab.* lex.yy.c compilador