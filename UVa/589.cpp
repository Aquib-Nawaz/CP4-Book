#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 20
char g[MAX][MAX];
int op[4] = {1,0,3,2};
int N,M,C=0,mi,mj,ui,uj, vi,vj, bdist[MAX][MAX], bpar[MAX][MAX];
pair<int,int> dist[MAX][MAX][4];
char cdir[4] = {'N', 'S', 'E', 'W'};
int dir[][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

struct state{
    int i,j,d;
    state(int _i, int _j, int _d):i(_i),j(_j),d(_d){}
    state(){}
    bool operator<(const state& rhs) const{
        return i<rhs.i;
    }
};
struct parstate{
    int d;
    string path;
};
struct parstate par[MAX][MAX][4];

bool inRange(int x, int y){
    return x>=0 && y>=0 && x<N && y<M && g[x][y]!='#' && (x!=ui || y!=uj);
}
string path;
int bfs(int si, int sj, int ti, int tj){
    path.clear();
    if(!inRange(ti,tj))return -1;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)bdist[i][j]=-1;
    queue<pair<int,int>>q;
    bdist[si][sj]=0;
    q.emplace(si,sj);
    bpar[si][sj]=-1;
    while (!q.empty()){
        si=q.front().first, sj=q.front().second;
        q.pop();
        if(si==ti && sj==tj)break;
        for(int i=0;i<4;i++){
            int ni=si+dir[i][0], nj=sj+dir[i][1];
            if(inRange(ni,nj) && bdist[ni][nj]==-1){
                bdist[ni][nj]=bdist[si][sj]+1;
                q.emplace(ni,nj);
                bpar[ni][nj]=i;
            }
        }
    }
    int ans=bdist[ti][tj],d;
    if(ans<=0)return ans;
    while(bpar[ti][tj]!=-1){
        d = op[bpar[ti][tj]];
        path+=cdir[bpar[ti][tj]]-'A'+'a';
        ti=ti+dir[d][0], tj=tj+dir[d][1];
    }
//    reverse(path.begin(), path.end());
    return ans;
}
priority_queue<pair<pair<int,int>, struct state>>pq;
int cnt=0;
void process(state s){
    cnt++;
    for(int i=0;i<4;i+=2){
        if(inRange(ui+dir[i][0],uj+dir[i][1]) && inRange(ui+dir[i+1][0],uj+dir[i+1][1]) ||
        ui==vi && uj==vj){
            for(int j=0;j<2;j++){
                int d = bfs(mi,mj,ui+dir[i+j][0],uj+dir[i+j][1]);
                if(d!=-1){
                    if(s.i==-1){
                        pq.push({{0,-d},{ui,uj,i+j}});
                        dist[ui][uj][i+j]={0,d};
                        par[ui][uj][i+j]={-1, path};
                    }
                    else {
                        auto temp = dist[s.i][s.j][s.d];
                        temp.first++, temp.second+=d;
                        if(dist[ui][uj][i+j]>temp){
                            pq.push({{-temp.first,-temp.second},{ui,uj,i+j}});
                            dist[ui][uj][i+j]=temp;
                            par[ui][uj][i+j]={s.d, path};
                        }
                    }
                }
            }
        }
    }
}
int main(){
    char c;
    while (scanf("%d%d", &N,&M), N){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf(" %c", &c);
                g[i][j]='.';
                if(c=='S')mi=i,mj=j;
                else if(c=='B')ui=i,uj=j;
                else if(c=='T')vi=i,vj=j;
                else if(c=='#')g[i][j]=c;
            }
        }
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)for(int s=0;s<4;s++)dist[i][j][s]={1e6,1e6};
        while (!pq.empty())pq.pop();
        process({-1,-1,-1});
        pair<int,int>ans={-1,-1};
        state u;
        while(!pq.empty()){
            pair<int,int>d=pq.top().first;
            u=pq.top().second;
            d.first = -d.first, d.second=-d.second;
            pq.pop();
            if(u.i==vi && u.j==vj){
                ans = d;
                break;
            }
            if(d!=dist[u.i][u.j][u.d])continue;
            ui = u.i+dir[op[u.d]][0], uj = u.j+dir[op[u.d]][1];
            mi = u.i, mj=u.j;
            process(u);
        }
        printf("Maze #%d\n", ++C);
        if(ans.first==-1)printf("Impossible.\n");
        else{
            path.clear();
            int d;
            while(true){
                path+=par[u.i][u.j][u.d].path;
                d = par[u.i][u.j][u.d].d;
                if(d==-1)break;
                path+=cdir[op[d]], u.d=d;
                u.i+=dir[d][0], u.j+=dir[d][1];
            }
            reverse(path.begin(), path.end());
            printf("%s\n", path.c_str());
        }
        printf("\n");
    }
}