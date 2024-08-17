#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

char box[3];
int dir[][2]={{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2},
              {1,-2}, {-1,2}, {-1,-2}};
int dist[8][8];

int bfs(int r1, int c1, int r2, int c2){
    memset(dist, -1, sizeof dist);
    queue<pair<int,int>> q;
    q.emplace(r1, c1);
    dist[r1][c1] = 0;
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        if(r==r2 && c==c2) return dist[r][c];
        for(auto & i : dir){
            int nr = r+i[0], nc = c+i[1];
            if(nr<0 || nr>=8 || nc<0 || nc>=8 || dist[nr][nc]!=-1) continue;
            dist[nr][nc] = dist[r][c]+1;
            q.emplace(nr, nc);
        }
    }
    return -1;
}

int main(){
    int r1,c1,r2,c2;
    while(scanf("%s", box)!=-1){
        r1 = box[0]-'a', c1 = box[1]-'1';
        printf("To get from %s to ", box);
        scanf("%s", box);
        r2 = box[0]-'a', c2 = box[1]-'1';
        printf("%s takes %d knight moves.\n", box, bfs(r1, c1, r2, c2));
    }
}