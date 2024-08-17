#include <iostream>
#include <cstring>
using namespace std;
bool avail[26];
char line[251];
int dp[26], num[26];

int dfs(int u){
    if(dp[u]!=-1)return dp[u];
    num[u]=1;
    if(!avail[u])return 0;
    int ret=0;
    for(int v=u+1;v<26;v++){
        if(avail[v]&&5*(u+1)<=4*(v+1)){
            if(dfs(v)>ret)ret=dfs(v), num[u]=num[v];
            else if(dfs(v)==ret)num[u]+=num[v];
            else break;
        }
    }
    return dp[u]=ret+1;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf(" %[^\n]", line);
        for(int i=0;i<26;i++)avail[i]= false, dp[i]=-1;
        int l= strlen(line);
        for(int i=0;i<l;i++){
            if(line[i]>='A'&&line[i]<='Z')avail[line[i]-'A']= true;
        }
        int ans1=0, ans2;
        for(int i=0;i<26;i++)
            if(!avail[i])continue;
            else if(dfs(i)>ans1)ans1= dfs(i), ans2 = num[i];
            else if(dfs(i)==ans1)ans2+=num[i];
            else { break;}
        printf("%d %d\n", ans1, ans2);
    }
}