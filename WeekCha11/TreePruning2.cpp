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

#define maxn 100111

vector <int> adj[maxn];
int n, k, weight[maxn], cnt[maxn], dfs_order[maxn];
long long f[maxn], sum[maxn];
int count;


void dfs(int u) {
    dfs_order[++count] = u;
    cnt[u] = 1;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];
        if (cnt[v]) continue;
        dfs(v);
        cnt[u] += cnt[v];
    }
}

int main() {
    int n, k;
    inp(n); inp(k);

    for (int i = 1; i <= n; i++) {
      inp(weight[i]);
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        inp(u); inp(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset (cnt, 0, sizeof(cnt));
    dfs(1);

    for (int i = 1; i <= n; i++)
        sum[i] = weight[dfs_order[i]] + sum[i - 1];

    for (int i = 1; i <= n; i++) f[i] = sum[i];
  
    
    for (int rep = 1; rep <= k; rep ++) {
        for (int i = n; i >= 1; i--) {
            int pos = i + cnt[dfs_order[i]] - 1;
            f[pos] = max(f[pos], f[i - 1]);
        }

        for (int i = 1; i <= n; i++)
            f[i] = max(f[i], f[i - 1] + weight[dfs_order[i]]);
    }

    cout << f[n] << endl;
    return 0;
}