bison -d -v a.y
flex a.l
g++ lex.yy.c a.tab.c -o parser1 -lfl 
./parser1 < in.txt > out.txt
bison -d -v code.y
flex code.l
g++ lex.yy.c code.tab.c -o parser2 -lfl 
./parser2 < out.txt > out.s
spim -file out.s
