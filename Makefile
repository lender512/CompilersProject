main: scanner.l lex.yy.c lexer
	flex scanner.l && gcc -lfl lex.yy.c -o lexer && ./lexer < main.ce > tokens.txt
