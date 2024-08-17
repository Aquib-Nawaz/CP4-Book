#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char box[3];
int dir[][2]={{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2},
              {1,-2}, {-1,2}, {-1,-2}};
int N,M,dist[9][9];
void bfs(int r1, int c1){
    queue<pair<int,int>> q;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)dist[i][j]=-1;
    q.emplace(r1,c1);
    dist[r1][c1] = 0;
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        for(auto & i:dir){
            int nr = r+i[0], nc = c+i[1];
            if(nr<=0 || nr>N || nc<=0 || nc>M || dist[nr][nc]!=-1) continue;
            dist[nr][nc] = dist[r][c]+1;
            q.emplace(nr,nc);
        }
    }
}

int main(){
    int r1,c1,T;
    N=M=8;
    scanf("%d", &T);
    while(T--){
        scanf("%s", box);
        r1=box[0]-'a'+1, c1 = box[1]-'0';
        bfs(r1,c1);
        int mx=0,cnt=0;
        for(int i=1;i<=N;i++)for(int j=1;j<=M;j++) {
            if(mx<dist[i][j])mx=dist[i][j],cnt=1;
            else if(mx==dist[i][j])cnt++;
        }
        printf("%d", mx);
        for(int j=M;j>=1;j--)for(int i=1;i<=N;i++)if(mx==dist[i][j])printf(" %c%c", i+'a'-1, j+'0');
        printf("\n");
    }
}