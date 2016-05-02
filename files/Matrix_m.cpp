#include "Matrix_m.h"
#include <iostream>

Matrix_m::Matrix_m(int a, int b, int c) : _row(a), _col(b){

	size = _row*_col;
	arr = new int[size];
	populate_m(c);
}

void Matrix_m::populate_m(int c){

	for (int i = 0; i < size; i++){
		arr[i] = c;

	}
}
void Matrix_m::print(void){
	for (int i = 0; i < size; i++)
	{
		if (i % _col == 0){ printf("\n"); }
		printf("%d", arr[i]);
	}
}


void Matrix_m::fill(int * values){
	for (int i = 0; i < size; i++)
	{
		arr[i] = *(values + i);

	}
}