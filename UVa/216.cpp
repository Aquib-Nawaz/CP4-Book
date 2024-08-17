#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 8
struct mypair{
    int x,y;
} arr[MAXN];
double adj[MAXN][MAXN];
double distace(mypair a, mypair b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double dp[1<<MAXN][MAXN];
int N, par[1<<MAXN][MAXN];
double tsp(int mask, int pos) {
    if (mask == (1 << N) - 1)
        return 0;

    double &ans = dp[mask][pos];
    if (ans > 0)return ans;
    ans=-1;
    for (int i = 0; i < N; i++){
        if (!(mask & (1 << i))){
            if(ans<0 || adj[pos][i] + tsp(mask | (1 << i), i) < ans)
                ans = adj[pos][i] + tsp(mask | (1 << i), i) , par[mask][pos]=i;
        }
    }
    return ans;
}

int main(){
    int C=0;
    while (scanf("%d",&N),N){
        memset(dp,-1,sizeof dp);
        for(int i=0;i<N;i++)scanf("%d %d", &arr[i].x, &arr[i].y);
        for(int i=0;i<N;i++)
            for(int j=i+1; j<N; j++)
                adj[i][j] = adj[j][i] = distace(arr[i],arr[j])+16;
        printf("**********************************************************\nNetwork #%d\n", ++C);
        double mnv=-1;
        int mni;
        for(int i=0;i<N;i++){
            if(mnv<0 || tsp(1<<i, i) < mnv)
                mnv = tsp(1<<i, i) , mni = i;
        }
        int mask=1<<mni;
        for(int i=0,nxti;i<N-1;i++){
            nxti = par[mask][mni];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
                   arr[mni].x, arr[mni].y, arr[nxti].x, arr[nxti].y, adj[mni][nxti]+1e-10);
            mask|=1<<nxti;
            mni=nxti;
        }
        printf("Number of feet of cable required is %.2lf.\n", mnv+1e-10);
    }
}