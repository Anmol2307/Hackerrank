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

typedef unsigned long long llu;

llu modpow(llu base, llu exp, llu modulus) {
  base %= modulus;
  llu result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}


int main () {
  int t;
  inp(t);

  while (t--) {
    llu sum = 0;
    llu k, n;
    scanf("%llu %llu",&k,&n);
    for (int i = 1; i <= k; i++) {
      sum = (sum + modpow(i,n,100))%100;
    }
    if (sum < 10) printf("0%llu\n",sum);
    else printf("%llu\n",sum);
  }
}