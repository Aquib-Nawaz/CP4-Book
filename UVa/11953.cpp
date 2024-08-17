#include <iostream>
using namespace std;

char graph[100][101];

int N, dir[2][2] = {{0,1}, {1,0}};
bool inRange(int i, int j){
    return  i<N&&j<N&&graph[i][j]!='.';
}
bool dfs(int i, int j, int k){
    bool ret=graph[i][j]=='x';
    graph[i][j]='.';
    int ni,nj;
    ni=i+dir[k][0], nj=j+dir[k][1];
    if(inRange(ni,nj))ret|=dfs(ni,nj,k);
    return ret;
}

int main(){
    int T,C=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%s",graph[i]);
        int cnt=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)if(graph[i][j]!='.')cnt+=dfs(i,j,0)|dfs(i,j,1);
        printf("Case %d: %d\n",++C,cnt);
    }
}