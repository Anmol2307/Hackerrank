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
#define N 90
#define MOD 1000000007

ll sum[N];
int bits[N];

void pre() {
  sum[0] = 1;
  sum[1] = 2;
  for (int i = 2; i < N; i++) {
    sum[i] = sum[i-2] + sum[i-1];
  }
}

int binSearch(ll key) {
  int l = 0, m, r = N-1;

  while (r-l > 1) {
    m = l + (r-l)/2;
    if (sum[m] <= key) l = m;
    else r = m;
  }

  return l;
}

void update (ll elem) {
  while (elem != 0){
    int bs = binSearch(elem);
    bits[bs+1]++;
    elem -= sum[bs];
  }
}

ll modpow(ll a, ll b) {
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


int main () {
  int n;
  inp(n);

  ll arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%lli", &arr[i]);
  }

  pre();

  // for (int i = 0; i < N; i++) {
  //   printf("%d %lli\n",i,sum[i]);
  // }
  // exit(0);

  for (int i = 0; i < n; i++) {
    update(arr[i]);
  }

  // for (int i = 1; i < N; i++) {
  //   if (bits[i] == 1) printf("%d %d\n",i,bits[i]);
  // }
  
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    if (bits[i]%2 == 1) {
      (ans += modpow(2,i-1)) %= MOD;
    }
  }
  printf("%lli\n",ans);
}