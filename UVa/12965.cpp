#include <iostream>
#include <algorithm>
using namespace std;
int A[10001],B[10001],T,N,M;
int f(int x){
    int ans=0;
    ans+= N-(upper_bound(A,A+N,x)-A);
    ans+= (upper_bound(B,B+M,x-1)-B);
    return ans;
}

int main(){
    scanf("%d",&T);
    while(T--){

        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++)scanf("%d",&A[i]);
        for(int i=0;i<M;i++)scanf("%d",&B[i]);
        sort(A,A+N);
        sort(B,B+M);
        int ans=f(0),cur,p=0;
        for(int i=0;i<N;i++){
            cur=f(A[i]);
            if(cur<ans||(cur==ans&&p>A[i]))ans=cur,p=A[i];
        }
        for(int i=0;i<M;i++){
            cur=f(B[i]);
            if(cur<ans||(cur==ans&&p>B[i]))ans=cur,p=B[i];
        }
        printf("%d %d\n",p,ans);
    }
}
