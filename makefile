all: stack

stack_functions.o:
	g++ -c stack_functions.cpp

stack_main.o:
	g++ -c stack_main.cpp

stack:	stack_main.o stack_functions.o
	g++ stack_functions.o stack_main.o -o stack

clean:
	rm -rf *.o
	rm -rf -f stack

