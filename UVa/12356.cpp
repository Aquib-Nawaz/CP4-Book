#include <iostream>
using namespace std;
int A[100001],P[100001],N[100001];

int get_P(int i,int n){
    if(i==0)
        return 0;
    if(A[i]!=-1)
        return i;
    if(P[i]==i)
        return P[i]=get_P(i-1,n);
    return P[i]=get_P(P[i],n);
}

int get_N(int i, int n){
    if(i==n+1)
        return n+1;
    if(A[i]!=-1)
        return i;
    if(N[i]==i)
        return N[i]=get_N(i+1,n);
    return N[i]=get_N(N[i],n);
}

int main(){
    int S, B, L, R;
    while(scanf("%d %d", &S, &B), S){
        for(int i=1;i<S+1;i++)
            A[i]=i,N[i]=i,P[i]=i;
        for(int i=0;i<B;i++){
            scanf("%d %d", &L, &R);
            for(int j=L;j<R+1;j++)
                A[j]=-1;
            int p=get_P(L-1,S);
            int n=get_N(R+1,S);
            if(p==0)
                printf("* ");
            else
                printf("%d ", p);
            if(n==S+1)
                printf("*\n");
            else
                printf("%d\n", n);
        }
        printf("-\n");
    }
}