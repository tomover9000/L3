#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h" 
#include "InSet.h"

using namespace std;

int main() {
	
	// Am separat clasa Matrix in fisiere separate de header si sursa 

	Matrix m(3);
	m.setRand(1, 2);
	m.print();
	m.power(2);
	m.print();

	//Am facut o mica posibilitate de selectie direct din consola

	// Am separat si clasa InSet in fisiere diferite

	int num;
	cout << "Introduceti marimea multimii: ";
	cin >> num;
	InSet multime(num);
	char c;
	do {
		cout << "(a)dd/(r)emove/(c)ontains/(p)rint/(e)xit: ";
		cin >> c;
		switch (c) {
		case 'a':
			cout << "Type a number to add: ";
			cin >> num;
			multime.add(num);
			break;
		case 'r':
			cout << "Type a number to remove: ";
			cin >> num;
			multime.remove(num);
			break;
		case 'c':
			cout << "Type a number to check: ";
			cin >> num;
			if (multime.contains(num)) {
				cout << num << " este in multime" << endl;
			}
			else {
				cout << num << " nu este in multime" << endl;
			}
			break;
		case 'p':
			multime.print();
			break;
		}
	} while (c != 'e');
}

