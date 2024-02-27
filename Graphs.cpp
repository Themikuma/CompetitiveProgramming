#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

queue<int> q;
const int neighbors[50][50] = {
	{0,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0,0,1,0,0 },
	{0,1,0,0,0,0,1,0,0,0,0,0,0,0 },
	{0,0,1,0,0,0,1,0,0,0,0,1,0,0 },
	{0,0,0,0,1,1,0,0,0,1,0,0,0,0 },
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0 },
	{0,0,0,0,0,0,0,1,0,0,0,0,1,1 },
	{0,0,0,0,0,0,1,0,0,0,1,0,0,0 },
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
	{0,0,0,1,0,1,0,0,0,0,0,0,0,0 },
	{0,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{0,0,0,0,0,0,0,0,1,0,0,0,1,0 }
};
const int n = 14; //Current vertices
bool visited[50];
string output;


void BFS() {
	int start;
	cin >> start;
	start--;
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int current = q.front();
		cout << current + 1 << ", ";
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (neighbors[current][i] != 0 && !visited[i])
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

void DFS(int vertex) {
	visited[vertex] = 1;
	output += to_string(vertex + 1);
	output += ", ";
	for (int i = 0; i < n; i++)
	{
		if (neighbors[vertex][i] != 0 && !visited[i])
		{
			DFS(i);
		}
	}
}

void DFSEntry() {
	int start;
	cin >> start;
	DFS(start - 1);
	output = output.substr(0, output.length() - 2);
	cout << output;
}

int main()
{
	//BFS();
	DFSEntry();
}
