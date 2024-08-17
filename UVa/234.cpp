#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

int A[10], L[8], I[8], T[8],p,a;
int miss[5], amiss[5], O[8], cur[8];

void solve(int mask, int l){
    if(mask==0){
        int t, *it;
        memset(miss,0,sizeof miss);
        for(int i=0;i<a;i++){
            t=INT_MAX;
            it = lower_bound(A, A+l+1,T[i]);
            if(it!=A+l+1)t=min(abs(*it-T[i]),t);
            if(it!=A)t=min(abs(*--it-T[i]),t);
            miss[I[i]]+=t;
        }
        for(int i=0;i<5;i++)
            if(miss[i]<amiss[i])
            {memcpy(O,cur,sizeof cur), memcpy(amiss,miss,sizeof miss); return;}
            else if(miss[i]>amiss[i])break;

        return;
    }
    int _m=mask, t, lg;
    while(_m){
        t = _m&-_m;
        _m^=t;
        lg = __builtin_ctz(t);
        A[l+1]=A[l]+L[lg];
        cur[l]=L[lg];
        solve(mask^t, l+1);
    }
}

int main(){
    A[0]=0;
    int C=0;
    while (scanf("%d",&p),p!=0){
        for(int i=0;i<p;i++)scanf("%d", L+i);
        scanf("%d", &a);
        for(int i=0;i<a;i++)scanf("%d %d", I+i,T+i), I[i]--;
        for(int i=0;i<5;i++)amiss[i]=miss[i]=1e9;
        solve((1<<p)-1, 0);
        printf("Data set %d\n  Order:", ++C);
        for(int i=0;i<p;i++)printf(" %d", O[i]);
        int s=0;
        for(int i=0;i<5;i++)s+=amiss[i];
        printf("\n  Error: %d\n", s);
    }
}