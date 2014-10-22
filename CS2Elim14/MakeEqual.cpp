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


int main () {
  ll n, k;
  scanf("%lli %lli", &n, &k);

  int arr[n];
  int ma = -1;
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
    if (arr[i] > ma) ma = arr[i];
  }

  ll tot = 0, pres = 0;
  int last = arr[0];
  for(int i=0;i<n;i++){
        if(pres>= ma-arr[i]){
            pres = ma-arr[i];
        }
        else{
            tot += ma-arr[i]-pres;
            pres = ma-arr[i];
        }
    }

  if (tot > k) {
    printf("0\n");
  }
  else {
    printf("%lli\n",k-tot+1);
  }
}