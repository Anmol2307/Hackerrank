#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;


inline void inp(int &n ) {//fast input function
  n=0;
  int ch=getchar_unlocked(),sign=1;
  while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
  while( ch >= '0' && ch <= '9' )
    n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
  n=n*sign;
}

int n,k,A[301][301],vis[301],a,b;
vector<int> g[301];
int B[301];

void dfs(int i,int j,int val) {
  A[i][j]=val;
  vis[j]=i;
  // cout<<j<<" "<<A[i][j]<<endl;

  for(int k=0;k<g[j].size();k++)
    if(vis[g[j][k]]!=i)
      dfs(i,g[j][k],val+1);

}

int main() {
  inp(n);
  inp(k);
  memset(A,0,sizeof A);

  for(int i=1;i<n;i++) {
    inp(a);
    inp(b);
    g[a].push_back(b);
    g[b].push_back(a);
  }

  memset(vis,-1,sizeof vis);
  for(int i=1;i<=n;i++) {
    // cout<<i<<" :\n";
    dfs(i,i,0);
  }

  int ans=0;

  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      ans=max(ans,A[i][j]);

  while(k--) {
    int idx=1,val=0;
    memset(B,0,sizeof B);
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=n;j++) {
        if(A[i][j]==ans)
          B[i]++;
      }
      if(B[i]>val) {
        val=B[i];
        idx=i;
      }
    }

    for(int i=1;i<=n;i++) {
      A[i][idx]=0;
      A[idx][i]=0;
    }

    ans=0;
    for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
        ans=max(ans,A[i][j]);
  }
  printf("%d\n", ans);
  return 0;
}