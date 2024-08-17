#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 2048

int dp[MAXN][MAXN];

void rotate(int x, int y, int &tx, int &ty, int dy){
    tx = x-y+dy;
    ty=x+y;
}
int dx,dy,n,q,tx,ty,x,y,C=0,m;

void solve(){
    int ans=0,_x=1,_y=1,cnt,lx,ly,rx,ry;
    for(y=1;y<=dy;y++)
        for(x=1;x<=dx;x++){
            rotate(x,y,tx,ty,dy);
            //Number of coffe shop in square whose centre is tx ty with half size m
            lx = max(tx-m-1,0),ly = max(ty-m-1,0);
            rx = min(tx+m, dy+dx),ry = min(ty+m, dx+dy);
            cnt = dp[rx][ry]-dp[rx][ly]-dp[lx][ry]+dp[lx][ly];
            if(ans<cnt)_x=x,_y=y,ans=cnt;
        }
    printf("%d (%d,%d)\n",ans,_x,_y);
}

int main(){
    while (scanf("%d %d %d %d",&dx,&dy,&n,&q),dx||dy||n||q){
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            rotate(x,y,tx,ty,dy);
            dp[tx][ty]++;
        }
        for(int i=1;i<=dx+dy;i++)
            for(int j=1,s=0;j<=dx+dy;j++){
                s+=dp[i][j];
                dp[i][j] = s+dp[i-1][j];
            }
        printf("Case %d:\n",++C);
        while(q--){
            scanf("%d",&m);
            solve();
        }
    }

}