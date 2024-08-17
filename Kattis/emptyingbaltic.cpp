#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//9801965688

int g[500][500], dir[][2]={{-1,0},{1,0},{0,-1},{0,1},
{-1,-1},{-1,1},{1,-1},{1,1}}, dist[500][500];
int n,m,ui,uj;
bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && g[i][j]<0;
}

int main(){
    scanf("%d%d", &n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d", g[i]+j), dist[i][j]=1e6;
    scanf("%d%d", &ui,&uj);
    priority_queue<pair<int,pair<int,int>>>pq;
    ui--,uj--;
    dist[ui][uj]=g[ui][uj];
    pq.emplace(-g[ui][uj], make_pair(ui,uj));
    while(!pq.empty()){
        int w=-pq.top().first,i = pq.top().second.first, j = pq.top().second.second;
        pq.pop();
        if (w != dist[i][j])continue;
        for (auto &k: dir) {
            int ii = i + k[0], jj = j + k[1];
            if (valid(ii, jj) && dist[ii][jj] > max(w, g[ii][jj])) {
                dist[ii][jj] = max(w, g[ii][jj]);
                pq.emplace(-dist[ii][jj], make_pair(ii, jj));
            }
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans+=max(0, -dist[i][j]);
    printf("%lld\n", ans);
}