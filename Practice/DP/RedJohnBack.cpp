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

typedef long long int lli;
#define N 217300

int dp[45];
int numPrime[45];
int prime[N];
vector <int> primes;

void find () {
  for (int i = 2; i < N; i++) {
    if (prime[i] == 0) {
      primes.push_back(i);
      for (int j = 2*i; j < N; j+=i) {
        prime[j] = 1;
      }
    }
  }

  // for (int i = 0; i < 100; i++) {
  //   printf("%d ",primes[i]);
  // }
  // printf("\n");
  // exit(0);
}

void pre () {
  dp[1] = 1;
  dp[0] = 1;
  for (int i = 2; i <= 40; i++) {
    dp[i] = dp[i-1];
    if (i >= 4) dp[i] += dp[i-4];
  }
  numPrime[0] = 0;
  numPrime[1] = 0;
  int j = 0;
  int sz = primes.size();
  for (int i = 2; i <= 40; i++) {
    int val = dp[i];
    while (j < sz && primes[j] <= val) {
      j++;
    }
    numPrime[i] = j;
  }
}


int main () {
  int t;
  inp(t);

  find();
  pre();

  while (t--) {
    int n;
    inp(n);
    printf("%d\n",numPrime[n]);
  }
}