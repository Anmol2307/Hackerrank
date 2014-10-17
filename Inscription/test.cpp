// A C++ program to find convex hull of a set of points
// Refer http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// for explanation of orientation()
#include <bits/stdc++.h>
using namespace std;
#define MOD 10000
typedef long long ll;

int n;

struct Point
{
    ll x;
    ll y;
};
 
// A globle point needed for  sorting points with reference to the first point
// Used in compare function of qsort()
Point p0;
 
// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance between p1 and p2
ll dist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

double dist2(Point p1, Point p2)
{
    return (double)(sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
// Prints convex hull of a set of n points.
double convexHull(Point points[])
{
   // Find the bottommost point
   ll ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     ll y = points[i].y;
 
     // Pick the bottom-most or chose the left most point in case of tie
     if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.  A point p1 comes
   // before p2 in sorted ouput if p2 has larger polar angle (in 
   // counterclockwise direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   // Create an empty stack and push first three points to it.
   
   stack<Point> S;
   
     S.push(points[0]);
     S.push(points[1]);
     S.push(points[2]);
    
     // Process remaining n-3 points
     for (int i = 3; i < n; i++)
     {
        // Keep removing top while the angle formed by points next-to-top, 
        // top, and points[i] makes a non-left turn
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
           S.pop();
        S.push(points[i]);
     }
   // Now stack has the output points, print contents of stack
   Point first = S.top();
   S.pop();
   double ans = 0;
   Point p = first;
   while (!S.empty())
   {
       Point q = S.top();
       ans += dist2(p,q);
       p = q;
       S.pop();
   }
   ans += dist2(p,first);
   return ans;
}
 
// Driver program to test above functions
int main()
{
    
    scanf("%d", &n);

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    Point points[n];
    scanf("%lli %lli", &points[0].x, &points[0].y);
    
    for (int i = 1; i < n; i++) {
      points[i].x = (a*(points[i-1].x)*(points[i-1].x))%MOD + (b*(points[i-1].y)*(points[i-1].y))%MOD;
      (points[i].x += ((points[i-1].x)/c + (points[i-1].y)/d)%MOD) %= MOD;
      
      points[i].y = (b*(points[i-1].x)*(points[i-1].x))%MOD + (a*(points[i-1].y)*(points[i-1].y))%MOD;
      (points[i].y += ((points[i-1].x)/d + (points[i-1].y)/c)%MOD) %= MOD;
    }
    
    // for (int i = 0; i < n; i++) {
    //   printf("%d %d\n",points[i].x,points[i].y);
    // }
    if (n == 1) printf("%.3lf\n",0.000);
    else if (n == 2) {
      double ans = dist2(points[0], points[1]);
      printf("%.3lf\n",ans); 
    }
    else printf("%.3lf\n",convexHull(points));
    return 0;
}