#include <iostream>
using namespace std;

char graph[100][101];

int N,M, dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isSafeToMove(int i, int j){
    bool ret = true;
    for(auto & k : dir){
        ret &= graph[i+k[0]][j+k[1]]!='T';
    }
    return ret;
}
int dfs(int i, int j){
    int ret = graph[i][j]=='G';
    graph[i][j]='#';
    int ni,nj;
    if(isSafeToMove(i,j))
        for(auto & k : dir){
            ni=i+k[0], nj=j+k[1];
            if(graph[ni][nj]!='#')ret+=dfs(ni,nj);
        }
    return ret;
}

int main(){
    scanf("%d%d",&M,&N);
    for(int i=0;i<N;i++)scanf("%s",graph[i]);
    int ans;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(graph[i][j]=='P'){
                ans=dfs(i,j);
                break;
            }
    printf("%d\n", ans);
}