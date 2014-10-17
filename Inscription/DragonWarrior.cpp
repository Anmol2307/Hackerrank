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
#define N 1005


bool cmp(const pair<int,int>& p,const pair<int,int>& q) {
  if (p.first < q.first) return 1;
  else if (p.first == q.first && p.second <= q.second) return 1;
  else return 0;
}

int main () {
  ll a, z;
  scanf("%lli %lli", &a, &z);
  int q, k;
  inp(q); inp(k);

  vector<pii> vec;

  for (int i = 0; i < k; i++) {
    int x, y;
    inp(x); inp(y);
    vec.push_back(pii(x,y));
  }

  sort(vec.begin(), vec.end(),cmp);

  ll ans = a + z;
  int prevx = vec[0].first;
  int prevy = vec[0].second;

  for (int i = 1; i < k; i++) {
    int nextx = vec[i].first;
    int nexty = vec[i].second;
    if (prevx == nextx || prevy == nexty) 
      ans += a + z - (ll)(max(abs(nexty-prevy), abs(nextx-prevx)));
    else ans += a + z - (ll)(min(abs(nexty-prevy), abs(nextx-prevx)));
    prevx = nextx;
    prevy = nexty;
  }

  if (ans >= q) printf("1\n");
  else printf("0\n");
}