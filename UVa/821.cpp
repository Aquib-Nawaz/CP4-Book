#include <iostream>
#include <unordered_map>
using namespace std;

int dp[101][101];

int main(){
    int C=0,u,v;
    while(scanf("%d%d", &u,&v),u){
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                dp[i][j]=100;
            }
            dp[i][i]=0;
        }
        unordered_map<int, int>mp;
        while(u){
            if(!mp.count(u))
                mp.insert({u, mp.size()});
            if(!mp.count(v))
                mp.insert({v, mp.size()});
            dp[mp[u]][mp[v]]=1;
            scanf("%d%d", &u,&v);
        }
        int N=mp.size();
        for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
        double sum=0;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)sum+=dp[i][j];
        C++;
        sum = sum/(N*(N-1));
        printf("Case %d: average length between pages = %.3lf clicks\n", C,sum);
    }
}