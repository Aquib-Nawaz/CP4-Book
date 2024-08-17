#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
vector<pair<int,int>>adjL[10001];
bool taken[10001];
int main(){
    int T,n,m,l,s,u,v,w, d;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &n,&m,&l,&s);
        priority_queue<pair<int,int>>pq;
        for(int i=1;i<=n;i++) taken[i]= false, adjL[i].clear();
        for(int i=0;i<s;i++)scanf("%d", &u),  pq.emplace(0,u);
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &u, &v, &w);
            adjL[u].emplace_back(v,w+l);
            adjL[v].emplace_back(u,w+l);
        }
        int rem = n;
        ll ans = 0;
        while(!pq.empty() && rem){
            d = -pq.top().first, u = pq.top().second;
            pq.pop();
            if(taken[u])continue;
            taken[u] = true;
            ans+=d;
            rem--;
            for(auto it:adjL[u]){
                v = it.first, w = it.second;
                if(!taken[v])pq.emplace(-w,v);
            }
        }
        printf("%lld\n", ans);
    }
}
