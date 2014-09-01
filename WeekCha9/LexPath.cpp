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


llu mat[11][11];
llu fact[21];

void factorial() {
	fact[0] = 1;
	fact[1] = 1;
	for (llu i = 2; i <= 20; i++) {
		fact[i] = fact[i-1]*i;
	}
}


void pre () {
	factorial();
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			if (i== 0 || j == 0) mat[i][j] = 1;
			else mat[i][j] = fact[i+j]/(fact[i]*fact[j]);
		}
	}
}

int main () {
	int t;
	inp(t);

	pre();
	while (t--) {
		int n, m, k;
		inp(n); inp(m); inp(k);
		int len = n+m;
		char ch[n+m];
		int i =0;
		while (n != 0 && m != 0) {
			if (k <  mat[n-1][m]) {
				ch[i] = 'H';
				n--;	
			}
			else {
				ch[i] = 'V';
				k -= mat[n-1][m];
				m--;
			}
			i++;
		}
		while (n != 0) {
			ch[i] = 'H';
			i++; n--;
		}
		while (m != 0) {
			ch[i] = 'V';
			i++; m--;
		}
		for (int i = 0; i < len; i++) {
			printf("%c",ch[i]);
		}
		printf("\n");
	}
}