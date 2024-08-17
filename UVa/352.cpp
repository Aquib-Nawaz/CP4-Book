#include <iostream>
using namespace std;

bool graph[25][25];
int N;
int dir[8][2] = {{-1,0}, {-1,1}, {1,1},
                 {1,-1}, {0,1}, {0,-1}, {-1,-1}, {1,0}};
void dfs(int r, int c){
    graph[r][c]= false;
    int nr,nc;
    for(auto & i : dir){
        nr=r+i[0];
        nc=c+i[1];
        if(nr>=0&&nr<N&&nc>=0&&nc<N&&graph[nr][nc])dfs(nr,nc);
    }

}
int main(){
    char c;
    int C=0;
    while(scanf("%d",&N)!=-1){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)scanf(" %c",&c), graph[i][j]=c=='1';
        }
        int ans=0;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)
            if(graph[i][j])dfs(i,j), ans++;
        printf("Image number %d contains %d war eagles.\n",++C, ans);
    }

}