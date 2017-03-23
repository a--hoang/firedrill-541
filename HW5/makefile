all: main.cpp matrix.o
	g++ -o hw5 main.cpp matrix.o

matrix.o: Matrix.h Matrix.cpp
	g++ -c Matrix.cpp

clean:
	rm *.o
