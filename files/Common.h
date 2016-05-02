#include "Matrix_m.h"

#define _Common_

using namespace std;

void mul(int *  __restrict a_arr, int *  __restrict b_arr, int size, int * __restrict  ary, int a_row_e, int a_col_e, int b_col_e);
void v_mul(int * __restrict  a_arr, int *  __restrict b_arr, int size, int * __restrict  ary, int a_row_e, int a_col_e, int b_col_e);
void *mul1(void * st);
void *v_mul1(void * st);
void pthread_m_m_value(Matrix_m a, Matrix_m b, Matrix_m ans, int threads, int z);
void pthread_m_m(Matrix_m * __restrict  a, Matrix_m* __restrict  b, Matrix_m* __restrict  ans, int threads, int z);

struct arg_list{
	int *  __restrict a_arr;
	int * __restrict  b_arr;
	int size;
	int * __restrict  ary;
	int a_row_s;
	int a_row_e;
	int a_col_e;
	int b_col_e;

};