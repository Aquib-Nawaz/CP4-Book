#include <iostream>
using namespace std;

char graph[9][10];

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
char op[2]={'X', 'O'};
bool isInRange(int i, int j, int k){
    return i<9&&j<9&&i>=0&&j>=0 && (graph[i][j]=='.'|| graph[i][j]=='0'+k);
}

void dfs(int i, int j, int val){
    if(graph[i][j]=='.')
        graph[i][j]='0'+val;
    else if(graph[i][j]==1-val+'0')
        graph[i][j]='2';
    int ni,nj;
    for(auto & k : dir){
        ni=i+k[0], nj=j+k[1];
        if(isInRange(ni,nj,1-val))dfs(ni,nj,val);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<9;i++)scanf("%s",graph[i]);
        int ans[2]={0,0};
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                for(int k=0;k<2;k++)
                    if(graph[i][j]==op[k]){
                        dfs(i,j,k), ans[k]++;
                    }
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)
            if(graph[i][j]=='0')ans[0]++;
            else if(graph[i][j]=='1')ans[1]++;
        printf("Black %d White %d\n", ans[0], ans[1]);
    }
}