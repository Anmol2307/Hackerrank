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
typedef pair< int, ll > pil;
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
#define N 20
#define MOD 1000000007
#define mx 1000000000000000000
int arr[N];
int n;
pil m[1<<17+5];

ll gcd (ll a, ll b) {
  if (b == 0) return a;
  return gcd(b,a%b);
}

ll lcm (ll a, ll b) {
  if (a > mx/b) return -1;
  return (a*b)/gcd(a,b);
}

pil numbits(int val) {
  int ans = 0;
  int i = 0;
  ll l = 1;
  while (val) {
    if (val&1) {
      ans++;
      l = lcm(l,arr[n-1-i]);
      if (l == -1) return pil(ans,l);
    }
    i++;
    val >>= 1;
  }
  return pil(ans,l);
}



ll find (ll r) {
  ll ans = 0;
  int end = (1<<n) - 1;
  for (int k = 1; k <= end; k++) {
    pil p = m[k];
    if (p.ff % 2 == 1 && p.ss != -1) ans += r/p.ss;
    else if (p.ss != -1) ans -= r/p.ss;
  }
  return ans;
}


int main () {
  inp(n);
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }
  
  int end = (1<<n) - 1;
  for (int k = 1; k <= end; k++) {
    pil p = numbits(k);
    m[k] = p;
  }

  int d;
  inp(d);
  for (int i = 0; i < d; i++) {
    ll l, r;
    scanf("%lli %lli", &l, &r);
    ll ans = find(r) - find(l-1);
    printf("%lli\n",ans);
  }
}