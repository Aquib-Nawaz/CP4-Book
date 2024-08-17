#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int,int>>adjL[1001];
int dist[1001];
bool inqueue[1001];
int main(){
    int T,n,m;
    scanf("%d", &T);
    while (T-- ){
        scanf("%d%d", &n,&m);
        for(int i=0;i<n;i++){
            adjL[i].clear();
            dist[i]=1e8;
            inqueue[i]= false;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d", &a,&b,&c);
            adjL[a].push_back({b,c});
        }
        queue<int>q[2];
        q[0].push(0);
        dist[0]=0;
        for(int i=0,x;i<n-1;i++){
            x=i&1;
            while(!q[x].empty()){
                int u=q[x].front();
                q[x].pop();
                for(auto v:adjL[u]){
                    if(dist[v.first]>dist[u]+v.second){
                        dist[v.first]=dist[u]+v.second;
                        if(!inqueue[v.first])
                            q[x^1].push(v.first);
                    }
                }
            }
            for(int j=0;j<n;j++)inqueue[j]= false;
        }
        int x=n-1&1;
        bool hasCycle=false;
        while(!q[x].empty() && !hasCycle){
            int u=q[x].front();
            q[x].pop();
            for(auto v:adjL[u]){
                if(dist[v.first]>dist[u]+v.second){
                    hasCycle=true;
                    break;
                }
            }
        }
        printf("%s\n", hasCycle?"possible":"not possible");
    }
}