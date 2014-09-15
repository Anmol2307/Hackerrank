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

#define MAX 500005
typedef long long int lli;
int N;
lli dp[MAX];
lli V[MAX];
lli P[MAX];
lli sum[MAX];
  
lli find (int index) {
  if (dp[index] != -1) {
    // printf("One %d %lli\n",index,dp[index]);
    return dp[index];
  }
  
  if (P[index] >= (N-index-1)) {
    // lli val = sum[N-1] - sum[index];
    // for (int i = index+1; i < N; i++) {
    //   val += V[i];
    // }
    dp[index] = sum[N-1] - sum[index];
    // printf("Two %d %lli\n",index,dp[index]);
    return dp[index];
  }

  int end = index + P[index];
  lli ans = -1;
  for (int i = index+1; i <= end; i++) {
    // for (int j = index+1; j < i; j++){
    //   val += V[j];
    // }
    lli val = sum[i-1] - sum[index];
    ans = max(ans,val + find(i));
  }
  dp[index] = ans;
  // printf("Three %d %lli\n",index,dp[index]); 
  return ans;
}

int main () {
  inp(N);
  memset(dp,-1,sizeof(dp));
    
  for (int i = 0; i < N; i++) {
    scanf("%lli %lli\n",&V[i],&P[i]);
  }

  sum[0] = V[0];
  for (int i = 1; i < N; i++) {
    sum[i] = sum[i-1] + V[i];
  }

  lli ans = find(0);
  printf("%lli\n",ans);
}