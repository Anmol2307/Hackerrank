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
  string str(ch);
  int len = str.size();

  int ans = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'A') ans ^= 0;
    else if (str[i] == 'B') ans ^= 1;
    else if (str[i] == 'C') ans ^= 2;
    else if (str[i] == 'D') ans ^= 3;   
  }

  k++;
  int val = k%n;
  int fin = 0;
  for (int i = 0; i < val; i++) {
    if (str[i] == 'A') fin ^= 0;
    if (str[i] == 'B') fin ^= 1;
    if (str[i] == 'C') fin ^= 2;
    if (str[i] == 'D') fin ^= 3;
  }

  if ((k/n)%2 != 0) fin ^= ans;

  if (fin == 0) printf("%c",'A');
  else if (fin == 1) printf("%c",'B');
  else if (fin == 2) printf("%c",'C');
  else if (fin == 3) printf("%c",'D');
  
  int newval = val;

  for (int i = 1; i < len; i++) {
    if (str[i-1] == 'A') fin ^= 0;
    else if (str[i-1] == 'B') fin ^= 1;
    else if (str[i-1] == 'C') fin ^= 2;
    else if (str[i-1] == 'D') fin ^= 3;
    
    if (str[val] == 'A') fin ^= 0;
    else if (str[val] == 'B') fin ^= 1;
    else if (str[val] == 'C') fin ^= 2;
    else if (str[val] == 'D') fin ^= 3;
    
    val = (val + 1)%n;
    
    if (fin == 0) printf("%c",'A');
    else if (fin == 1) printf("%c",'B');
    else if (fin == 2) printf("%c",'C');
    else if (fin == 3) printf("%c",'D');
  
  }

  // for (int i = 0; i < len; i++) {
  //   printf("%d",finstr[i]);
  // }
  printf("\n");

}
