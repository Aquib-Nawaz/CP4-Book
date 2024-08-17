#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

unordered_map<string,int>mp;
vector<pair<int,int>>adjL[101];
int dist[101],cost[101];
int main(){
    mp.emplace("English", 0);
    int N,M,u,v,w;
    scanf("%d%d ", &N,&M);
    string s;
    for(int i=1;i<=N;i++){
        cin >> s;
        mp.emplace(s, i);
        dist[i]=-1;
    }
    for(int i=0;i<M;i++){
        cin >> s;
        u=mp[s];
        cin >> s >> w;
        v=mp[s];
        adjL[u].emplace_back(v,w);
        adjL[v].emplace_back(u,w);
    }
    int rem=N+1;
    queue<int>q;
    q.emplace(0);
    dist[0]=0;
    while(!q.empty()&&rem){
        u=q.front();
        q.pop();
        rem--;
        for(auto it:adjL[u]){
            v=it.first, w=it.second;
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                cost[v]=w;
                q.emplace(v);
            }
            else if(dist[v]==dist[u]+1)cost[v]=min(cost[v],w);
        }
    }
    if(rem)printf("Impossible\n");
    else{
        int ans=0;
        for(int i=1;i<=N;i++)ans+=cost[i];
        printf("%d\n", ans);
    }
}