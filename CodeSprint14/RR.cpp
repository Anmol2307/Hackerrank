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

int main () {
  int t;
  inp(t);

  while (t--) {
    lli x, y, x1, y1, x2, y2;
    scanf("%lli %lli %lli %lli %lli %lli\n",&x,&y,&x1,&y1,&x2,&y2);
    lli one = x - x1;
    lli two = x2 - x;
    lli three = y - y1;
    lli four = y2 - y;
    lli ans = min(min(one,two),min(three,four));
    printf("%lli\n",ans);
  }
}