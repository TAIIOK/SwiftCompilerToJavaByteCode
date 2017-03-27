all: clean swiftComp

swiftComp: swift.tab.o lex.yy.o
	g++ lex.yy.o swift.tab.o -o swiftComp

swift.tab.o: swift.tab.c tree_nodes.h tree_nodes_funcs.h tree_print.h
	g++ -c swift.tab.c

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

lex.yy.c:
	flex ../lexer/swift.yy

swift.tab.c:
	bison -d ../bison/swift.y

tree_nodes.h:
	cp ../bison/tree_nodes.h ./

tree_nodes_funcs.h:
	cp ../bison/tree_nodes_funcs.h ./

tree_print.h:
	cp ../bison/tree_print.h ./


clean:
	rm -rf *.o *.h *.c swiftComp
