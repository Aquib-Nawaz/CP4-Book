#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

set<int>adjL[26];
char path[27];
int dp[26];

int dfs(int u){
    if(dp[u]!=-1)return dp[u];
    if(adjL[u].empty())return 1;
    int ret=0;
    for(auto v:adjL[u]){
        ret += dfs(v);
    }
    return dp[u]=ret;
}

int main(){
    int T,n,m,q;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &n,&m);
        for(int i=0;i<n;i++)adjL[i].clear(), dp[i]=-1;
        for(int i=0;i<m;i++){
            char a,b;
            scanf(" %c%c",&a,&b);
            adjL[a-'A'].insert(b-'A');
        }
        scanf("%d", &q);
        while(q--){
            scanf("%s", path);
            int cur = path[0]-'A', ans=0;
            for(int i=1;i< strlen(path); i++){
                for(auto v:adjL[cur]){
                    if(v==path[i]-'A')break;
                    ans+=dfs(v);
                }
                cur=path[i]-'A';
            }
            printf("%s: %d\n",path, ans+1);
        }
    }
}