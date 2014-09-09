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


int main () {
  int t;
  inp(t);

  char ch[100005];
  while (t--) {
    scanf("%s",ch);
    int len = strlen(ch);
    int ans = 0;
    for (int i = 1; i < len; i++) {
      if (ch[i] == ch[i-1]) ans++;
    }
    printf("%d\n",ans);
  }
}