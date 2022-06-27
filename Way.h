#pragma once
#include <iostream>
#include "Vertice.h"
using namespace std;
class way
{
private:
	void swap(int& a, int& b);
	vector<int> path;
	int size = 0;

public:

	void operator +=(const vertice& v);

	inline int Size() { return size; }

	friend ostream& operator<<(ostream& os, const way& a);
	friend way max(way& a, way& b);
};
