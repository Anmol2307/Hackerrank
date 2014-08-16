#include <iostream>
#include <stdio.h>
using namespace std;

#define THRESHOLD 70
#define INFI 1000

long long A[200001];



long long gcd(long long x, long long y){
    
    if(y>x) return gcd(y,x);
    if(y==0) return x;
    return gcd(y, x%y);
}


long long greaterHelper(int L, int R){
    
    if(L>R) return 1;
    
    long long ret = greaterHelper(L+1, R);
    long long a = A[L];

    if(ret == 0){
        return 1;
    }
    
    if(ret > 7 ||  a > THRESHOLD)
        return INFI;
    
    for(int i=1;i<ret;i++){
        a = a * A[L];
        if(a > THRESHOLD)
            return INFI;
    }
    return a;
}

bool mygreater(int L, int R, int K){  //K<60
    
    int nsteps = 20;
    int Rprime = min(L+nsteps, R);
    for(int i=Rprime; i>=L; i--){
        if(A[i]==0 || A[i]==1) Rprime = i;
    }
    long long ans = greaterHelper(L, Rprime);    
    if(ans > K)
        return true;
    else 
        return false;
}

void funct(long long x, int L, int R, int K, long long a){
    
    //cout<<x<<" : "<<L<<" : "<<R<<" : "<<K<<" : "<<a<<endl;
    
    if(L==R || A[L+1]==1){
        if(a%x == 0)
            printf("Yes\n");
        else    
            printf("No\n");
        return;    
    }
    
    
    if(A[L+1] == 0){
        if(x==1)
            printf("Yes\n");
        else
            printf("No\n");
        return;
    }
    
    
    if(a%x == 0){
        printf("Yes\n");
        return;
    }
    
    
    long long g = gcd(a, x);
    if(g == 1) {
        printf("No\n");
        return;
    }
    
    if(!mygreater(L+1, R, K+1)){
        printf("No\n");
        return;
    }
    funct(x/g, L, R, K+1, g);
}

int main(){
    
    int N,Q,L,R;
    long long x;
    scanf("%d", &N); 
    for(int i=0;i<N;i++)
        scanf("%lld", &A[i]);
    scanf("%d", &Q);
    for(int i=0;i<Q;i++){
        scanf("%d", &L);
        scanf("%d", &R);
        scanf("%lld", &x);
        funct(x, L-1, R-1, 0, A[L-1]);
    }
}