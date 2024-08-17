#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string name[25];
unordered_map<string,int>mp;
int order[25],c,x,N;
unordered_set<int>adjL[2][25];
bool vis[25],f;
char line[26];
void dfs(int u){
    vis[u]=true;
    for(auto v:adjL[x][u]){
        if(!vis[v])dfs(v);
    }
    if(x){
        if(!f)printf(", ");
        printf("%s",name[u].c_str());
        f=false;
    }
    else
        order[--c]=u;
}

int main(){
    int M,u,C=0;
    while(scanf("%d%d", &N,&M),N){
        for(int i=0;i<N;i++)vis[i]=false, adjL[0][i].clear(), adjL[1][i].clear();
        mp.clear();
        c=0;
        for(int i=0;i<M;i++){
            scanf("%s", line);
            if(mp.count(line)==0)mp[line]=c, name[c]=line, c++;
            u=mp[line];
            scanf("%s", line);
            if(mp.count(line)==0)mp[line]=c, name[c]=line, c++;
            adjL[0][u].insert(mp[line]);
            adjL[1][mp[line]].insert(u);
        }
        x=0;
        for(int i=0;i<N;i++)if(!vis[i])dfs(i);
        for(int i=0;i<N;i++)vis[i]= false;
        x=1;
        if(C!=0)printf("\n");
        printf("Calling circles for data set %d:\n",++C);
        for(int i=0;i<N;i++)if(!vis[order[i]])f=true, dfs(order[i]), printf("\n");

    }
}
