#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {
  int t;
  scanf("%d",&t);

  while (t--) {
    unsigned long long n;
    scanf("%llu",&n);
    n *=2; 
    unsigned long long i = sqrt(n);
    // while (i*(i + 1) < n) {
    //   i++;
    // }
    if (i*(i + 1) == n) printf("Go On Bob %llu\n",i);
    else printf("Better Luck Next Time\n");
  }
}
