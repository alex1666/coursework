#include "Graph.h"
#include "Windows.h"
using namespace std;
graph::graph()
{
	Size = 0;
}
graph::~graph()
{
	vertices.clear();
}

void graph::add_vertice(vertice* v)
{
	vertices.push_back(v);
	Size++;
}

void graph::dfs(const vertice* v, bool vis[], vector<way>& paths)
{
	vis[v->index()] = true;
	bool* visited = new bool[vertice::vertice_count];


	for (int i = 0; i < v->Count; i++)
	{
		if (!vis[v->neighbour(i)->index()])
		{
			for (int j = 0; j < vertice::vertice_count; j++)
				visited[j] = vis[j];

			vector<way> temp;
			dfs(v->neighbour(i), visited, temp);

			if ((paths).empty())
			{
				paths = temp;
			}
			else if ((paths[0]).Size() < (temp[0]).Size())
			{
				paths.clear();
				for (auto i : temp)
				{
					paths.push_back(i);
				}
			}
			else if ((paths[0]).Size() == (temp[0]).Size())
			{
				for (auto i : temp)
				{
					paths.push_back(i);
				}
			}
		}
	}

	if ((paths).empty())
	{
		way t;
		t += (*v);
		paths.push_back(t);
	}
	else
	{
		for (int i = 0; i < paths.size(); i++)
		{
			paths[i] += (*v);
		}
	}
}



void graph::longest_path()
{
	bool* visited = new bool[vertice::vertice_count];
	for (int i = 0; i < vertice::vertice_count; i++)
		visited[i] = false;

	vector<way> paths;
#pragma omp parallel for firstprivate(visited, temp) shared(vertices,paths)
	for (int i = 0; i < Size; i++)
	{
		vector<way> temp;
		Sleep(500);
		for (int i = 0; i < vertice::vertice_count; i++)
			visited[i] = false;

		dfs(vertices[i], visited, temp);

#pragma omp critical
		{
		if (paths.empty()) paths = temp;

		else if (paths[0].Size() < temp[0].Size())
		{
			paths.clear();
			paths = temp;
		}
		else if (paths[0].Size() == temp[0].Size())
		{
			for (auto j : temp)
			{
				paths.push_back(j);
			}
		}
		}
	}
	cout<<"Самый длинный путь" << endl;
	for (auto i : paths)
	{
		cout << i << endl;
	}
	delete[] visited;
}
