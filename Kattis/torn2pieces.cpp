#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int>adjL[10000];
int par[10000];
unordered_map<string,int>mp;
string name[10000];
char line[31];

int main(){
    int M, N=0, u, v;
    char c;
    scanf("%d", &M);
    memset(par, -1, sizeof par);
    for(int i=0;i<M;i++){
        scanf("%s", line);
        if(mp.count(line)==0)name[N]=line,mp[line]=N++;
        u=mp[line];
        while(true){
            scanf(" %s%c", line,&c);
            if(mp.count(line)==0)name[N]=line,mp[line]=N++;
            v=mp[line];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
            if(c=='\n')break;
        }
    }

    int s,d;
    scanf("%s", line), s=mp[line];
    scanf("%s", line), d=mp[line];
    queue<int>q;
    q.push(d);
    par[d]=-2;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(u==s)break;
        for(int v:adjL[u]){
            if(par[v]==-1){
                par[v]=u;
                q.push(v);
            }
        }
    }
    if(par[s]==-1)printf("no route found\n");
    else {
        printf("%s", name[s].c_str());
        for(int i=par[s];i!=-2;i=par[i]){
            printf(" %s", name[i].c_str());
        }
        printf("\n");
    }

}