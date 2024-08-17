#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
typedef long double ld;
ld dist[100][100], dp[100][100];

pair<int,int>points[100];

ld _sqdist(int i, int j){
    int dx=points[j].first-points[i].first, dy=points[j].second-points[i].second;
    return sqrt(dx*dx + dy*dy);
}

int main(){
    int n,m;
    while(scanf("%d", &n),n){
        for(int i=0;i<n;i++)scanf("%d %d", &points[i].first, &points[i].second);
        for(int i=0;i<n;i++){for(int j=0;j<n;j++)dist[i][j]= _sqdist(i,j), dp[i][j]=1e9; dp[i][i]=0;}
        scanf("%d", &m);

        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d", &u,&v);
            dp[u][v]=dp[v][u]=dist[u][v];
        }

        for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)dp[j][k]=min(dp[j][k], dp[j][i]+dp[i][k]);
        ld total=0;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)total+=dp[i][j];
        ld reduction=total;
        int ansi, ansj;
        for(int u=0;u<n;u++){
            for(int v=u+1;v<n;v++){
                if(abs(dist[u][v]-dp[u][v])<1e-9)continue;
                ld cur=0;
                for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
                    cur+=min(dp[i][v]+dist[u][v]+dp[u][j]
                            ,min(dp[i][j], dp[i][u]+dist[u][v]+dp[v][j]));
                }
                if(cur+1e-9<reduction){
                    reduction=cur;
                    ansi=u, ansj=v;
                }
            }
        }
        if(abs(reduction-total)<1e-9)printf("no addition reduces %Lf\n", total);
        else printf("adding %d %d reduces %Lf to %Lf\n", ansi, ansj, total, reduction);
    }
}