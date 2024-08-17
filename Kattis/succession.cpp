#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long double ld;
unordered_map<string,int>mp;
vector<int>adjL[100];

ld dfs(int u) {
    if(u==0)return 1;
    if(adjL[u].empty())return 0;
    ld ret=0;
    for(int v:adjL[u]){
        ret+=dfs(v);
    }
    return ret/2;
}

char line[21];
int n=0;
int getIn(){
    scanf("%s", line);
    if(mp.count(line)==0)
        mp[line]=n++;
    return mp[line];
}

int main(){
    int N,M, u, v;
    scanf("%d%d", &N,&M);
    getIn();
    for(int i=0;i<N;i++){
        u=getIn();
        v=getIn();
        adjL[u].push_back(v);
        v=getIn();
        adjL[u].push_back(v);
    }
    string mxnam;
    ld ans=-1, tmp;
    for(int i=0;i<M;i++){
        scanf("%s", line);
        if(mp.count(line)==0)continue;
        u=mp[line];
        tmp=dfs(u);
        if(tmp>ans){
            ans=tmp;
            mxnam=line;
        }
    }
    printf("%s\n", mxnam.c_str());

}