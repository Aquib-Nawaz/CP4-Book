#include <iostream>
using namespace std;

char graph[100][101];

int N,M, dir[8][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,1}, {1,1},
                      {-1,-1}, {1,-1}};
bool inRange(int i, int j){
    return  i<N && j<M && i>=0 && j>=0 && graph[i][j]!='.';
}
void dfs(int i, int j){
    graph[i][j]='.';
    int ni,nj;
    for(auto & k : dir){
        ni=i+k[0], nj=j+k[1];
        if(inRange(ni,nj))dfs(ni,nj);
    }
}

int main(){

    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)scanf("%s",graph[i]);
    int cnt=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(graph[i][j]!='.')dfs(i,j), cnt++;
    printf("%d\n",cnt);

}