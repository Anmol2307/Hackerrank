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
#define MAX 30000
#define eps 1e-3
double xc, yc, r;
    
bool check (double x1, double y1, double x2, double y2) {
  double c1x = xc - x1;
  double c1y = yc - y1;
  double e1x = x2 - x1;
  double e1y = y2 - y1;

  double k = c1x*e1x + c1y*e1y;

  if (k > 0){
    double len = sqrt(e1x*e1x + e1y*e1y);
    k = (double)((double)k/(double)len);

    if (k < len){
      if (abs(c1x*c1x + c1y*c1y - k*k - r*r) <= eps){
        return true;
      }
    }
  }
  return false;
}

bool check2 (double x1, double y1, double x2, double y2) {
  
  // v = P1 - P0
  // w = P - P0

  double e1x = x2 - x1;
  double e1y = y2 - y1;

  double c1x = xc - x1;
  double c1y = yc - y1;

  
  double c1 = c1x*e1x + c1y*e1y;
  double c2 = e1x*e1x + e1y*e1y;

  if ( c1 <= 0 ) {
    // return false;
    if ((x1-xc)*(x1-xc) + (y1-yc)*(y1-yc) - r*r <= 0) return true;
    else return false;
    // return d(P, P0)
  }
  if ( c2 <= c1 ) {
    // return false;
    if ((x2-xc)*(x2-xc) + (y2-yc)*(y2-yc) - r*r <= 0) return true;
    else return false;
    // return d(P, P1)
  }

  double b = c1 / c2;
  
  e1x = x1 + b*e1x;
  e1y = y1 + b*e1y;
  
  if ((e1x-xc)*(e1x-xc) + (e1y-yc)*(e1y-yc) - r*r <= 0) return true;
  else return false;
  // return true;
  // return d(P, Pb)
}

int main () {
  int t;
  inp(t);
  int i = 1;
  while (t--) {
    scanf("%lf %lf %lf",&xc,&yc,&r);
    double x1,y1,x2,y2,x3,y3;
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    scanf("%lf %lf",&x3,&y3);
    double one = (x1-xc)*(x1-xc) + (y1-yc)*(y1-yc) - r*r;
    double two = (x2-xc)*(x2-xc) + (y2-yc)*(y2-yc) - r*r;
    double three = (x3-xc)*(x3-xc) + (y3-yc)*(y3-yc) - r*r;
    // printf("%lf %lf %lf\n",one,two,three);
    double mi = min(one,min(two,three));
    double ma = max(one,max(two,three));
    // printf("%lf %lf\n",mi,ma);
    if (mi <= 0 && ma >= 0) {
      // printf("Yahan par hoon %d\n", i);
      printf("YES\n"); 
      // i++;
    }
    else {
      // Check if line is tangent to a circle
      // Distance of point from line
      // printf("Came Here bitch! %d %lf %lf\n",i,mi,ma);
      bool one = check2(x1,y1,x2,y2);
      bool two = check2(x2,y2,x3,y3);
      bool three = check2(x3,y3,x1,y1);

      if (ma < 0) printf("NO\n");
      else if (mi > 0 && (one || two || three)) printf("YES\n");
      else printf("NO\n");     
      // i++;
    }
  }
}