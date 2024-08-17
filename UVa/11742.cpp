#include <iostream>
using namespace std;
int ans, cur[8], n,m;

struct {
    int a,b,c;
} Q[20];

void solve(int mask, int l){
    if(mask==0){
        bool ok= true;
        for(int i=0;i<m&&ok;i++){
            if(Q[i].c>0){if(abs(cur[Q[i].a]-cur[Q[i].b])>Q[i].c)ok=false;}
            else if(abs(cur[Q[i].a]-cur[Q[i].b])<-Q[i].c)ok=false;
        }
        ans+=ok;
        return;
    }
    int _m=mask, t, lg;
    while(_m){
        t = _m&-_m;
        _m^=t;
        lg = __builtin_ctz(t);
        cur[lg]=l;
        solve(mask^t, l+1);
    }
}
int main(){
    while(scanf("%d %d", &n,&m), n){
        for(int i=0;i<m;i++)scanf("%d %d %d", &Q[i].a, &Q[i].b, &Q[i].c);
        ans=0;
        solve((1<<n)-1,0);
        printf("%d\n", ans);
    }
}