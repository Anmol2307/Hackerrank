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
  // string ch;
  scanf("%s",ch);
  // cin >> ch;
  // int len = strlen(ch);
  string str(ch);
  int len = str.size();
  map <string,int> mymap;
  char first = str[0];
  for (int j = 0; j < len-1; j++) {
    str[j] = mat[str[j]-'A'][str[j+1] - 'A'];
  }
  str[len-1] = mat[str[len-1]-'A'][first-'A'];
  int val = 1, pivot = val;
    
  while (1) {
    mymap.insert(pair<string,int>(str,val));
    first = str[0];
    for (int j = 0; j < len-1; j++) {
      str[j] = mat[str[j]-'A'][str[j+1] - 'A'];
    }
    str[len-1] = mat[str[len-1]-'A'][first-'A'];
    val++;
    if (mymap.find(str) != mymap.end()) {
      pivot = mymap.find(str)->second;
      break;
    }
  }
  val--;
  if (k > val && (k - pivot + 1)%(val - pivot + 1) == 0) k = val;
  else if (k > val) k = (k-pivot+1)%(val-pivot+1) + pivot -1 ;
      
  map<string,int>::iterator it;
  for (it = mymap.begin(); it != mymap.end(); ++it )
    if (it->second == k)
      printf("%s\n",it->first.c_str());
}
