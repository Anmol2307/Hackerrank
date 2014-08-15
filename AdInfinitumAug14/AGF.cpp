#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int m;

int modpow(unsigned long long base, unsigned long long exp) {
  base %= m;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % m;
    base = (base * base) % m;
    exp >>= 1;
  }
  return result;
}


int find(unsigned long long n) {
  if (n==1) return 1;

  if (n%2 == 0) {
    unsigned long long val = find(n/2);
    unsigned long long power = modpow(10,n/2);
    return (val*((1+ power)%m))%m;
  }
  else {
    unsigned long long val = find(n-1);
    return (1 + ((10%m)*val)%m)%m;
  }
}

int main () {
  int t;
  scanf("%d",&t);

  while (t--) {
    unsigned long long n;
    scanf("%llu %d",&n,&m);
    int val = find(n);
    printf("%d\n",val); 
  }
}