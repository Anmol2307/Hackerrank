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

typedef unsigned long long llu;

vector <llu> vec;  

int binSearch(llu val){
  int start=0,end=vec.size()-1;
  int last = vec.size()-1;

  while(start<=end){
    int mid= (start+end)/2;
    
    if (vec[mid] <= val && (mid==last || vec[mid+1] > val)) return mid;
    
    else if(vec[mid] <= val) start=mid+1;
    
    else end=mid-1;
  }
}


int main () {
  llu MAX = pow(10,16);
  llu ans = 0;
  llu i = 1;
  ans = (i*(i+1)*(2*i + 1))/6; 
  while (ans < MAX) {
    vec.push_back(ans);
    i++;
    ans = (i*(i+1)*(2*i + 1))/6;
  }

  int t;
  inp(t);

  while (t--) {
    llu n;
    scanf("%llu",&n);
    int ans = binSearch(n);
    printf("%d\n",ans+1);
  }
}