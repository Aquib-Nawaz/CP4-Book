#include <iostream>
using namespace std;

bool graph[100][100];
int N,M;
int dir[8][2] = {{-1,0}, {-1,1}, {1,1},
                 {1,-1}, {0,1}, {0,-1}, {-1,-1}, {1,0}};
int dfs(int r, int c){
    graph[r][c]= false;
    int nr,nc,ret=1;
    for(auto & i : dir){
        nr=r+i[0];
        nc=c+i[1];
        if(nr>=0&&nr<N&&nc>=0&&nc<M&&graph[nr][nc])ret+=dfs(nr,nc);
    }
    return ret;
}
int main(){
    char c;
    while(scanf("%d%d",&N,&M),N){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)scanf(" %c",&c), graph[i][j]=c=='@';
        }
        int ans=0,t;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)
            if(graph[i][j])t=dfs(i,j), ans+=t/100 + (t%100!=0);
        printf("%d\n", ans);
    }

}