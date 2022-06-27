#include "Vertice.h"

using namespace std;
int vertice::vertice_count = 0;

vertice::vertice()
{
	index_ = vertice_count;
	vertice_count++;
}

vertice::~vertice()
{
	vertice_count--;
}

void connect(vertice& v1, vertice& v2)
{
	v1.Count++;
	v1.neighbours.emplace_back(&v2);

	v2.neighbours.emplace_back(&v1);
	v2.Count++;
}

bool are_connected(vertice& v1, vertice& v2)
{
	for (int i = 0; i < v1.Count; i++)
		if (v1.neighbours[i] == &v2) return true;

	return false;
}

vertice* vertice::neighbour(int i) const
{
	return neighbours[i];
}