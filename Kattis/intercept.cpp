#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll dis[2][100000];
int N,M;
vector<pair<int,int>>adjL[2][100000];
bool pushed[100000];

void djikstra(int s, int x){

    for(int i = 0; i < N; i++){
        dis[s][i] = 1e18;
    }
    dis[s][x] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>q;
    q.emplace(0,x);
    int u,w,v;
    ll d;
    while(!q.empty()){
        u=q.top().second, d=q.top().first;
        q.pop();
        if(dis[s][u]!=d)continue;
        for(auto it:adjL[s][u]){
            v=it.first, w=it.second;
            if(dis[s][v]>d+w){
                dis[s][v]=d+w;
                q.emplace(dis[s][v],v);
            }
        }
    }
}

int main(){
    scanf("%d%d", &N,&M);
    int u,v,w,s,d;
    for(int i = 0; i < M; i++){
        scanf("%d%d%d", &u,&v,&w);
        adjL[0][u].emplace_back(v,w);
        adjL[1][v].emplace_back(u,w);
    }
    scanf("%d%d", &s,&d);
    djikstra(0,s);
    djikstra(1,d);
    vector<int>res;
    priority_queue<pair<ll,int>>q;
    q.emplace(0,s);
    memset(pushed,0,sizeof pushed);
    pushed[s]= true;
    while(!q.empty()){
        u=q.top().second;
        q.pop();
        if(q.empty())res.push_back(u);
        if(u==d)break;
        for(auto it:adjL[0][u]){
            v=it.first, w=it.second;
            if(pushed[v])continue;
            if(dis[0][u]+dis[1][v]+w==dis[0][d]){
                pushed[v]=true;
                q.emplace(-dis[0][v],v);
            }
        }
    }
    sort(res.begin(),res.end());
    printf("%d",res[0]);
    for(int i=1;i<res.size();i++)
        printf(" %d",res[i]);
    printf("\n");
    return 0;
}