#include <pthread.h>
#include "Vector_m.h"
#ifndef _Common_
#include "Common.h"
#endif

#include <iostream>
#include <chrono>

void pthread_m_m_value(Matrix_m a, Matrix_m b, Matrix_m ans, int threads, int z)
{
	int * a_arr = a.arr;
	int * b_arr = b.arr;
	int size = ans.size;
	int *ary = ans.arr;

	int a_row_e = a._row;
	int a_col_e = a._col;
	int b_col_e = a._col;

	if (threads < 2)
	{

		if (z == 0)
		{

			v_mul(a_arr, b_arr, size, ary, a_row_e, a_col_e, b_col_e);

		}
		else{


			clock_t begin = clock();
			mul(a_arr, b_arr, size, ary, a_row_e, a_col_e, b_col_e);
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime taken by   " << elapsed_secs << "with " << threads << " threads" << endl;
		}
	}

	else{

		if (z == 0){
			clock_t begin = clock();

			int mar = a_row_e / threads;
			int xar = threads + (a_row_e % 2);
			pthread_t* thread_id = new pthread_t[xar];
			arg_list * ll = new arg_list[xar];
			for (int i = 0; i < xar; i++){

				int x = mar*i;
				int y = mar*(i + 1);

				if (y > a_row_e){
					y = a_row_e;
				}

				ll[i] = { a_arr, b_arr, size, ary, x, y, a_col_e, b_col_e };

				pthread_create(&thread_id[i], NULL, &v_mul1, &ll[i]);

			}

			for (int i = 0; i < xar; i++){
				pthread_join(thread_id[i], NULL);
			}
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime taken by   " << elapsed_secs << "with " << threads << " threads" << endl;
		}
		else{
			clock_t begin = clock();

			int mar = a_row_e / threads;
			int xar = threads + (a_row_e % 2);
			arg_list * ll = new arg_list[xar];
			pthread_t* thread_id = new pthread_t[xar];
			for (int i = 0; i < xar; i++){

				int x = mar*i;
				int y = mar*(i + 1);

				if (y > a_row_e){

					y = a_row_e;

				}

				ll[i] = { a_arr, b_arr, size, ary, x, y, a_col_e, b_col_e };

				pthread_create(&thread_id[i], NULL, &mul1, &ll[i]);

			}
			for (int i = 0; i < xar; i++){
				pthread_join(thread_id[i], NULL);
			}
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime taken by   " << elapsed_secs << "with " << threads << " threads" << endl;
		}
	}


}
void pthread_m_m(Matrix_m * __restrict  a, Matrix_m* __restrict  b, Matrix_m* __restrict  ans, int threads, int z)
{
	int * __restrict   a_arr = (*a).arr;
	int *  __restrict  b_arr = (*b).arr;
	int size = (*ans).size;
	int *  __restrict  ary = (*ans).arr;

	int a_row_e = (*a)._row;
	int a_col_e = (*a)._col;
	int b_col_e = (*b)._col;
	
	if (threads < 2)
	{

		if (z == 0)
		{
			clock_t begin = clock();
			v_mul(a_arr, b_arr, size, ary, a_row_e, a_col_e, b_col_e);
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime taken by   " << elapsed_secs << "with " << threads << " threads" << endl;
		}
		else{

			clock_t begin = clock();
			mul(a_arr, b_arr, size, ary, a_row_e, a_col_e, b_col_e);
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime taken by   " << elapsed_secs << "with " << threads << " threads" << endl;
		}
	}

	else{

		if (z == 0){
			clock_t begin = clock();

			int mar = a_row_e / threads;
			int xar =  threads + (a_row_e % 2);
			pthread_t* thread_id = new pthread_t[xar];
			arg_list * ll = new arg_list[xar];
			for (int i = 0; i < xar; i++){

				int x = mar*i;
				int y = mar*(i + 1);

				if (y > a_row_e){

					y = a_row_e;

				}

				ll[i] = { a_arr, b_arr, size, ary, x, y, a_col_e, b_col_e };
				
			

				pthread_create(&thread_id[i], NULL, &v_mul1, &ll[i]);

			}

			for (int i = 0; i < xar; i++){
				pthread_join(thread_id[i], NULL);
			}
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime taken by  " << elapsed_secs << "with " << threads << " threads" << endl;
		}
		else{
			clock_t begin = clock();

			int mar = a_row_e / threads;
			int xar =  threads + (a_row_e % 2);
			arg_list * ll = new arg_list[xar];
			pthread_t* thread_id = new pthread_t[xar];
			for (int i = 0; i < xar; i++){

				int x = mar*i;
				int y = mar*(i + 1);

				if (y > a_row_e){

					y = a_row_e;

				}
			
				ll[i] = { a_arr, b_arr, size, ary, x, y, a_col_e, b_col_e };
			


				pthread_create(&thread_id[i], NULL, &mul1, &ll[i]);

			}
			for (int i = 0; i < xar; i++){
				pthread_join(thread_id[i], NULL);
			}
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime taken by   " << elapsed_secs << "with " << threads << " threads" << endl;
		}
	}


}

void * mul1(void *st){

	arg_list *args = new arg_list();
	memcpy(args, (arg_list*)st, sizeof(arg_list));
	
	int c = (*args).a_row_e;
	int d = (*args).a_col_e;
	int e = (*args).b_col_e;
	int * __restrict   ar = (*args).ary;
	int *  __restrict  bar = (*args).a_arr;
	int *  __restrict  car = (*args).b_arr;
	
	for (int i = (*args).a_row_s; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			for (int k = 0; k < e; k++)
			{

				ar[(i*d) + k] += bar[(i*d) + j] * car[(j*d) + k];
			}
		}
	}

	int p = 1;
	int * l = &p;
	return l;

}
void * v_mul1(void *st){

	arg_list *args = new arg_list();
	memcpy(args, (arg_list*)st, sizeof(arg_list));
	
	int c = (*args).a_row_e;
	int d = (*args).a_col_e;
	int e = (*args).b_col_e;
	int *  __restrict  ar = (*args).ary;
	int *  __restrict  bar = (*args).a_arr;
	int *  __restrict  car = (*args).b_arr;
	
	
	for (int i = (*args).a_row_s; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			ar[i] += bar[(i*c) + j] * car[j];
		}
	}


	int p = 1;
	int * l = &p;
	return l;

}
void mul(int * __restrict  a_arr, int * __restrict  b_arr, int size, int * __restrict  ary, int a_row_e, int a_col_e, int b_col_e){

	for (int i = 0; i < a_row_e; i++)
	{
		for (int j = 0; j < a_col_e; j++)
		{
			for (int k = 0; k < b_col_e; k++)
			{

				ary[(i*a_col_e) + k] += a_arr[(i*a_col_e) + j] * b_arr[(j*a_col_e) + k];
			}
		}
	}
}
void v_mul(int *  __restrict a_arr, int *  __restrict b_arr, int size, int *  __restrict ary, int a_row_e, int a_col_e, int b_col_e){

	for (int i = 0; i < a_row_e; i++)
	{
		for (int j = 0; j < a_col_e; j++)
		{

			ary[i] += a_arr[(i*a_row_e) + j] * b_arr[j];

		}
	}

}