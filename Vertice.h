#pragma once

#include <vector>
using namespace std;
struct vertice
{
private:
	static int vertice_count;
	int index_;

	int Count = 0;
	vector<vertice*> neighbours;

public:
	vertice();
	~vertice();
	friend void connect(vertice& v1, vertice& v2);
	friend bool are_connected(vertice& v1, vertice& v2);
	vertice* neighbour(int i) const;  
	inline int index() const { return index_; }
	inline int hood_size() const { return Count; }
	friend class graph;
};

