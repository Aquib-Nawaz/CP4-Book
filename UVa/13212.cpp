#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int A[1000001], tmp1[1000001];
#define REP(i,j,n) for(int i=j;i<n;i++)

long long get_cnt(int l, int r){
    if(r<=l)
        return 0;
    long long ret=0;
    int mid =(l+r)>>1;
    ret+= get_cnt(l,mid)+ get_cnt(mid+1, r);
    int i=l, j=mid+1, k=l;
    while(i<=mid || j<=r){
        if(j>r || (i<=mid && A[i]<=A[j]))
            tmp1[k++]=A[i++];
        else{
            tmp1[k++]=A[j++];
            ret+=mid-i+1;
        }
    }
    REP(i,l,r+1)A[i]=tmp1[i];
    return ret;
}

int main(){
    int n;
    while (scanf("%d", &n), n){
        REP(i,0,n)scanf("%d", &A[i]);
        printf("%lld\n", get_cnt(0,n-1));
    }

}