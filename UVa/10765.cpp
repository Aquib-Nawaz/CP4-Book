#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int>adjL[10000];
int dfsL[10000], dfsN[10000], val[10000], c;

struct node{
    int id,v;
    bool operator<(const struct node &rhs) const {
        if(v==rhs.v)return id<rhs.id;
        return v>rhs.v;
    }
}arr[10000];

void dfs(int u, int p){
    dfsL[u]=dfsN[u]=c++;
    val[u]=1;
    for(int v:adjL[u]){
        if(dfsN[v]==-1){
            dfs(v, u);
            if(dfsL[v]>=dfsN[u])val[u]++;
            dfsL[u] = min(dfsL[v], dfsL[u]);
        }
        else if(v!=p)
            dfsL[u] = min(dfsL[u], dfsN[v]); //cycle
    }
    if(u==0)val[u]--;
}

int main(){
    int N, M, u,v;
    while(scanf("%d%d", &N, &M), N){
        while(scanf("%d%d", &u,&v),u!=-1){
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        memset(dfsN, -1, sizeof dfsN);
        c=0;
        dfs(0,-1);
        for(int i=0;i<N;i++)adjL[i].clear(),arr[i]={i,val[i]};

        sort(arr, arr+N);
        for(int i=0;i<M;i++)printf("%d %d\n", arr[i].id, arr[i].v);
        printf("\n");
    }
}