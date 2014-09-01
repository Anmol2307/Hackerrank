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

#define max 1000005

char mat[4][4];
  
void pre () {
  mat[0][0] = 'A'; mat[0][1] = 'B'; mat[0][2] = 'C'; mat[0][3] = 'D';
  mat[1][0] = 'B'; mat[1][1] = 'A'; mat[1][2] = 'D'; mat[1][3] = 'C';
  mat[2][0] = 'C'; mat[2][1] = 'D'; mat[2][2] = 'A'; mat[2][3] = 'B';
  mat[3][0] = 'D'; mat[3][1] = 'C'; mat[3][2] = 'B'; mat[3][3] = 'A';
}

int main () {
  pre();
  int n, k;
  inp(n); inp(k);
  char ch[max];
  scanf("%s",ch);
  int len = strlen(ch);

  for (int i = 0; i < k; i++) {
    char first = ch[0];
    for (int j = 0; j < n-1; j++) {
      ch[j] = mat[ch[j]-'A'][ch[j+1] - 'A'];
    }
    ch[n-1] = mat[ch[n-1]-'A'][first-'A'];
    printf("%s\n",ch);
  }
  // printf("%s\n",ch);
}