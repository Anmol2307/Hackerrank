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
#define N 100005

lli arr[N];
lli dp[N];
lli sum[N];

int main () {
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    memset(dp,0,sizeof(dp));
    for (int i = n-1; i >= 0; i--) {
      scanf("%lli", &arr[i]);
    }

    sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
      sum[i] = sum[i-1] + arr[i];
    }

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = arr[0] + arr[1] + arr[2];
    for (int i = 3; i < n; i++) {
      dp[i] = max(arr[i] + sum[i-1] - dp[i-1], max(arr[i-1] + arr[i] + sum[i-2] - dp[i-2],arr[i-2] + arr[i-1] + arr[i] + sum[i-3] - dp[i-3]));
    }
    printf("%lli\n",dp[n-1]);
  }
}