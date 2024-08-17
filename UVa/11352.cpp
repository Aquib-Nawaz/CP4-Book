#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int R,C, dist[100][100];
bool g[100][100];

int dir[][2]={{-2,1}, {-1,2}, {1,2}, {2, 1},
              {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int dir1[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0},
                 {1,1}, {1,-1}, {-1,1}, {-1,-1}};
bool inRange(int u,int v){
    return u>=0 && u<R && v>=0 && v<C ;
}

#define REP(i,n) for(int i=0;i<n;i++)

int main(){
    int T,ui,uj,vi,vj;
    scanf("%d", &T);
    char c;
    while (T--){
        scanf("%d%d", &R,&C);
        REP(i,R)REP(j,C)dist[i][j]=-1, g[i][j]= true;
        REP(i,R)REP(j,C){
            scanf(" %c", &c);
            if(c=='.')continue;
            else if(c=='Z'){
                g[i][j]= false;
                for(auto &d:dir)if(inRange(i+d[0],j+d[1]))g[i+d[0]][j+d[1]]=false;
            }
            else if(c=='A')ui=i,uj=j;
            else vi=i,vj=j;
        }
        queue<pair<int,int>>q;
        q.emplace(ui,uj);
        dist[ui][uj]=0;
        while(!q.empty()){
            ui=q.front().first, uj=q.front().second;
            q.pop();
            for(auto &d:dir1)if(inRange(ui+d[0],uj+d[1]) && dist[ui+d[0]][uj+d[1]]==-1){
                dist[ui+d[0]][uj+d[1]]=dist[ui][uj]+1;
                if(g[ui+d[0]][uj+d[1]])
                    q.emplace(ui+d[0],uj+d[1]);
            }
        }
        int ans=dist[vi][vj];

        if(ans==-1)printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n", ans);
    }
}