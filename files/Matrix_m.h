
#define _Matrix_

using namespace std;
class Matrix_m
{
public:
	int  *  arr;
	int size;

	Matrix_m(int a, int b ,int c);
	void fill(int * values);
	void print(void);

	const int _col;
	const int _row;

	void Matrix_m::m_m_mul(Matrix_m a, Matrix_m b);
	void populate_m(int c);
	void operator*(Matrix_m & m)
	{
		return m_m_mul(*this, m);
	}
};

