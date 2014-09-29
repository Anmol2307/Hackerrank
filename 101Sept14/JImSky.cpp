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

int main () {
  int n;
  inp(n);

  map <int, int> m;
  stack<int> stk;
  lli ans = 0;
  for (int i = 0; i < n; i++) {
    int x; inp(x);
    if (m.find(x) != m.end() && !stk.empty() && stk.top() <= x) {
      while (!stk.empty() && stk.top() < x) {
        m.erase(stk.top());
        stk.pop();
      }
      ans += (lli)m[x];
      m[x]++;
    }
    else if (m.find(x) == m.end() && !stk.empty() && stk.top() < x){
      while (!stk.empty() && stk.top() < x) {
        m.erase(stk.top());
        stk.pop();
      }
      m[x] = 1;
      stk.push(x);
    }
    else if (m.find(x) == m.end() && !stk.empty() && stk.top() > x) {
      stk.push(x);
      m[x] = 1;
    }
    else if (stk.empty()){
      stk.push(x);
      m[x] = 1;
    }
  }
  printf("%lli\n",ans*2);
}