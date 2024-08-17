#include <iostream>
#include <cstring>
using namespace std;
int PRO[20];
int ans=0,n;
void solve(int id, int pro){
    ans++;
    for(int i=id;i<n;i++){
        if(1<<i&pro)continue;
        solve(i+1,pro|PRO[i]);
    }
}
int main(){
    int m,a,b;
    scanf("%d %d", &n, &m);
    memset(PRO,0,sizeof(PRO));
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        a--;b--;
        PRO[a]|=(1<<b);
        PRO[b]|=(1<<a);
    }
    solve(0,0);
    printf("%d", ans);
}