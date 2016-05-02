#include "Common.h"
#include <iostream>
#include "conio.h"





int main(){

	Matrix_m  m(1500, 1500, 1);
	Matrix_m mm(1500, 1500, 1);
	Matrix_m mmm(1500, 1, 1);

	Matrix_m ans_v((m)._row, (mmm)._col, 0);
	Matrix_m ans2_v((m)._row, (mmm)._col, 0);
	Matrix_m ans4_v((m)._row, (mmm)._col, 0);
	Matrix_m ans16_v((m)._row, (mmm)._col, 0);
	Matrix_m ans32_v((m)._row, (mmm)._col, 0);
	
	cout << "matrix with vector \n" << endl;

	pthread_m_m(&m, &mmm, &ans_v, 1, 0);
	pthread_m_m(&m, &mmm, &ans2_v, 2, 0);	
	pthread_m_m(&m, &mmm, &ans4_v, 4, 0);
	pthread_m_m(&m, &mmm, &ans16_v, 16, 0);
	pthread_m_m(&m, &mmm, &ans32_v, 32, 0);

	Matrix_m ans((m)._row, (mm)._col, 0);
	Matrix_m ans2((m)._row, (mm)._col, 0);
	Matrix_m ans4((m)._row, (mm)._col, 0);
	Matrix_m ans16((m)._row, (mm)._col, 0);
	Matrix_m ans32((m)._row, (mm)._col, 0);
	cout << "matrix with matrix \n" << endl;
	pthread_m_m(&m, &mm, &ans, 1, 1);
	pthread_m_m(&m, &mm, &ans2, 2, 1);
	pthread_m_m(&m, &mm, &ans4, 4, 1);
	pthread_m_m(&m, &mm, &ans16, 16, 1);
	pthread_m_m(&m, &mm, &ans32, 32, 1);
	


	printf("\ndone");

	_getch();
	return 0;
}