#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<int>adjL[1000001];
int inDeg[1000001], order[1000000];

bool solve(int N){
    int l=0, u;
    queue<int>q;
    for(int i=1;i<=N; i++)if(inDeg[i]==0)q.push(i);
    while(!q.empty()){
        u=q.front();
        order[l++]=u;
        q.pop();
        for(auto v: adjL[u]){
            inDeg[v]--;
            if(inDeg[v]==0)
                q.push(v);
        }
    }
    return l==N;
}

int main(){
    int N,M,u,v;
    scanf("%d%d",&N,&M);
    memset(inDeg,0, (N+1)*sizeof(int));
    for(int i=0;i<M;i++){
        scanf("%d%d",&u,&v);
        adjL[u].push_back(v);
        inDeg[v]++;
    }

    if(!solve(N))printf("IMPOSSIBLE\n");
    else
        for(int i=0;i<N;i++)printf("%d\n", order[i]);

}