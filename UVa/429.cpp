#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char line[11];
string W[200];
vector<int>adjL[200];
unordered_map<string, int>mp;
int dist[200][200];

void bfs(int i){
    if(dist[i][i]==0)return;
    dist[i][i]=0;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adjL[u]){
            if(dist[i][v]>dist[i][u]+1){
                dist[i][v]=dist[i][u]+1;
                q.push(v);
            }
        }
    }
}

int insertAndGetId(){
    mp[line]=mp.size();
    return mp[line];
}

void addEdge(string & u, string & v){
    if(u.size()!=v.size()){
        return;
    }
    int diff=0;
    for(int i=0;i<u.size();i++){
        if(u[i]!=v[i]){
            diff++;
        }
    }
    if(diff!=1){
        return;
    }
    adjL[mp[u]].push_back(mp[v]);
    adjL[mp[v]].push_back(mp[u]);
}

int main(){
    int T,u,v;
    scanf("%d", &T);

    while(T--){
        while(scanf("%s%*c", line), strcmp("*", line)!=0){
            u = insertAndGetId();
            W[u]=line;
            for(int i=0;i<u;i++){
                addEdge(W[i],W[u]);
            }
        }
        for(int i=0;i<mp.size();i++)for(int j=0;j<mp.size();j++)dist[i][j]=1e9;
        while(scanf("%[^\n ]", line)==1){
            u = mp[line];
            scanf("%s%*c", line);
            v = mp[line];
            bfs(u);
            printf("%s %s %d\n", W[u].c_str(), W[v].c_str(), dist[u][v]);
        }
        for(int i=0;i<mp.size();i++)adjL[i].clear();
        mp.clear();
        if(T!=0)printf("\n");
    }
}