#include <iostream>
using namespace std;

int graph[202][202],N,M,curcc,cnt[6], order[]={1,5,3,2,4,0};
char H[]={'W', 'A', 'K', 'J', 'S', 'D'};

void hexToBin(int i, int j, char c){
    int v;
    if(c<='9')v=c-'0';
    else v = 10+c-'a';
    for(int k=3;k>=0;k--,j++)
        if(v&(1<<k))graph[i][j]=1;
        else graph[i][j]=0;
}

bool inRange(int r, int c){
    return r<=N+1 && c<=M+1 && r>=0 && c>=0 && graph[r][c]!=-1;
}
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

void dfs1(int r, int c){
    graph[r][c]=-1;
    for(auto & i : dir){
        int nr = r+i[0], nc = c+i[1];
        if(inRange(nr,nc)&&graph[nr][nc]==0)dfs1(nr,nc);
    }
}

void dfs2(int r, int c){
    graph[r][c]=-1;
    for(auto & i : dir){
        int nr = r+i[0], nc = c+i[1];
        if(inRange(nr,nc)){
            if(graph[nr][nc]==1)dfs2(nr,nc);
            else curcc++,dfs1(nr,nc);
        }
    }
}

int main(){
    char c;
    int C=0;
    while(scanf("%d%d",&N,&M),N){
        M<<=2;
        //Secure the borders

        for(int i=0;i<=N+1;i++)graph[i][0]=graph[i][M+1]=0;
        for(int i=0;i<=M+1;i++)graph[0][i]=graph[N+1][i]=0;

        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j+=4){
                scanf(" %c",&c);
                hexToBin(i,j+1,c);
            }
        }

        dfs1(0,0);

        for(int & i : cnt)i=0;
        for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
            if(graph[i][j]==1){
                curcc=0;
                dfs2(i,j);
                cnt[curcc]++;
            }
        }
        printf("Case %d: ",++C);
        for(auto & i : order)
            for(int j=0;j<cnt[i];j++)
                printf("%c",H[i]);
        printf("\n");
    }
}