#include <iostream>
#include "InSet.h"

using namespace std;

InSet::InSet(int n) {
	m = new int[n];
	capacity = n;
}

InSet::~InSet() {
	delete[] m;
}

void InSet::print() {
	for (int i = 0; i < size; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}

void InSet::add(int a) {
	if (!contains(a) && capacity != size) {
		m[size] = a;
		size++;
	}
	else if (capacity != size) {
		cout << a << " se afla deja in multime" << endl;
	}
	else {
		cout << "Multimea este plina" << endl;
	}
}

void InSet::remove(int a) {
	int index = contains(a) - 1;
	int temp;
	if (index + 1) {
		for (int i = index; i < size - 1; i++) {
			temp = m[i];
			m[i] = m[i + 1];
			m[i + 1] = temp;
		}
		size--;
	}
	else {
		cout << a << " nu se afla in multime" << endl;
	}
}

int InSet::contains(int a) {
	for (int i = 0; i < size; i++) {
		if (m[i] == a) {
			return i + 1;
		}
	}
	return 0;
}

