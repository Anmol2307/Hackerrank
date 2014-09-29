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

typedef pair<int,int> pii;
typedef long long int lli;
typedef vector<int> vi;
#define inf (1<<30)

int main () {
  int n, t;
  inp(n); inp(t);
  vi vec;

  for (int i = 0; i < n; i++) {
    int x; inp(x);
    vec.push_back(x);
  }

  int dp[105][105];
  int cost[105][105];

  

  int low = 0, high = inf;

  while (low < high) {
    int mid = (low+high)/2;
    for (int i = 0; i < n; i++) {
      dp[i][i] = 0;
      cost[i][i] = vec[i];
    }
    for (int l = 2; l <= n; l++) {
      for (int i = 0; i < n-l+1; i++) {
        int j = i+l-1;
        dp[i][j] = inf;
        cost[i][j] = vec[i] + cost[i+1][j];
        for (int k = i; k < j; k++) {
          int c = cost[i][k]*(k-i+1) + cost[k+1][j]*(j-k);
          if (c >= mid) {
            c -= mid;
          }
          else c = 0;
          c += dp[i][k] + dp[k+1][j];
          dp[i][j] = min(dp[i][j],c);
        }
      }
    }
    if (dp[0][n-1] <= t) high = mid;
    else low = mid+1;
  }
  printf("%d\n",low);
}