#include <iostream>
using namespace std;

char graph[20][21],l,w;
int N,M;

bool inRange(int r, int &c){
    if(c>M)c-=M;
    else if(c<0)c+=M;
    return r<N && r>=0 && graph[r][c]==l;
}

int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

int dfs(int r, int c){
    graph[r][c]=w;
    int ret=1;
    for(auto & i : dir){
        int nr = r+i[0], nc = c+i[1];
        if(inRange(nr,nc))ret+=dfs(nr,nc);
    }
    return ret;
}

int main(){
    int u,v,ans;
    while(scanf("%d%d",&N,&M)!=-1){
        for(int i=0;i<N;i++)scanf("%s",graph[i]);
        scanf("%d%d",&u,&v);
        l=graph[u][v];
        w=l+1;
        dfs(u,v);
        ans=0;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)
            if(graph[i][j]==l)ans=max(ans,dfs(i,j));
        printf("%d\n",ans);
    }
}