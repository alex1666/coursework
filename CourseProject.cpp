#include <iostream>
#include <fstream>
#include "Graph.h"
#include <string>
#include <sstream> 
#include <omp.h>

using namespace std;
int Size(std::string line)
{
	stringstream ss;
	ss << line;

	int val;
	int size = 0;

	while (!ss.eof())
	{
		if (ss >> val)
		{
			size++;
		}
	}
	return size;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	omp_set_num_threads(4);
#ifdef _OPENMP 
	cout << "openmp support\n";
#endif
	graph Graph;

	ifstream input;
	input.open("matrix.txt");
	if (!input) {
		cerr << "нет файла матрицыn";
		return 1;
	}

	string line;
	getline(input, line);

	int size = Size(line);

	vertice* v = new vertice[size];
	for (int i = 0; i < size; i++)
		Graph.add_vertice(&v[i]);

	int i = 0; // Проходимся по файлу и добавляем вершины в смежные друг к другу увеличивая число смежных вершин у каждой вершины
	while (!input.eof())
	{
		stringstream ss;
		ss << line;
		int val;

		int j = 0;
		while (!ss.eof())
		{
			if (ss >> val)
			{
				if (val == 1) {
					//если вершины смежные но еще не добавлены то добавляем
					if (!are_connected(v[i], v[j])) connect(v[i], v[j]);
				}
			}
			j++;
		}
		getline(input, line);
		i++;
	}

	Graph.longest_path();
}