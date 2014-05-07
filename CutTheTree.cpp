#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int * cost;
vector <pair<int,int> > edges;
vector <list <int> > graph;
bool * visited;

int findcost (int vertex) {
	int ans = cost[vertex];
	visited[vertex] = 1;
	list<int>::iterator it;
	for (it = graph[vertex].begin(); it != graph[vertex].end();it++) {
		if (!visited[*it]) ans += findcost(*it);
	}
	return ans;
}


int main () {
	int n;
	cin >> n;
	
	cost = new int[n+1];
	visited = new bool[n+1];
	graph.assign(n+1,*new list<int>);
	
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	
	for (int i = 0 ; i < n-1; i++) {
		int x, y;
		cin >> x >> y;

		pair <int, int> edge = make_pair(x,y);
		edges.push_back(edge);

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int first, second, min = 1000;
	for (int i = 0; i < edges.size();i++) {
		memset(visited,0,(n+1)*sizeof(bool));
		pair <int, int> edge = edges[i];
		int x = edge.first;
		int y = edge.second;
		graph[x].remove(y);
		graph[y].remove(x);
		first = findcost(x);
		second = findcost(y);

		if ( min > abs(first-second)) min = abs(first - second);
		graph[x].push_back(y);
		graph[y].push_back(x);	
	}
	cout << min << endl;

}