#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
using namespace std;

unordered_map<string, int>mp;
long long dist[2][100], dp[100];
bool inqueue[100];
vector<pair<int,int>>adjL[100];
char city[21];
int main(){
    int T,n,m,u,v,w,C=0;
    scanf("%d", &T);
    while (T--){
        scanf("%d ", &n);
        mp.clear();
        for(int i=0;i<n;i++){
            scanf("%s", city);
            mp[string(city)] = i;
            adjL[i].clear();
            dist[1][i]=dist[0][i]=1e15;
        }
        scanf("%d", &m);
        for(int i=0;i<m;i++){
            scanf("%s", city);
            u=mp[city];
            scanf("%s", city);
            v=mp[city];
            scanf("%d", &w);
            adjL[u].push_back({v,w});
        }
        queue<int>q[2];
        q[0].push(0);
        dist[0][0]=0;
        for(int i=0,x;i<n-1;i++){
            x=i&1;
            for(int j=0;j<n;j++)inqueue[j]= false;
            while (!q[x].empty()){
                u=q[x].front();
                q[x].pop();
                for(auto p:adjL[u]){
                    v=p.first;
                    w=p.second;
                    if (dist[1-x][v]>dist[x][u]+w){
                        dist[1-x][v]=dist[x][u]+w;
                        if(!inqueue[v])
                            q[1-x].push(v), inqueue[v]=true;
                    }
                }
            }
            for(int j=0;j<n;j++)dist[x][j]=dist[1-x][j]=min(dist[1-x][j], dist[x][j]);
            dp[i]=dist[1-x][n-1];
        }
        int Q;
        scanf("%d", &Q);
        printf("Scenario #%d\n", ++C);
        for(int i=0;i<Q;i++){
            scanf("%d", &u);
            if(u>n-2)u=n-2;
            if(dp[u]>1e14)printf("No satisfactory flights\n");
            else printf("Total cost of flight(s) is $%lld\n", dp[u]);
        }
        if(T)printf("\n");
    }
}