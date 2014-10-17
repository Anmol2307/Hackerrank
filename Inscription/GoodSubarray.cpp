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
#define mx 1005

int gcd (int a, int b) {
  if (b == 0) return a;
  return gcd(b,a%b);
}


int main () {
  
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    int arr[n];
    int dp[n];
    
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
    }

    memset(dp,-1,sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      bool flag = false;
      for (int j = i-1; j >= 0; j--) {
        int val = gcd(arr[i],arr[j]);
        if (val == 1) {
          flag = true;
          break;
        }
      }
    }
    int ma = -1;

    for (int i = 0; i < n; i++) {
      printf("%d ",dp[i]);
    }
    printf("\n");
    exit(0);
    for (int i = 0; i < n; i++) {
      if (dp[i] > ma) {
        ma = dp[i];
      }
    }

    printf("%d\n",ma);

  }  
}
