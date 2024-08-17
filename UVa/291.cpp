#include <iostream>
using namespace std;

bool vis[6][6];
int cur[8];

void dfs(int u, int l){
    if(l==8){
        printf("1");
        for(int i : cur)printf("%d", i);
        printf("\n");
        return;
    }
    for(int i=1;i<=5;i++){
        if(!vis[u][i]){
            vis[u][i]=vis[i][u]=true;
            cur[l]=i;
            dfs(i,l+1);
            vis[u][i]=vis[i][u]=false;
        }
    }

}

int main(){
    for(int i=1;i<6;i++)for(int j=1;j<=5;j++)vis[i][j]=i==j;
    vis[1][4]=vis[4][1]=vis[2][4]=vis[4][2]= true;
    dfs(1,0);
}