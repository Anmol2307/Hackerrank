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


  int main () {

    int n;
    inp(n);

    vector <pii> vec;
    for (int i = 0; i < n; i++) {
      int t, d;
      inp(t); inp(d);
      vec.push_back(pii(t+d,i));
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
      printf("%d ",vec[i].second + 1);
    }
    printf("\n");
  }