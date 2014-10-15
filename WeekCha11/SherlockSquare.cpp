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
#define MOD 1000000007
typedef long long int llu;

llu modpow(llu base, llu exp) {
  base %= MOD;
  llu result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    llu n;
    scanf("%llu",&n);
    if (n == 0) {
      printf("4\n");
      continue;
    }
    
    llu pro = modpow(2ll,n+1);
    pro += 2;
    printf("%lli\n",pro);
  }
}