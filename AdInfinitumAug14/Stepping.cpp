#include <iostream>
#include <cstdio>
using namespace std;

int main () {
  int t;
  scanf("%d",&t);

  while (t--) {
    long long int n;
    scanf("%lli",&n);
    long long int i = 1;
    n *=2; 
    while (i*(i + 1) < n) {
      i++;
    }
    if (i*(i + 1) == n) printf("Go On Bob %lli\n",i);
    else printf("Better Luck Next Time\n");
  }
}
