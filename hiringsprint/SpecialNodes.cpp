#include <iostream>
#include <algorithm>
#define pair<int,int> pii
#define N 100005

using namespace std;

vector<pii> ppii[N];
vector<int> special;

int main () {
	int n, m;
	scanf("%d %d",&n, &m);

	for (int i = 0; i < m; i++) {
		int u,v,w;
		scanf("%d %d %d",&u, &v, &w);		
		ppii[u].push_back(pii(v,w));
		ppii[v].push_back(pii(u,w));
	}

	int s;
	scanf("%d",&s);

	for (int i = 0; i < s; i++) {
		int tmp;
		scanf("%d",&tmp);
		special.push_back(tmp);
	}

	
}