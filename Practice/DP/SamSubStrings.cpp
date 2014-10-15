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
#define MOD 1000000007

int main () {
  string str;
  cin >> str;

  int sz = str.size();
  lli sum = str[0] - '0';
  lli val = str[0] - '0';
  for (int i = 1; i < sz; i++) {
    val = ((i+1)*(str[i] - '0')+ 10*val)%MOD;
    (sum += val) %= MOD;
  }
  printf("%lli\n",sum);
}