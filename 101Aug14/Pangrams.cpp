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

  string ch;
  getline(cin,ch);

  int len = ch.size();

  int arr[26];
  memset(arr,0,sizeof(arr));
  int total = 0;

  for (int i = 0; i < len; i++) {
    if (ch[i] - 'a' >= 0 && ch[i] - 'a' <= 25 && arr[ch[i] - 'a'] == 0) {
      arr[ch[i] - 'a'] = 1;
      total++;
    }
    else if  (ch[i] - 'A' >= 0 && ch[i] - 'A' <= 25 && arr[ch[i] - 'A'] == 0) {
      arr[ch[i] - 'A'] = 1;
      total++;
    }
  }

  if (total == 26) {
    printf("pangram\n");
  }
  else printf("not pangram\n");
}