#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main () {

  int t;
  scanf("%d",&t);

  while (t--) {
    int x1, y1, x2, y2, xm, ym;
    scanf("%d %d %d %d %d %d",&x1, &y1, &x2, &y2, &xm, &ym);
    
    double slope_mirror, val1, val2;
    if (xm != 0) {
      slope_mirror = ym/xm;
      val1 = y1 - slope_mirror*x1;
      val2 = y2 - slope_mirror*x2;
    }
    else {
      val1 = x1;
      val2 = x2;
    }
    double slope_wall, valm, origin;
    if ((x2 - x1) != 0) {
      slope_wall = (y2-y1)/(x2-x1);
      valm = ym - slope_wall*xm - y1 + x1*slope_wall;
      origin = - y1 + x1*slope_wall;
    }
    else {
      valm = xm + x1;
      origin = x1;
    }
    
    double pro1 = valm*origin;
    double pro2 = val1*val2;
    // printf("%lf %lf %lf\n",valm,origin,pro1);
    if (pro1 < 0 && pro2 < 0) {
      printf("NO\n");
    }
    // else if ((val1 == 0 && val2 != 0) || (val1 != 0 && val2 == 0)) {
    //     printf("NO\n"); 
    // }
    else if (val1 == 0 ) {
      double point1_origin = sqrt(y1*y1 + x1*x1);
      double origin_mirror = sqrt(ym*ym + xm*xm);
      double point1_mirror = sqrt((ym-y1)*(ym-y1) + (xm-x1)*(xm-x1));
      if (point1_origin > origin_mirror || point1_mirror > origin_mirror) {
        printf("YES\n");
      }
      else printf("NO\n");
    }
    else if (val2 == 0) {
      double point1_origin = sqrt(y2*y2 + x2*x2);
      double origin_mirror = sqrt(ym*ym + xm*xm);
      double point1_mirror = sqrt((ym-y2)*(ym-y2) + (xm-x2)*(xm-x2));
      if (point1_origin > origin_mirror || point1_mirror > origin_mirror) {
        printf("YES\n");
      }
      else printf("NO\n");
    }
    else {
      printf("YES\n");
    }
  }
}