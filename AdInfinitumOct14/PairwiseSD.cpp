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



int main () {
  int t;
  inp(t);

  while (t--) {
    ll n;
    scanf("%lli", &n);

    int arr[n];
    ll cnt1 = 0;
    ll cnt2 = 0;
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
      if (arr[i] == 1) cnt1++;
      else if (arr[i] == 2) cnt2++;
    }

    if (cnt1 == 0) {
      ll ans = cnt2*(cnt2-1);
      ans /= 2;
      printf("%lli\n",ans);
    }
    else {
      ll ans = cnt1*(cnt1-1);
      ans += cnt1*(n-cnt1);
      ans += (cnt2*(cnt2-1))/2;
      printf("%lli\n",ans);
    }
  }
}