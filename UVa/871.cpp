#include <iostream>
using namespace std;

bool graph[25][25];
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
char c[26];
int main(){
    int T, ret,j;
    scanf("%d ", &T);
    while(T--){
        N=0;
        while(true){
            ret = scanf("%[^\n]%*c", c);
            if(ret!=1)break;
            for(j=0;c[j]!='\0'; j++)graph[N][j]=c[j]=='1';
            N++;M=j;
        }
        scanf("%*c");
        int ans=0;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(graph[i][j])ans=max(ans,dfs(i,j));
        printf("%d\n", ans);
        if(T!=0)printf("\n");
    }

}