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
#define MAX 1000005

pair<int,int> pdivisiors[MAX];

bool isEvenPerfect (int num) {
  int x = sqrt(num);
  if (x*x == num && num%2 == 0) return true;
  else return false;
}

void pre () {
  for (int i = 2; i < MAX; i++) {
    bool flag = isEvenPerfect(i);
    for (int j = 2*i; j < MAX; j += i) {
      pdivisiors[j].first++;
      if (flag) pdivisiors[j].second++;
    }
  }
}

int gcd (int a, int b) {
  if (a > b) swap(a,b);
  int tmp;
  while (a != 0) {
    tmp = b;
    b = a;
    a = tmp%a;
  }
  return b;
}


void printDivisors () {
  // for (int i = 2; i <= 50; i++) {
  //   printf("The number of proper divisors of %d is %d\n",i,pdivisiors[i] + 1);
  // }
  // for (int i = 1; i <= 100; i++) {
  //   printf("The number %d is %d\n",i,isPerfect(i));
  // }
  // printf("Gcd %d\n",gcd(18,12));
}

int main () {
  int t;
  inp(t);

  pre();
  while (t--) {
    int n;
    inp(n);

    if (pdivisiors[n].second == 0) printf("0\n");
    else {
      int g = gcd(pdivisiors[n].first+1,pdivisiors[n].second);
      int num = pdivisiors[n].second/g;
      int den = (pdivisiors[n].first+1)/g;
      printf("%d/%d\n",num,den);
    }
  }
}