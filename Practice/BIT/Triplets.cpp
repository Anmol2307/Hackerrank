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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 100005

map<int,int> m;
int arr[N];
set<int> s;

class FenwickTree
{
private:
    long long tree[N];

public:
    FenwickTree()
    {
        memset(tree, 0, sizeof(tree));
    }

    long long get(int idx)
    {
        return query(idx) - query(idx - 1);
    }

    void set(int idx, long long val)
    {
        long long curr = get(idx);
        update(idx, val - curr);
    }

    void update(int idx, long long val)
    {
        while (idx <= N)
        {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    long long query(int idx)
    {
        long long sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};

FenwickTree a, b, c;

int main () {
  int n;
  inp(n);
 
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
    s.insert(arr[i]);
  }

  int cnt = 1;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    m[*it] = cnt++;
  }

  for (int i = 0; i < n; i++) {
    int x = m[arr[i]];
    a.set(x,1);
    b.set(x,a.query(x-1));
    c.set(x,b.query(x-1));
  }
  printf("%lli\n",c.query(N));
}