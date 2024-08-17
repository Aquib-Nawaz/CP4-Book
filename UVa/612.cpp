#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
char A[101][51], tmp[51], tmp1[51];
int perm[101], cnt[101];
#define REP(i,j,n) for(int i=j;i<n;i++)

int get_cnt(int l, int r){
    if(r<=l)
        return 0;
    int ret=0;
    int mid =(l+r)>>1;
    ret+= get_cnt(l,mid)+ get_cnt(mid+1, r);
    int i=l, j=mid+1, k=l;
    while(i<=mid || j<=r){
        if(j>r || (i<=mid && tmp[i]<=tmp[j]))
            tmp1[k++]=tmp[i++];
        else{
            tmp1[k++]=tmp[j++];
            ret+=mid-i+1;
        }
    }
    strncpy(tmp+l, tmp1+l, r-l+1);
    return ret;
}

int main(){
    int T,n,m;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &m,&n);
        memset(cnt,0, sizeof cnt);
        REP(i,0,n)scanf("%s", A[i]),perm[i]=i;
        REP(i,0,n)strcpy(tmp, A[i]),cnt[i]=get_cnt(0,m-1);
        stable_sort(perm,perm+n,[&](int a, int b){return cnt[a]<cnt[b];});
        REP(i,0,n)printf("%s\n", A[perm[i]]);
        if(T)printf("\n");
    }
}
