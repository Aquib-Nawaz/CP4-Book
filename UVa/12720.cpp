#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define REP(i,n)for(int i=0;i<n;i++)
#define PRIME 1000000007
char C[100001];
int main(){
    int t,n, ans, l, r;
    scanf("%d\n", &t);
    REP(c,t){
        printf("Case #%d: ", c+1);
        scanf("%s", C);
        n = strlen(C);
        ans=0, l=n/2-1, r=n/2;
        if(n%2)ans=C[n>>1]-'0', r++;
        REP(i,n/2){
            ans = (ans*2 + max(C[l]-'0', C[r]-'0'))%PRIME;
            ans = (ans*2 + min(C[l]-'0', C[r]-'0'))%PRIME;
            l--;r++;
        }
        printf("%d\n", ans);
    }
}