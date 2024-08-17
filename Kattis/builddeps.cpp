#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int order[100000],l=0;
char name[100000][11];
vector<int>adjL[100000];
bool vis[100000];
unordered_map<string,int>mp;
char line[11],c;
void dfs(int u){
    vis[u]=true;
    for(int v: adjL[u])
        if(!vis[v])
            dfs(v);
    order[l++]=u;
}

int main(){
    int N,cnter=0, u;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf(" %[^:]:",line);

        if(mp.count(line)==0)mp[line]=cnter++;
        u=mp[line];
        strcpy(name[u] ,line);
        scanf("%c",&c);
        while(c!='\n'){
            scanf(" %s%c", line, &c);
            if(mp.count(line)==0)mp[line]=cnter++;
            adjL[mp[line]].push_back(u);
        }
    }
    scanf("%s", line);
    dfs(mp[line]);
    for(int i=l-1;i>=0;i--)
        printf("%s\n", name[order[i]]);

}