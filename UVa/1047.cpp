#include <iostream>
#include <unordered_map>
using namespace std;
int k,ans,cur[20],n,am,S[20];
unordered_map<int,int>M;
void solve(int idx, int l){
    if(l==k){
        int m=0,s=0;
        for(int i=0;i<k;i++)m|=1<<cur[i],s+=S[cur[i]];

        for(auto &it:M) {
            int _m=(it.first & m);
            if (_m) s -=  (__builtin_popcount(_m)-1) * it.second;
        }
        if(s>ans)ans=s,am=m;
        return;
    }
    for(int i=idx; n-i>=k-l;i++){
        cur[l]=i;
        solve(i+1,l+1);
    }
}

int main(){
    int d,m, t, _m,C=0;
    while(scanf("%d %d", &n,&k),n){
        M.clear();
        for(int i=0;i<n;i++){
            scanf("%d",S+i);
        }
        scanf("%d", &m);
        for(int i=0;i<m;i++){
            _m=0;
            scanf("%d", &t);
            for(int j=0;j<t;j++){
                scanf("%d", &d);
                d--;
                _m|=1<<d;
            }
            scanf("%d", &d);
            M[_m]+=d;
        }
        ans=0;
        solve(0,0);
        printf("Case Number  %d\n",++C);
        printf("Number of Customers: %d\n", ans);
        printf("Locations recommended:");
        for(int i=0;am;i++,am>>=1)if(am&1)printf(" %d",i+1);
        printf("\n\n");
    }
}