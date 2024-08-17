#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N,M,dist[20][60],par[20][60];
char g[20][60];
int dir[8][2]={{-1,0},{0,-1},{1,0},{0,1},
    {-1,-1},{-1,1},{1,1},{1,-1}};
char c;
int main(){
    while (scanf("%d%d", &N,&M),N){
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<M;i++){
            scanf(" %c", &c);
            g[0][i]=c-'0';
            dist[0][i]=c-'0';
            pq.push({-dist[0][i],{0,i}});
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<M;j++){
                scanf(" %c", &c), g[i][j]=c-'0';
                dist[i][j]=1e6;
            }
        }
        int i,j,d;
        while (true){
            i=pq.top().second.first, j=pq.top().second.second;
            d = -pq.top().first;
            pq.pop();
            if(dist[i][j]<d)continue;
            if(i==N-1)break;
            for(int k=0;k<8;k++){
                int ii = i+dir[k][0], jj = j+dir[k][1];
                if(ii<0 || jj<0 || ii>=N || jj>=M)continue;
                if(dist[ii][jj]>d+g[ii][jj]){
                    dist[ii][jj]=d+g[ii][jj];
                    pq.push({-dist[ii][jj],{ii,jj}});
                    par[ii][jj]=k;
                }
            }
        }
        while(true){
            g[i][j]=' ';
            if(i==0)break;
            d=par[i][j];
            i-=dir[d][0], j-=dir[d][1];
        }
        for( i=0;i<N;i++){
            for(j=0;j<M;j++)printf("%c", g[i][j]<10?'0'+g[i][j]:' ');
            printf("\n");
        }
        printf("\n");
    }
}