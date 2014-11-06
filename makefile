all: stack

stack_functions.o: stack_functions.cpp stack_functions.h
	g++ -c stack_functions.cpp

stack_main.o: stack_main.cpp stack_functions.h stack_functions.cpp
	g++ -c stack_main.cpp

stack:	stack_main.o stack_functions.o
	g++ stack_functions.o stack_main.o -o stack.exe

clean:
	rm -rf *.o
	rm -rf stack.exe

