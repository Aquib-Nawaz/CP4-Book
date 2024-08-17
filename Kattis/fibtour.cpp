#include <iostream>
#include <vector>
#include <map>
using namespace std;

int V[100001];
map<long long,int>mp;
vector<int>adjL[100001];
int dp[100001];
bool ones[100001];
int dfs(int u){
    if(dp[u]!=-1)return dp[u];
    if(V[u]==-1)return 0;
    int ret=0;
    for(int v:adjL[u]){
        ret=max(ret,dfs(v));
    }
    return dp[u]=ret+1+ones[u];
}

int main(){
    int N,M;
    scanf("%d%d", &N,&M);
    long long p=1,c=1,t;
    while(c<=1e18){
        mp[c] = mp.size();
        t=c;
        c+=p;
        p=t;
    }
    for(int i=1;i<=N;i++){
        scanf("%lld", &t);
        if(mp.count(t)==0)V[i]=-1;
        else V[i]=mp[t];
        dp[i]=-1, ones[i]=false;
    }
    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d%d", &u,&v);
        if(V[u]==0 && V[v]==0)ones[v]=ones[u] = true;
        if(abs(V[u]-V[v])!=1)continue;
        if(V[u]<V[v])adjL[u].push_back(v);
        else adjL[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=N;i++)ans= max(ans,dfs(i));
    printf("%d\n", ans);

}