#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<pair<int,int>,vector<pair<int,int>>>adj;
char g[100][101];
int r[100][100];
map<pair<int,int>, pair<int,int>>mp;
set<pair<int,int>>vis1, vis;

bool try_kuhn(pair<int,int>u){
    if(!vis.insert(u).second)return false;
    for(auto v:adj[u]){
        if(mp.count(v)==0 || try_kuhn(mp[v])){
            mp[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
    int N;
    while (scanf("%d", &N)==1){
        mp.clear(), adj.clear(), vis1.clear();
        for(int i=0;i<N;i++)scanf("%s", g[i]);
        for(int i=0;i<N;i++)for(int j=0,cr=0;j<N;j++){
            if(g[i][j]=='X')cr++, r[i][j]=-1;
            else r[i][j]=cr;
        }
        for(int j=0;j<N;j++)for(int i=0,cr=0;i<N;i++){
            if(g[i][j]=='X')cr++;
            else{
                adj[{i,r[i][j]}].push_back({j,cr});
                if(mp.count({j,cr})==0 && vis1.count({i,r[i][j]})==0)
                    mp[{j,cr}]={i,r[i][j]}, vis1.insert({i,r[i][j]});
            }
        }
        for(auto it:adj){
            if(vis1.count(it.first)==0){
                vis.clear();
                try_kuhn(it.first);
            }
        }
        printf("%d\n", mp.size());
    }

}