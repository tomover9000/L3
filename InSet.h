#pragma once
class InSet {
private:
	int* m;
	int capacity;
	int size = 0;
public:
	InSet(int);
	~InSet();
	void add(int);
	void remove(int);
	int contains(int);
	void print();
};
