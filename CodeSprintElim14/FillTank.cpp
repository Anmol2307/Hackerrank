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

typedef pair<int,int> pii;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vii;
typedef priority_queue<pii, vpii, greater<pii> > pqii;

#define INF (1<<30)
#define N 1000001

vpii graph[N];

vi vec;
vi min_vals(N,INF);


void compute_vals() {
    int small = vec[0];
    min_vals[0] = 0;
    pqii Q;
    Q.push(pii(0,0));
    while (!Q.empty()) {
      pii ref = Q.top();
      Q.pop();
      int v = ref.second, d = ref.first;
      if (d <= min_vals[v]) {
        int sz = graph[v].size();
        for (int i = 0; i < sz; i++) {
          int v2 = graph[v][i].first, cost = graph[v][i].second;
          if (min_vals[v2] > (min_vals[v] + cost)) {
            min_vals[v2] = min_vals[v] + cost;
            Q.push(pii(min_vals[v2],v2));
          }
        }
      }
    }
}

void create_graph () {
  int sz = vec.size();
  int small = vec[0];
  for (int i = 1; i < sz; i++) {
    for (int j = 0; j < small; j++) {
      graph[j].push_back(pii((j+vec[i])%small,(j+vec[i])/small));
    }
  }
}

// void print_graph() {
//   int small = vec[0];
//   for (int i = 0; i < small; i++) {
//     printf("Neighbours of %d are :\n",i);
//     for (int j = 0; j < graph[i].size(); j++) {
//       printf("Node - %d, Weight - %d\n",graph[i][j].first, graph[i][j].second);
//     }
//   }
// }

int main () {
  int B, Q;
  inp(B); inp(Q);
  for (int i = 0; i < B; i++) {
    int x; inp(x);
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  create_graph();
  compute_vals();
  int small = vec[0];
  for (int i = 0; i < Q; i++) {
    int y; inp(y);
    int ym = y%small;
    if (y >= (lli)((lli)small*(lli)min_vals[ym] + (lli)ym)) printf("yes\n");
    else printf("no\n");
  }
}

