#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int>adjL[100000];
int dist[100000],n;
bool vis[2][100000];

int findFurthest(int u, int x){
    queue<int>q;
    q.push(u);
    dist[u]=0;
    vis[x][u]= true;
    while (!q.empty()){
        u=q.front();
        q.pop();
        for(int v:adjL[u]){
            if(!vis[x][v]){
                dist[v]=dist[u]+1;
                q.push(v);
                vis[x][v]=true;
            }
        }
    }
    return u;
}
int diameter(int u){
    int x = findFurthest(u,0);
    int y = findFurthest(x,1);
    return dist[y];
}

int main(){
    int l;
    scanf("%d%d", &n,&l);
    for(int i=0;i<l;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    for(int i=0;i<n;i++)vis[0][i]=vis[1][i]= false;
    vector<int>diam;
    for(int i=0;i<n;i++)if(!vis[0][i])diam.push_back(diameter(i));
    sort(diam.begin(),diam.end());
    for(int i=0,d1,d2,d3;diam.size()>1;i++){
        d1=d2=diam.back()/2;
        d1+= diam.back()&1;
        diam.pop_back();
        d3=diam.back()/2;
        d3+= diam.back()&1;
        diam.pop_back();
        diam.push_back(max(d2, d3+1)+d1);
    }
    printf("%d\n", diam[0]);
}