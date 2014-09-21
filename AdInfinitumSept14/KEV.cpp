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
#define MAX 5000005
double arr[MAX];

void pre () {
  arr[0] = 0;
  for (int i = 1; i < MAX; i++) {
    arr[i] = (double)sqrt(1+4*i) + arr[i-1];
  }
}

int main () {
  int t;
  inp(t);
  pre();

  while (t--) {
    double n;
    scanf("%lf",&n);
    n--;
    double a = n/(double)2;
    double b = arr[(int)n];

    b = b/((double)2);

    a += b;
    a = a/(double)(n+1);

    printf("%.30lf\n",a);
  }
}