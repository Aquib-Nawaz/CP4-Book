#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

typedef long double ld;
vector<pair<int, ld>>adjL[50];

struct {
    int x,y,m;
}node[50];

ld distance(int x1, int y1, int x2, int y2){
    return sqrt((ld)(x1-x2)*(x1-x2)+(ld)(y1-y2)*(y1-y2));
}
bool taken[50];
ld dist[50];

int main(){
    int N, u, v,C=0;
    while(scanf("%d", &N), N){
        for(int i=0;i<N;i++){
            taken[i]= false;
            dist[i]= 1e15;
            scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].m);
            u=node[i].x, v=node[i].y;
            for(int j=0;j<i;j++){
                ld t = distance(u, v, node[j].x, node[j].y);
                adjL[i].emplace_back(j, t);
                adjL[j].emplace_back(i, t);
            }
        }
        ld pop=0, pop_t=0;
        priority_queue<pair<ld,int>>pq;
        pq.emplace(0,0);
        dist[0]=0;
        int rem=N;
        while(!pq.empty()&&rem){
            u=pq.top().second;
            pq.pop();
            if(taken[u])continue;
            taken[u]= true;
            pop+=node[u].m;
            pop_t+=dist[u]*node[u].m;
            rem--;
            for(auto it:adjL[u]){
                if(!taken[it.first] && dist[it.first] > max(it.second , dist[u]) )dist[it.first]= max(it.second, dist[u]),
                pq.emplace(-dist[it.first], it.first);
            }
        }
        printf("Island Group: %d Average %.2Lf\n\n",++C, pop_t/pop);
        for(int i=0;i<N;i++)adjL[i].clear();
    }
}