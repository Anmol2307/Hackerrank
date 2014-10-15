#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

#define N 100005
typedef pair<int,int> pii;

int arr[N];
vector <vector <int> > graph(N);
int parent[N];
int visited[N];

void update_cost () {
  stack<int> S;
  S.push(1);

  while (!S.empty()) {
    int val = S.top();
    S.pop();
    visited[val] = 1;
    for (int i = 0; i < graph[val].size(); i++) {
      if (visited[val] == 0) {
        S.push(graph[val][i]);
        break;
      }
    }
  }
}


int main () {
  int n, k;
  inp(n); inp(k);

  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }

  for (int i = 0; i < n-1; i++) {
    int x, y; 
    inp(x); inp(y);
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  // for (int i = 1; i <= n; i++) {
  //   printf("Neighbours of %d\n",i);
  //   for (int j = 0; j < graph[i].size(); j++) {
  //     printf("%d %d\n",graph[i][j].first, graph[i][j].second);
  //   }
  //   printf("\n");
  // }

  queue<int> Q;
  Q.push(1);

  while (!Q.empty()) {
    int val = Q.front();
    Q.pop();
    visited[val] = 1;
    for (int j = 0; j < graph[val].size(); j++) {
      if (visited[graph[val][j]] == 0) {
        parent[graph[val][j]] = val;
        Q.push(graph[val][j]);
      }
    }
  }


  // for (int i = 1; i <= n; i++) {
  //   printf("Parent of %d is %d\n",i,parent[i]);
  // }

  update_cost();

}