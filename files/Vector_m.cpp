#include "Vector_m.h"

#ifndef _Common_
#include "Common.h"
#endif

#include <iostream>

Vector_m::Vector_m(int m) : _row(m){

	arr = new int[_row];
}
void Vector_m::fill(int * values){
	for (int i = 0; i < _row; i++)
	{
		arr[i] = *(values + i);

	}

}
void Vector_m::print(void){
	for (int i = 0; i < _row; i++)
	{
		printf("%d \n", arr[i]);
	}

}


Vector_m Vector_m::m_v_mul(Matrix_m a, Vector_m b){

	Vector_m ans(a._row);
	int size = ans._row;
	int * ary = new int[size];
	for (int i = 0; i < size; i++)
	{
		ary[i] = 0;
	}

	for (int i = 0; i < a._row; i++)
	{
		for (int j = 0; j < a._col; j++)
		{

			ary[i] += a.arr[(i*(a._row)) + j] * b.arr[j];

		}
	}
	/*for (int i = 0; i < size; i++){ printf("%d   ", ary[i]); }
	printf("\n");*/
	ans.fill(ary);
	ans.print();

	return ans;
}