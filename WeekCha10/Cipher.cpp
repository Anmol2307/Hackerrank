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
    int n, k;
    inp(n); inp(k);

    // char ch[n+k-1];
    // scanf("%s",ch);
    string ch;
    cin >> ch;

    // char ans[n];
    string ans = "";

    // ans[0] = ch[0];
    ans.push_back(ch[0]);

    int val = (ch[0] - '0');
    int xval = (ch[0] - '0');
    int sz = min(n,k);
    for (int i = 1; i < sz; i++) {
      val = xval^(ch[i] - '0');
      // ans[i] = (char)(val + 48);
      ans.push_back((char)(val + 48));
      xval ^= (ans[i] - '0'); 
      // printf("%d %c\n",i,ans[i]);
    }

    for (int i = sz; i < n; i++) {
      xval ^= (ans[i-k] - '0');
      val = xval^(ch[i]  - '0');
      // ans[i] = (char)(val + 48);
      ans.push_back((char)(val + 48));
      xval ^= (ans[i]  - '0');
      // printf("%d %c\n",i,ans[i]);
    }

    printf("%s\n",ans.c_str());
  }