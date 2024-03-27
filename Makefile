EXEC = PJ3
CC = clang++
CFLAGS = -c -Wall

$(EXEC)	:main.o util.o stack.o heap.o graph.o
	$(CC) -o $(EXEC) main.o util.o heap.o graph.o stack.o -g 
	
main.o	:main.cpp data_structures.h util.h stack.h heap.h graph.h
	$(CC) $(CFLAGS) main.cpp -g 
	
util.o	:util.cpp util.h data_structures.h
	$(CC) $(CFLAGS) util.cpp -g 
	
stack.o	:stack.cpp stack.h data_structures.h
	$(CC) $(CFLAGS) stack.cpp -g 

heap.o	:heap.cpp heap.h data_structures.h
	$(CC) $(CFLAGS) heap.cpp -g 

graph.o	:graph.cpp graph.h data_structures.h stack.h heap.h
	$(CC) $(CFLAGS) graph.cpp -g 

clean	:
	rm *.o $(EXEC)
