#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<int>adjL[100000];
int inDeg[2][100000];
bool lab[100000];

int solve(int t, int N){
    int x=t, u;
    queue<int>q[2];
    for(int i=0;i<N; i++)if(inDeg[t][i]==0)q[lab[i]].push(i);
    int ret=0;
    while(!q[0].empty() || !q[1].empty()){
        ret++;
        while(!q[x].empty()){
            u=q[x].front();
            q[x].pop();
            for(auto v: adjL[u]){
                inDeg[t][v]--;
                if(inDeg[t][v]==0)
                    q[lab[v]].push(v);
            }
        }
        x^=1;
    }
    return ret;
}

int main(){
    int T,N,M,d,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++) scanf("%d", &d), inDeg[0][i]=inDeg[1][i]=0, lab[i]=d-1==1, adjL[i].clear();
        for(int i=0;i<M;i++){
            scanf("%d%d",&d,&v);
            d--,v--;
            adjL[d].push_back(v);
            inDeg[0][v]++;
            inDeg[1][v]++;
        }
        printf("%d\n", min(solve(0,N), solve(1,N))-1);
    }

}