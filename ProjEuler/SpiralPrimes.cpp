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
#define N 20000

int prime[N];

void sieve () {
  for (int i = 2; i < N; i++) {
    if (prime[i] == 0) {
      for (int j = i*i; j < N; j+=i) {
        prime[j] = 1;
      }
    }
  }
}

bool isPrime (int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (num%i == 0) return false;
  }
  return true;
}

int main () {
  double n;
  cin >> n;
  n /= 100;
  //sieve();
  int last = 0;
  int cur = 0;
  for (int i = 3; ; i+=2) {
    int val1 = (i-2)*(i-2) + (i-1);
    int val2 = (i-1)*(i-1) + 1;
    int val3 = i*i - (i-1);
    int cnt = 0;
    if (isPrime(val1)) {
      cnt++;
    }
    if (isPrime(val2)) {
      cnt++;
    }
    if (isPrime(val3)) {
      cnt++;
    }
    cur = last + cnt;
    double val = double(cur)/double(2*i-1);
    if (val < n) {
      printf("%d\n",i);
      break;
    }
    else {
      last = cur;
    }
  }
}