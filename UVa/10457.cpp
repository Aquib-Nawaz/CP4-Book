#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int par[201];

int Find(int x){return par[x]==-1?x:par[x]=Find(par[x]);}
void Merge(int x, int y){x = Find(x), y= Find(y); if(x==y)return; par[x]=y;}
bool same(int x, int y){return Find(x)== Find(y);}

struct Edge{
    int u,v,w;
}arr[1000];

pair<int,int>query[5];

int main(){
    int N,M,Q,u,v,w,s,e;
    int ans[5];
    while (scanf("%d%d",&N,&M)!=-1){
        for(int i=0;i<M;i++)scanf("%d%d%d", &u,&v,&w), arr[i] = {u,v,w};
        scanf("%d%d%d", &s, &e, &Q);
        for(int i=0;i<Q;i++)scanf("%d%d", &query[i].first, &query[i].second), ans[i]=INT_MAX;
        sort(arr, arr+M, [](Edge &a, Edge &b){return a.w<b.w;});
        for(int i=0;i<M;i++){
            for(int j=1;j<=N;j++)par[j]=-1;
            for(int j=i;j<M;j++){
                Merge(arr[j].u, arr[j].v);
                bool b=true;
                int val = arr[j].w-arr[i].w;
                for(int k=0;k<Q;k++){
                    if(same(query[k].first, query[k].second))ans[k] = min(ans[k], val);
                    if(ans[k]>val)b=false;
                }
                if(b)break;
            }
        }
        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]+s+e);
    }
}