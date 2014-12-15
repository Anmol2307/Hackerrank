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
typedef long long int ll;
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
#define N 222222

ll dist (ll x1, ll y1) {
  return x1*x1 + y1*y1;
}


int main () {
  int n;
  inp(n);
  ll R[n];
  for (int i = 0; i < n; i++) {
    scanf("%lli",&R[i]);
  }
  sort(R,R+n);
  int m;
  inp(m);

  ll ans = 0;
  for (int i = 0; i < m; i++) {
    ll x1, y1, x2, y2;
    scanf("%lli %lli %lli %lli",&x1,&y1,&x2,&y2);
    int j, k;
    if (dist(x1,y1) < dist(x2,y2)) {
      for (j = 0; j < n; j++) {
        ll first = x1*x1 + y1*y1 - R[j]*R[j];
        if (first < 0) break;
      }
      for (k = n-1; k >= 0; k--) {
        ll first = x2*x2 + y2*y2 - R[k]*R[k];
        if (first > 0) break;
      }
      ans += k-j+1;
    }
    else {
      for (j = 0; j < n; j++) {
        ll first = x2*x2 + y2*y2 - R[j]*R[j];
        if (first < 0) break;
      }
      for (k = n-1; k >= 0; k--) {
        ll first = x1*x1 + y1*y1 - R[k]*R[k];
        if (first > 0) break;
      }
      ans += k-j+1;
    }
  }
  printf("%lli\n",ans);
}