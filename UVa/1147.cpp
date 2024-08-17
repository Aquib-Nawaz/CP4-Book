#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;

int A[1000];
ll B[1001];

int f(int lo, int hi, int k){
    return abs((B[k]-B[lo])-(B[hi]-B[k+1]));
}

int partition(int lo, int hi){

    int ret=-1,v,cur;
    for(int i=lo;i<hi;i++){
        if(i!=hi-1&&A[i+1]==A[i])continue;
        cur=f(lo,hi,i);
        if(ret==-1|| cur<v || cur==v && B[ret]<B[i]){
            v=cur;
            ret=i;
        }
    }
    return ret;
}

void build(int lo, int hi){
    if(lo==hi)return;
    if(hi-lo==1){
        printf("%d",A[lo]);
        return;
    }
    int k= partition(lo,hi);
    printf("%d(",A[k]);
    build(lo,k);
    if(lo!=k&&hi-k-1!=0){
        printf(",");
    }
    build(k+1,hi);
    printf(")");
}

int main(){
    int T,C=0,n;
    scanf("%d",&T);
    B[0]=0;
    while (T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",A+i);
        sort(A,A+n);
        for(int i=0;i<n;i++)B[i+1]=B[i]+A[i];
        printf("Case #%d: ",++C);
        build(0,n);
        printf("\n");
    }
}