#include <iostream>
#include <set>
using namespace std;

int A[5], ans, cur[5], m;
typedef struct {
   int m,l,r;
}Q;

Q q[1000];
void solve(int mask, int l){
    if(mask==0){
        int buf=0, mbuf=0, req=1;
        set<pair<int,int>>s[l];
        set<pair<int,int>>::iterator it;
        for(int i=0,j=0;i<m;i++){
            while(!s[cur[j]].empty()&&(it=s[cur[j]].begin())->first==req){
                req=it->second+1,s[cur[j]].erase(it);
                buf-=req-it->first;
                if(req>A[cur[j]])j++,req=1;
            }
            if(q[i].m==cur[j]&&q[i].l==req){req=q[i].r+1;if(req>A[cur[j]])j++,req=1;}
            else{
                buf+=q[i].r-q[i].l+1;
                s[q[i].m].insert({q[i].l,q[i].r});
                mbuf = max(mbuf, buf);
            }
        }
        ans = min(ans,mbuf);
        return;
    }
    int _m=mask, t, lg;
    while(_m){
        t = _m&-_m;
        _m^=t;
        lg = __builtin_ctz(t);
        cur[l]=lg;
        solve(mask^t, l+1);
    }
}

int main(){
    int C=0,n;
    while(scanf("%d %d", &n,&m),n){
        for(int i=0;i<n;i++)scanf("%d", &A[i]);
        for(int i=0;i<m;i++)scanf("%d %d %d", &q[i].m, &q[i].l, &q[i].r), q[i].m--;
        ans=1e9;
        solve((1<<n)-1,0);
        printf("Case %d: %d\n\n", ++C, ans);
    }
}