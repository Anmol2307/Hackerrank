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


ll modpow(ll a, ll b, ll MOD) {
    ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

 
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) {
    ll x = 1, y = 0;
    ll xLast = 0, yLast = 1;
    ll q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
ll modInverse(ll a, ll m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    ll a, b, x;
    scanf("%lli %lli %lli", &a, &b, &x);
    ll ans=0;
    if (b < 0) {
      ll val = modInverse(a,x);
      ans = modpow(val,-b,x);
    }
    else {
      ans = modpow(a,b,x);
    }
    printf("%lli\n",ans);
  }
}