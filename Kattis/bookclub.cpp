#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int mt[10000];
bool used[10000], used1[10000];
vector<int>adj[10000];

bool try_kuhn(int u){
    if(used[u])return false;
    used[u]=true;
    for(int v:adj[u]){
        if(mt[v]==-1||try_kuhn(mt[v])){
            mt[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
    int N,M;
    scanf("%d%d", &N,&M);
    for(int i=0;i<N;i++)mt[i]=-1,used1[i]=false;
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d", &a,&b);
        adj[a].push_back(b);
        if(!used1[a]&&mt[b]==-1)mt[b]=a,used1[a]= true;
    }
    for(int i=0;i<N;i++){
        if(!used1[i]){
            memset(used, 0, sizeof used);
            try_kuhn(i);
        }
    }
    int ans=0;
    for(int i=0;i<N;i++)if(mt[i]!=-1)ans++;
    printf("%s\n", ans==N?"YES":"NO");
}