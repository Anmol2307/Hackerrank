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
typedef pair<double, double> pdd;
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

bool myComp(const pdd& f, const pdd& s) {
  if (f.first*f.second <= s.first*s.second) return true;
  else return false;
}

int main () {
  int n;
  inp(n);
  pdd arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%lf %lf",&arr[i].first,&arr[i].second);
  }

  sort(arr,arr+n,myComp);
  double ans = 0;
  double sum = 0;
  double pro = 1;
  for (int i = 0; i < n; i++) {
    sum += arr[i].first;
    ans += sum*pro*(1-arr[i].second);
    pro *= arr[i].second;
  }
  ans += sum*pro;
  printf("%lf\n",ans);
}