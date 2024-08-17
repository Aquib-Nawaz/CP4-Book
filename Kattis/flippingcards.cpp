#include <iostream>
#include <vector>
using namespace std;

int mt[100001];
vector<int>adj[50001];
bool used1[50001], used[50001];

bool try_kuhn(int u){
    if(used[u]) return false;
    used[u]=true;
    for(int v:adj[u]){
        if(mt[v]==-1 || try_kuhn(mt[v])){
            mt[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        for(int i=1;i<=2*N;i++)mt[i]=-1;
        for(int i=0;i<N;i++){
            int a,b;
            used1[i]=false;
            adj[i].clear();
            scanf("%d %d", &a, &b);
            adj[i].push_back(a);
            if(b!=a)
                adj[i].push_back(b);
            if(mt[a]!=-1)used1[i] = true, mt[a]=i;
            else if(mt[b]!=-1)used1[i] = true, mt[b]=i;
        }
        bool poss=true;
        for(int i=0;i<N&&poss;i++){
            if(!used1[i]){
                for(int j=0;j<N;j++)used[j]= false;
                poss&=try_kuhn(i);
            }
        }
        printf("%s\n", poss?"possible":"impossible");
    }
}