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
#define N 1000005

int n;
ll R[N];

ll dist (ll x1, ll y1) {
  return x1*x1 + y1*y1;
}

int binSearchLower(ll xa, ll ya) {
  int l = 0;
  int h = n-1;
  int m = -1;
  while (l <= h) {
    m = l + (h-l)/2;
    // ll res1 = xa*xa + ya*ya - R[m]*R[m];
    // ll res2 = xa*xa + ya*ya - R[m-1]*R[m-1];
    if ((xa*xa + ya*ya - R[m]*R[m]) < 0 && (m == 0 || (m > 0 && (xa*xa + ya*ya - R[m-1]*R[m-1]) > 0) )) return m;
    else if ((xa*xa + ya*ya - R[m]*R[m]) < 0) {
      h = m-1;
    }
    else if ((xa*xa + ya*ya - R[m]*R[m]) > 0) {
      l = m+1;
    }
  }
  return -1;
}


int binSearchUpper(ll xb, ll yb) {
  int l = 0;
  int h = n-1;
  int m = -1;
  while (l <= h) {
    m = l + (h-l)/2;
    // ll res1 = xb*xb + yb*yb - R[m]*R[m];
    // ll res2 = xb*xb + yb*yb - R[m+1]*R[m+1];
    if ((xb*xb + yb*yb - R[m]*R[m]) > 0 && (m == n-1 || (m < n-1 && (xb*xb + yb*yb - R[m+1]*R[m+1]) < 0))) return m;
    else if ((xb*xb + yb*yb - R[m]*R[m]) > 0) {
      l = m+1;
    }
    else if ((xb*xb + yb*yb - R[m]*R[m]) < 0) {
      h = m-1;
    }
  }
  return -1;
}


int main () {
  inp(n);
  for (int i = 0; i < n; i++) {
    scanf("%lli",&R[i]);
  }
  sort(R,R+n);
  int m;
  inp(m);

  ll ans = 0;
  for (int i = 0; i < m; i++) {
    ll xa,ya,xb,yb;
    scanf("%lli %lli %lli %lli",&xa,&ya,&xb,&yb);
    if (dist(xa,ya) <= dist(xb,yb)) {
      int j = binSearchLower(xa, ya);
      int k = binSearchUpper(xb, yb);
      // printf("1 Lower %d Higher %d\n",j,k);
      if (j != -1 && k != -1 && k >= j) ans += k-j+1;  
    }
    else {
      int j = binSearchLower(xb, yb);
      int k = binSearchUpper(xa, ya);
      // printf("2 Lower %d Higher %d\n",j,k);
      if (j != -1 && k != -1 && k >= j) ans += k-j+1;  
    }
  }
  printf("%lli\n",ans);
}