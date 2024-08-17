#include <iostream>
using namespace std;

int G[502][502];
bool Y[502][502];

int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

void dfs(int i, int j){
    Y[i][j]=true;
    for(int k=0;k<4;k++){
        if(G[i+dir[k][0]][j+dir[k][1]]==G[i][j]&&!Y[i+dir[k][0]][j+dir[k][1]])
            dfs(i+dir[k][0],j+dir[k][1]);
    }
}

int main(){
    int M,N,cnt=0;
    scanf("%d%d",&M,&N);
    for(int i=1;i<=N;i++){
        G[i][0]=G[i][M+1]=1000;
        for(int j=1;j<=M;j++)
            scanf("%d",&G[i][j]),Y[i][j]=false;
    }
    for(int i=0;i<=M+1;i++)G[0][i]=G[N+1][i]=1000;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
        if(Y[i][j])continue;
        for(int k=0;k<4;k++){
            if(G[i+dir[k][0]][j+dir[k][1]]<G[i][j])
                Y[i][j]=true;
        }
        if(Y[i][j])
            dfs(i,j);
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(!Y[i][j])cnt++;
    printf("%d\n",cnt);
}