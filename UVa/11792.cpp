#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int>adjL[10001];
bool vis[10001];
unordered_set<int>important;
int dist[10001];

int main(){
    int T,N,S;
    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &N, &S);
        for(int i=1;i<=N;i++)adjL[i].clear(), vis[i]=false;
        important.clear();
        for(int i=0,c,p;i<S;i++){
            p=0;
            while(scanf("%d", &c),c!=0){
                if(p!=0){
                    adjL[p].push_back(c);
                    adjL[c].push_back(p);
                }
                if(vis[c])
                    important.insert(c);
                vis[c]= true;
                p=c;
            }
        }
        int mn=1e9,ansi,cur;
        for(auto u:important){
            for(int i=1;i<=N;i++)dist[i]=-1;
            cur=0;
            queue<int>q;
            q.push(u);
            dist[u]=0;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                if(important.count(v))
                    cur+=dist[v];
                for(auto w:adjL[v]){
                    if(dist[w]==-1){
                        dist[w]=dist[v]+1;
                        q.push(w);
                    }
                }
            }
            if(mn>cur || mn==cur&&ansi>u){
                mn=cur;
                ansi=u;
            }
        }
        printf("Krochanska is in: %d\n", ansi);
    }

}