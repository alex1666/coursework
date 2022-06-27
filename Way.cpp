#include "Way.h"
using namespace std;
void way::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void way::operator +=(const vertice& v)
{

	path.emplace_back(v.index());
	size++;
}

ostream& operator<<(ostream& os, const way& a)
{
	for (auto i = a.path.rbegin(); i != a.path.rend() - 1; ++i)
	{
		os << *i << " - ";
	}
	cout << a.path[0];
	return os;
}


way max(way& a, way& b)
{
	if (a.size > b.size) return a;
	return b;
}
