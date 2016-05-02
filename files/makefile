matrix : main.o Common.o Matrix_m.o Vector_m.o
	g++ main.o Common.o Matrix_m.o Vector_m.o

main.o : main.cpp Common.h 
	g++ -c main.cpp

Common.o : Common.cpp -lpthread Vector_m.h
	g++ -c Common.cpp

Matrix_m.o : Matrix_m.cpp Matrix_m.h
	g++ -c Matrix_m.cpp
Vector_m.o : Vector_m.cpp Vector_m.h Matrix_m.h
	g++ -c Vector_m.cpp

clean : 
	rm main.o Common.o Matrix_m.o Vector_m.o
