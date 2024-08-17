#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<int> vi;
int cnt;
vi adjL[501];
bool vis[501];
struct edge{
    int u,v,w;
}arr[1000000];

void dfs(int u){
    vis[u]=1;
    cnt++;
    for(int v:adjL[u]){
        if(vis[v])continue;
        dfs(v);
    }
}

int main(){
    int N,M,mx;
    while (scanf("%d%d",&N,&M),N){
        mx=INT_MIN;
        for(int i=0;i<M;i++)scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].w),mx=max(mx,arr[i].w);
        for(int i=1;i<=N;i++)adjL[i].clear(), vis[i]=0;
        for(int i=0;i<M;i++){
            if(arr[i].w!=mx)continue;
            adjL[arr[i].u].push_back(arr[i].v);
            adjL[arr[i].v].push_back(arr[i].u);
        }
        int ans=0;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            cnt=0;
            dfs(i);
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }
}