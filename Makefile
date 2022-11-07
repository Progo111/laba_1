PROJECT = main
CC = clang++


$(PROJECT): main.o func.o
	$(CC) main.o func.o -o $(PROJECT)


main.0: main.cpp
	$(CC) main.cpp -o main.o


func.0: func.cpp
	$(CC) func.cpp -o func.o

clear:
	rm $(PROJECT) *.o