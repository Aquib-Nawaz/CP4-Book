#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std;

int mt[200];
bool used[200], used1[200];
vector<int>adj[3][200];

bool try_kuhn(int u, int x){
    if(used[u])return false;
    used[u]=true;
    for(int v:adj[x][u]){
        if(mt[v]==-1||try_kuhn(mt[v],x)){
            mt[v]=u;
            return true;
        }
    }
    return false;
}

pair<double,double>points[200];

double distance(double x, double y, double x1, double y1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

int t[3]={5,10,20};

int main(){
    int N,M,C=0;
    while(scanf("%d", &N),N){
        for(int i=0;i<N;i++) {
            scanf("%lf %lf", &points[i].first, &points[i].second);
            for(auto & j : adj)j[i].clear();
        }
        scanf("%d", &M);
        for(int i=0;i<M;i++){
            double a,b;
            scanf("%lf %lf", &a,&b);
            for(int j=0;j<N;j++){
                double dist = distance(a, b, points[j].first, points[j].second);
                for(int k=0;k<3;k++) {
                    if (dist < 10*t[k] + 1e-10)adj[k][j].push_back(i);
                }
            }
        }
        int ans[3];
        for(int j=0;j<3;j++){
            memset(mt,-1,sizeof mt);
            memset(used1, 0, sizeof used1);
            ans[j]=0;
            for(int i=0;i<N;i++){
                for(int k:adj[j][i])if(mt[k]==-1 ){
                    used1[i]=true, mt[k]=i;
                        break;
                }
            }
            for(int i=0;i<N;i++){
                if(!used1[i]){
                    memset(used, 0, sizeof used);
                    try_kuhn(i,j);
                }
            }
            for(int i=0;i<M;i++)if(mt[i]!=-1)ans[j]++;
        }
        if(C)printf("\n");
        printf("Scenario %d\n", ++C);
        for(int k=0;k<3;k++)
            printf("In %d seconds %d robot(s) can escape\n", t[k], ans[k]);

    }
}