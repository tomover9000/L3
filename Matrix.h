#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
	double** M;
	int size;
public:
	void add(Matrix);
	void prod(Matrix*);
	void print();
	void setRand(double, double);
	void set();
	void power(int);
	void copy(Matrix*);
	Matrix(int);
	~Matrix();
};

#endif
