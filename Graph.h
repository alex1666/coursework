#pragma once
#include <vector>
#include "Vertice.h"
#include "Way.h"
using namespace std;
class graph {
	int Size;
	vector< vertice*> vertices;
	void dfs(const vertice* v, bool vis[], vector<way>& paths);
public:

	graph();
	~graph();

	void add_vertice(vertice* v);
	void longest_path();

};

