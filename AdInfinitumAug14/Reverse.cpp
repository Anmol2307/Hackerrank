#include <iostream>

using namespace std;

int main () {
    
    int t;
    scanf("%d",&t);
    
    while (t--) {
        int n,k;
        scanf("%d %d",&n,&k);
        n--;
        if (k >= n/2) {
            int diff = n- k;
            printf("%d\n",diff*2);
        }
        else {
            printf("%d\n",2*k+1);
        }
    }
}