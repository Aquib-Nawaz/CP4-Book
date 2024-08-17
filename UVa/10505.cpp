#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>adjL[200];
int vis[200];
int main(){
    int T, N, d, v;
    scanf("%d", &T);
    while(T--){
        scanf("%d ", &N);
        for(int i=0;i<N;i++){
            scanf("%d", &d);
            vis[i]=-1;
            for(int j=0;j<d;j++){
                scanf("%d", &v);
                if(v>N)continue;
                v--;
                adjL[i].push_back(v);
                adjL[v].push_back(i);
            }
        }
        queue<int>q;
        int ans=0, w,b;
        for(int i=0;i<N;i++){
            if(vis[i]==-1){
                w=0,b=0;
                q.push(i);
                vis[i]=0;
                bool cycle =false;
                while(!q.empty() ){
                    int u=q.front();
                    if(vis[u]==0)w++;
                    else b++;

                    q.pop();
                    for(int x:adjL[u]){
                        if(vis[x]==-1)
                            vis[x]=1-vis[u],q.push(x);
                        else if(vis[x]==vis[u]){
                            cycle=true;
                        }
                    }
                    adjL[u].clear();
                }
                if(!cycle)
                    ans+=max(w,b);
            }
        }
        printf("%d\n", ans);
    }
}