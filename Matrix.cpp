#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int n) {
	size = n;
	M = new double*[size];
	for (int i = 0; i < size; i++) {
		M[i] = new double[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			M[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < size; i++) {
	//	cout << "Index delete: " << i << endl;
		delete[] M[i];
	}
	//cout << "Destructing pointer..." << endl;
	delete[] M;
}

void Matrix::copy(Matrix* m) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			M[i][j] = m->M[i][j];
		}
	}
}

void Matrix::setRand(double min, double max) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			M[i][j] = rand() % (int)max + min;
		}
	}
}
void Matrix::print() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << this->M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Matrix::set() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> M[i][j];
		}
	}
}

void Matrix::add(Matrix matrix1) {
	if (size == matrix1.size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				M[i][j] += matrix1.M[i][j];
			}
		}
	}
	else {
		cout << "Sizes do not match" << endl;
	}
}

void Matrix::prod(Matrix* matrix) {
	Matrix res(size);
	if (size == matrix->size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					res.M[i][j] += this->M[i][k] * matrix->M[k][j];
				}
			}
		}
	}
	else {
		cout << "Sizes do not match" << endl;
	}
	this->copy(&res);
}

void Matrix::power(int n) {
	Matrix* it = new Matrix(size);
	it->copy(this);
	for (int i = 1; i < n; i++) {
		(*this).prod(it);
	}
}
