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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 1005


int main () {
  int t;
  inp(t);

  while (t--) {
    int n, q;
    inp(n); inp(q);

    pii arr[26];

    for (int i = 0; i < 26; i++) {
      arr[i].ff = i/n;
      arr[i].ss = i%n;
    }

    vector <string> vec;

    for (int i = 0; i < q; i++) {
      string str;
      cin >> str;
      vec.push_back(str);
    }

    for (int i = 0; i < q; i++) {
      int s = vec[i].sz;
      int ans = arr[vec[i][0]-'a'].ff + arr[vec[i][0]-'a'].ss;
      for (int j = 1; j < s; j++) {
        ans += abs(arr[vec[i][j]-'a'].ff - arr[vec[i][j-1]-'a'].ff);
        ans += abs(arr[vec[i][j]-'a'].ss - arr[vec[i][j-1]-'a'].ss);
      }

      printf("%d\n",ans);
    }
  }
}