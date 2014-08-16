#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>
#include <climits>

using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 100003
#define mm 10000000
#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


typedef long long int LL;

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}

int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main () {
  int n;
  inp(n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }
  int q;
  inp(q);

  for (int i = 0; i < q; i++) {
    int x;
    inp(x);

    int a1[n];
    memset(a1,0,sizeof(a1));
    a1[0] = 1;
    a1[1] = arr[n-1];
    int b1[n];
    b1[0] = 1;
    for (int j = n-2; j >= 0; j--) {
      // printf("Iteration %d\n",j);
      for (int i = 1; i < n; i++) {
        b1[i] = (a1[i]%mod + ((long long int)(arr[j]*a1[i-1]))%mod)%mod;
        // printf("HERE %d %d %d\n",a1[i],arr[n-i],a1[i-1]);
        // printf("%d\n",b1[i]);
      }
      for (int i = 1; i < n; i++) {
        a1[i] = b1[i];
      }
    }
    printf("%d\n",a1[x]);
  }

}