#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>adjL[1000];
int dist[1000];

int main(){
    int N,H,L,u,v;
    scanf("%d%d%d", &N,&H,&L);
    for(int i=0;i<N;i++)dist[i]=1e9;
    queue<int>q;
    for(int i=0;i<H;i++)scanf("%d", &u), q.push(u), dist[u]=0;
    for(int i=0;i<L;i++){
        scanf("%d%d", &u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int v:adjL[u]){
            if(dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    int ans=0;
    for(int i=0;i<N;i++){
        if(dist[i]>dist[ans])
            ans=i;
    }
    printf("%d\n", ans);
}