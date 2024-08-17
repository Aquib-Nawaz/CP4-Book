#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int A[100001],A1[100001], tmp1[100001];
#define REP(i,j,n) for(int i=j;i<n;i++)

long long get_cnt(int l, int r){
    if(r<=l)
        return 0;
    long long ret=0;
    int mid =(l+r)>>1;
    ret+= get_cnt(l,mid)+ get_cnt(mid+1, r);
    int i=l, j=mid+1, k=l;
    while(i<=mid || j<=r){
        if(j>r || (i<=mid && A1[A[i]]<=A1[A[j]]))
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
    int n,d;
    scanf("%d", &n);
    REP(i,0,n)scanf("%d", &A[i]);
    REP(i,0,n)scanf("%d", &d),A1[d]=i;
    printf("%s\n", get_cnt(0,n-1)%2==0?"Possible":"Impossible");

}