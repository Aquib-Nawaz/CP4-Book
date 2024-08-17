#include <iostream>
#include <cstring>
using namespace std;
int cur[10], ans;

int A[10];
char C[27];

void solve(int mask, int l){
    if(mask==0){
        int s=0;
        for(int i=0;i<l-1;i++){
            s+=__builtin_popcount(A[cur[i]]&A[cur[i+1]]);
        }
        ans = min(ans,s);
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
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", C);
        for(int j=0;j< strlen(C);j++)A[i]|=1<<(C[j]-'A');
    }
    ans=1e9;
    solve((1<<n)-1, 0);
    printf("%d\n", ans);
    return 0;
}