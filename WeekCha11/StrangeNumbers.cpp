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

#define MOD 1000000007
typedef long long int llu;

vector<vector<llu> > vec(20);
vector <int> s(20);

int findlen (llu num) {
  if (num < 0) {
   return -1;
  }
  else if (num == 0) return 1;
  int ans = 0;
  while (num != 0) {
    ans++;
    num /= 10;
  }
  return ans;
}

void pre () {
  
  for (int i = 1;  i < 10; i++) {
    vec[1].push_back(i);
  }

  for (int i = 1; i < 19; i++) {
    for (int j = 0; j < vec[i].size(); j++) {
      for (int k = 2; k < 19; k++) {
        if (findlen(vec[i][j]*((llu)k))  == k) {
          if (vec[i][j]*((llu)k) == 112422203527233536) {
            printf("I cam here with %llu %d\n",vec[i][j], k);
          }
          vec[k].push_back(vec[i][j]*((llu)k));
        }
      }
    }
  }
  vec[1].insert(vec[1].begin(),0);
  for (int i = 1; i < 19; i++) {
    sort(vec[i].begin(), vec[i].end());
  }

  s[0] = 0;
  for (int i = 1; i < 19; i++) {
    s[i] = s[i-1] + vec[i].size();
  }
}

int main () {
  int t;
  inp(t);

  pre();

  // for (int i = 1; i < 20; i++) {
  //   for (int j = 0; j < vec[i].size(); j++) {
  //     printf("%llu ",vec[i][j]);
  //   }
  //   printf("\n\n");
  // }
  // exit(0);

  // for (int i = 1; i < 20; i++) {
  //   printf("%d %lu\n",i,vec[i].size());
  // }

  // for (int i = 1; i < 20; i++) {
  //   printf("%d %d\n",i,s[i]);
  // }



  while (t--) {
    llu l, r;
    scanf("%llu %llu", &l, &r);

    int sl = findlen(l);
    int sr = findlen(r);
    // printf("sz %d\n",sr);
    // printf("sz %d\n",sl);

    vector <llu>::iterator lo;
    int x = 0, y = 0, i = 0;
    while (i < vec[sl].size() && vec[sl][i] <= l) {
      x++;i++;
    }
    // printf("I came mere %d\n",x);
    if (i > 0 && vec[sl][i-1] == l) {
      // printf("I came mere %d\n",x);
      x--;
    }
    i = 0;
    while (i < vec[sr].size() && vec[sr][i] <= r) {
      y++;i++;
    }
    
    int ans = y + s[sr-1];
    // printf("HERE %d %d\n",ans,x);
    ans -= x + s[sl-1];
    printf("%d\n",ans);
  }
}