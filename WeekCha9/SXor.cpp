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
	int t;
	inp(t);

	while (t--) {
		long long int n;
		scanf("%lli\n",&n);
		int arr[n+1];

		for (int i = 1; i <= n; i++) {
			inp(arr[i]);
		}

		long long int ans = 0;
		for (long long int i = 1; i <= n ; i++) {
			long long int pro = i*(n-i+1);
			if (pro%2 != 0) ans ^= arr[i];
		}

		printf("%lli\n",ans);
	}
}