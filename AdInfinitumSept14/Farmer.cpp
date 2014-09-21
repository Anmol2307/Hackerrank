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

typedef long long int lli;

#define N 100005

struct node {
  int val;
  node():val(0){}
  void init (int s) {
    val = s;
  }
  void merge (node &l, node &r) {
    val = l.val*r.val;
  }
}tree[4*N];

vector <pair<lli,lli> > arr(N);
int n;

int check (int index) {
  lli val = arr[index].first*x + arr[index].second - y;
  if (val > 0) {
    return 1;
  }
  else return 0;
}

void build_tree(int node, int a, int b) {
  if(a > b) return;
    
  if(a == b) {
    int s = check(a);
    tree[node].init(s);
    return;
  }

  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
  tree[node].merge(tree[node*2], tree[node*2+1]);
}

int query_tree(int node, int a, int b, int i, int j) {
  
  if (a==i && b==j) return tree[node].val;
  int mid = (a+b)/2;
  if (j <= mid) {
    return query_tree((node<<1), a, mid, i, j);
  }
  if (i > mid) {
     return query_tree((node<<1) + 1, mid+1,b,i,j);
  }
  int left = query_tree((node<<1), a, mid, i, mid);
  int right = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
  return left*right;
}


int main () {
  
  inp(n);
  for (int i = 0; i < n; i++) {
    lli x, y;
    scanf("%lli %lli", &x, &y);
    pair<lli,lli> pii(x,y);
    vec[i] = pii;
  }

  int q;
  inp(q);
  for (i = 0; i < q; i++) {
    lli L, R, x, y;
    scanf("%lli %lli %lli %lli", &L, &R, &x, &y);
    if (query_tree(1,0,n-1,L-1,R-1) == 1) printf("YES\n");
    else printf("NO\n");
  }
}