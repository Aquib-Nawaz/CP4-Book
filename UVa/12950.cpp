#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dist[10000];
vector<pair<int,int>>adjL[10000];

int djikstra(int s, int t){
    priority_queue<pair<int,int>>pq;
    pq.emplace(0,s);
    dist[s]=0;
    int d;
    while(!pq.empty()){
        s=pq.top().second;
        d=-pq.top().first;
        pq.pop();
        if(s==t)return d;
        if(dist[s]!=d)continue;
        for(pair<int,int>v:adjL[s]){
            for(auto w:adjL[v.first]){
                if(dist[w.first]>d+v.second+w.second){
                    dist[w.first]=d+v.second+w.second;
                    pq.emplace(-dist[w.first],w.first);
                }
            }
        }
    }
    return -1;
}

int main(){
    int N,M;
    while(scanf("%d%d",&N,&M)!=-1){
        for(int i=0;i<N;i++)adjL[i].clear(), dist[i]=1e9;
        for(int i=0;i<M;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--,b--;
            adjL[a].emplace_back(b,c);
            adjL[b].emplace_back(a,c);
        }
        printf("%d\n",djikstra(0,N-1));
    }
}
