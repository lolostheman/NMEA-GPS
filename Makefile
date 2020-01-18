output: main.o hw5.o
	g++ main.o hw5.o -o output

main.o: main.cpp
	g++ -c main.cpp

matrix.o: hw5.cpp hw5.h
	g++ -c hw5.cpp

clean:
	rm *.o output
