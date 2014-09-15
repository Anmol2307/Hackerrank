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

map<char,int> m;    

int find (char x, int n) {
  map<char,int>::iterator it;

  for (it = m.begin(); it != m.end(); it++) {
    if (it->first > x && it->second > n) {
      return it->second;
    }
  }
  return -1;
}


int main () {
  int t;
  inp(t);

  while (t--) {
    m.clear();
    char ch[105];
    scanf("%s\n",ch);
    int len = strlen(ch);

    for (int i = 0; i < len; i++) {
      if (m.find(ch[i]) == m.end()) m.insert(pair<char,int>(ch[i],i));
      else {
        int val = m[ch[i]];
        val = max(val,i);
        m[ch[i]] = val;
      }
    }

    int mi = 0;
    int mind = 0;
    int index;
    bool flag = false;
    for (int i = 0; i < len - 1; i++) {
      index = find(ch[i], i);
      if (index != -1) {
        mi = i;
        mind = index;
        flag = true;
      }
    }
    
    char x = ch[mi];
    ch[mi] = ch[mind];
    ch[mind] = x;
    sort(ch+mi+1, ch+len);
        
    if (flag) printf("%s\n",ch);
    else printf("no answer\n");
  }
}