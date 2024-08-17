#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int>adjL[100001];
int deg[100001];
int main(){
    int N,M,u,v,K;
    scanf("%d%d%d", &N,&K,&M);
    memset(deg,0,sizeof deg);
    for(int i=0;i<M;i++){
        scanf("%d%d",&u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(deg[K]<2)
    {printf("YES\n"); return 0;}
    queue<int>q;
    for(int i=1;i<=N;i++)if(deg[i]==1)q.push(i);
    bool f=false;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(u==K){
            f= true;
            break;
        }
        for(int v:adjL[u]){
            deg[v]--;
            if(deg[v]==1)q.push(v);
        }
    }
    if(f)
        printf("YES\n");
    else
        printf("NO\n");
}

