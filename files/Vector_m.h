#include "Common.h"

using namespace std;
class Vector_m
{

public:
	int *arr;
	Vector_m(int m);
	void print(void);
	void fill(int * values);

	const int _row;
	Vector_m m_v_mul(Matrix_m a, Vector_m b);
	Vector_m operator*(Matrix_m & m)
	{
		return m_v_mul(m, *this);


	}

};