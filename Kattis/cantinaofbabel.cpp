#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

vector<int>adjL[2][100];
string speak[100];
unordered_set<string>understands[100];
char line[16],c;
int cnt=0,x, order[100],C;
bool vis[100];

void dfs(int u){
    vis[u]=true;
    for(auto v:adjL[x][u]){
        if(!vis[v])dfs(v);
    }
    if(x){
        cnt++;
    }
    else
        order[--C]=u;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf(" %*s%s%c", line, &c);
        speak[i]=line;
        understands[i].insert(speak[i]);
        while(c!='\n'){
            scanf("%s%c", line, &c);
            understands[i].insert(line);
        }
        for(int j=0;j<i;j++){
            if(understands[j].count(speak[i]))
                adjL[0][i].push_back(j), adjL[1][j].push_back(i);
            if(understands[i].count(speak[j]))
                adjL[0][j].push_back(i), adjL[1][i].push_back(j);
        }
        vis[i]=false;
    }
    x=0,C=N;
    for(int i=0;i<N;i++)if(!vis[i])dfs(i);
    for(int i=0;i<N;i++)vis[i]= false;
    x=1;
    int ans=0;
    for(int i=0;i<N;i++)if(!vis[order[i]]){
        cnt=0;
        dfs(order[i]);
        ans=max(ans,cnt);
    }
    printf("%d",N-ans);
}