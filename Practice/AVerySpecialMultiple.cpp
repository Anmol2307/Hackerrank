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

int main () {
  int t;
  inp(t);

  while (t--) {
    llu n;
    scanf("%llu", &n);
    vector<llu> vec;
    vec.push_back(4);
    while () {

    }
  }
}