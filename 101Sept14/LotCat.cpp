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

double find (int n , int m) {
  lli sum = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      sum += n-1;
      if (abs(i-j) <= 1) continue;
      else if (i < j) {
        sum += max(0,m-(i+n-1));
      }
      else sum += max (0,i-n);
    }
  }
  return double(sum)/(m*m);
}

int main () {
  int n, m;
  inp(n); inp(m);
  printf("%.10lf\n",find(n,m));
}