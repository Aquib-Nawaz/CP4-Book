#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int>interval[20];
int dp[20][11];
int main(){
    int T,s,e,m;
    scanf("%d", &T);
    while(T--) {
        m=0;
        while(scanf("%d %d", &s, &e) , s||e) {
            interval[m++] = make_pair(s, e);
        }
        sort(interval, interval+m, [](pair<int,int>a, pair<int,int>b){return a.second<b.second;});
        for(int i=0;i<=10;i++)dp[0][i]=i>=interval[0].second;
        for(int i=0;i<m;i++)dp[i][0]=0;
        for(int i=1;i<m;i++){
            for(int j=1;j<=10;j++){
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                if(j==interval[i].second)
                    dp[i][j]=max(dp[i][j], dp[i-1][interval[i].first]+1);
            }
        }
        printf("%d\n", dp[m-1][10]);
    }
}