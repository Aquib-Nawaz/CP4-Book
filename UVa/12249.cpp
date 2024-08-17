#include <iostream>
#include <string>
using namespace std;
int cur[6], ans;

string A[6];

void solve(int mask, int l){
    if(mask==0){
        int curl=A[0].size();
        string curs=A[cur[0]];
        for(int i=1;i<l;i++){
            int j;
            for(j=min(curs.size(), A[cur[i]].size());j>0;j--){
                if(curs.substr(curs.size()-j,j)==A[cur[i]].substr(0,j))break;
            }
            curl+=A[i].size()-j;
            curs+=A[cur[i]].substr(j);
        }
        ans=min(ans, curl);
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
    int T,C=0,n;
    scanf("%d", &T);
    while(T--){
        scanf("%d ", &n);
        for(int i=0;i<n;i++)getline(cin, A[i]);
        ans=1e9;
        solve((1<<n)-1,0);
        printf("Case %d: %d\n", ++C, ans);
    }
}