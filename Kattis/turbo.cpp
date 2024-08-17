#include <iostream>
using namespace std;

int A[100001], F[100001],N,d;

void build(){
    for(int i=1;i<=N;i++){
        F[i] = i&-i;
    }
}

void update(int i, int x){
    while(i<=N){
        F[i]+=x;
        i+=i&-i;
    }
}

int query(int i){
    int ans = 0;
    while(i>0){
        ans+=F[i];
        i-=i&-i;
    }
    return ans;
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)scanf("%d", &d), A[d]=i+1;
    build();
    for(int i=1;i<N;i++){
        int j=i%2?(i+1)/2:N+1-i/2;
        printf("%d\n", i%2?query(A[j]-1):query(N)-query(A[j]));
        update(A[j],-1);
    }
    printf("0");
}