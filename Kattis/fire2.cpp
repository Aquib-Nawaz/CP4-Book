#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int g[1000][1000],dir[][2]={{-1,0},{1,0},{0,-1},{0,1}},R,C;
char c;

int bfs(queue<pair<int,int>>&q, int t=0){
    while(!q.empty()){
        int i=q.front().first, j=q.front().second;
        q.pop();
        int d=g[i][j];
        if(t && (i==0||j==0||i==R-1||j==C-1)) return d+1;
        for (auto & k : dir){
            int ii=i+k[0], jj=j+k[1];
            if(ii<0 || ii>=R || jj<0 || jj>=C || g[ii][jj]<=d+1){
                continue;
            }
            g[ii][jj]=d+1;
            q.emplace(ii,jj);
        }
    }
    return -1;
}

int main(){
    int T,ui,uj;
    scanf("%d", &T);
    while (T--){
        queue<pair<int,int>>q;
        scanf("%d%d", &C,&R);
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                scanf(" %c", &c);
                if(c=='.'){
                    g[i][j]=1e9;
                    continue;
                }
                g[i][j]=0;
                if(c=='*'){
                    q.push({i,j});
                }
                else if(c=='@')ui=i,uj=j;
            }
        }
        bfs(q);
        q.emplace(ui,uj);
        int ans=bfs(q,1);
        if(ans==-1)printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }
}